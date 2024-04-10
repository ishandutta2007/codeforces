#include <cassert>
#include <stdexcept>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

template<long long MOD> struct Mod {
	long long value;

	static long long mod(long long x) {
		long long r = x % MOD;
		return r < 0 ? r + MOD : r;
	}

	static long long minv(long long x) {
		return x == 1 ? 1 : mod(minv(MOD % x) * (MOD - MOD/x));
	}
	static long long gcd(long long x, long long y) {
		return y == 0 ? x : gcd(y, x % y);
	}

	Mod(long long v): value(mod(v)) {}

	Mod operator+(const Mod& other) const { return mod(value + other.value); }
	Mod operator-(const Mod& other) const { return mod(value - other.value); }
	Mod operator*(const Mod& other) const { return mod(value * other.value); }
	Mod operator/(const Mod& other) const { return mod(value * minv(other.value)); }

	Mod operator-() const { return mod(-value); }

	Mod& operator+=(const Mod& other) { value = mod(value + other.value); }
	Mod& operator-=(const Mod& other) { value = mod(value - other.value); }
	Mod& operator*=(const Mod& other) { value = mod(value * other.value); }
	Mod& operator/=(const Mod& other) { value = mod(value * minv(other.value)); }

	static Mod binom(long long x, long long y) {
		// y should be small
		assert(x >= 0);
		if (y < 0 || y > x) return 0;
		Mod ret = 1;
		for (long long i = 0; i < y; i++) {
			ret *= (x - i);
			ret /= (i + 1);
		}
		return ret;
	}
};

using M = Mod<998244353>;

struct Polynomial {
	vector<M> coefs; // P(x) = sum coefs[i] (i choose x)

	static Polynomial constant(M x) {
		vector<M> coefs{x};
		return Polynomial { coefs };
	}

	M evaluate(long long x) {
		M ret = 0;
		long long degree = 0;
		for (M& coef : coefs) {
			ret += coef * M::binom(x, degree);
			degree++;
		}
		return ret;
	}

	void add_constant(M x) {
		add_coef(0, x);
	}

	void add_coef(size_t degree, M x) {
		while (coefs.size() <= degree) coefs.push_back(0);

		coefs[degree] += x;
	}

	Polynomial sum_poly(long long upper) const {
		// P such that P(x) = sum(this(x) .. this(upper))
		// inclusive because lol
		Polynomial ret{};
		size_t degree = 0;
		for (const M& coef : coefs) {
			// in general (j, c) + .. + (k, c) = (k+1, c+1) - (j, c+1)
			ret.add_coef(degree + 1, -coef);
			ret.add_coef(0, coef * M::binom(upper + 1, degree + 1));
			degree += 1;
		}
		return ret;
	}
};

struct Piece {
	long long breakpoint;
	Polynomial polynomial;

	M at_breakpoint() {
		return polynomial.evaluate(breakpoint);
	}
};
struct PiecewisePolynomial {
	vector<Piece> pieces; // decreasing order because it's always like this

	// Return P such that, for x not much larger than lo, P(x) = sum(this(x) ..
	// this(hi)).
	Polynomial suffix_sum_poly(long long lo, long long hi) const {
		M acc = 0;
		long long upper = hi;
		for (const Piece& piece : pieces) {
			if (piece.breakpoint > hi) {
				continue;
			}
			if (piece.breakpoint > lo) {
				// accumulate
				acc += piece.polynomial.sum_poly(upper).evaluate(piece.breakpoint);
				upper = piece.breakpoint - 1;
			} else {
				// done
				Polynomial p = piece.polynomial.sum_poly(upper);
				p.add_constant(acc);
				return p;
			}
		}

		// all things should be padded down to 0 so no
		throw runtime_error("ssp reached bot");
	}
};

int n;

PiecewisePolynomial derive(const PiecewisePolynomial& p, long long lo, long long hi) {
	vector<Piece> pieces;
	pieces.push_back(Piece {
		.breakpoint = hi + 1,
		.polynomial = Polynomial {}
	});
	for (auto& piece : p.pieces) {
		if (piece.breakpoint > hi) continue;

		long long bp = piece.breakpoint;
		if (bp < lo) bp = lo;
		pieces.push_back(Piece {
			.breakpoint = bp,
			.polynomial = p.suffix_sum_poly(piece.breakpoint, hi)
		});
		if (bp == lo) break;
	}

	auto& back = pieces.back();
	pieces.push_back(Piece {
		.breakpoint = 0,
		.polynomial = Polynomial::constant(back.at_breakpoint())
	});

	return PiecewisePolynomial { pieces };
}

vector<pair<long long, long long>> ranges;

int main() {
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int lo, hi;
		scanf("%d%d", &lo, &hi);
		ranges.emplace_back(lo, hi);
	}

	PiecewisePolynomial p = PiecewisePolynomial {
		.pieces = {
			{
				.breakpoint = 0,
				.polynomial = Polynomial::constant(1)
			}
		}
	};
	for (auto& range : ranges) {
		p = derive(p, range.first, range.second);

		/*
		printf("Deriving result:\n");
		for (Piece& piece : p.pieces) {
			printf("  Piece bp = %lld with coefs ", piece.breakpoint);
			for (M& coef : piece.polynomial.coefs) {
				long long v = coef.value;
				if (v > 990000000) {
					v -= 998244353;
				}
				printf("%lld,", v);
			}

			printf(" which has values %lld,%lld,%lld,%lld",
					piece.polynomial.evaluate(0).value,
					piece.polynomial.evaluate(1).value,
					piece.polynomial.evaluate(2).value,
					piece.polynomial.evaluate(3).value);
			puts(";");
		}
		*/
	}

	M res = p.pieces.back().at_breakpoint();

	// printf("The raw count is %lld\n", res.value);
	for (auto& range : ranges) {
		res /= 1 + range.second - range.first;
	}
	printf("%lld\n", res.value);
}
// 457137