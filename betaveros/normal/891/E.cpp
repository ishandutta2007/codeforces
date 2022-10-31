// Problem is equivalent to: let A = product a_i, then k times subtract 1 from
// a random a_i, then let B = product a_i; return expected A - B.  We just need
// B.

// Inverse problem: You have a bunch of a_i, k times add 1 to a random a_i,
// then find expected product. Combinatorially (nonsensical because a_i will be
// negative, but correct as polynomials), you have a_i and add k random balls,
// count the expected number of sets of n balls that are all in distinct bins.
// Every *permutation* of s balls, 0 <= s <= n union and any set of n - s balls
// in n - s specific bins has 1 out of n^s ways to form such a set. That's
// There are P(k, s) * sum (product of every (n - s) elements of a_i) ways to pick sets.
//
// sum(0 <= s <= n)
//   P(k, s) * sum (product of every (n - s) elements of a_i) / n^s

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

	explicit Mod(long long v): value(mod(v)) {}

	Mod<MOD> operator+(const Mod<MOD>& other) const { return Mod<MOD>(value + other.value); }
	Mod<MOD> operator-(const Mod<MOD>& other) const { return Mod<MOD>(value - other.value); }
	Mod<MOD> operator*(const Mod<MOD>& other) const { return Mod<MOD>(value * other.value); }
	Mod<MOD> operator/(const Mod<MOD>& other) const { return Mod<MOD>(value * minv(other.value)); }

	Mod<MOD> operator-() const { return Mod<MOD>(-value); }

	Mod<MOD>& operator+=(const Mod<MOD>& other) { value = mod(value + other.value); }
	Mod<MOD>& operator-=(const Mod<MOD>& other) { value = mod(value - other.value); }
	Mod<MOD>& operator*=(const Mod<MOD>& other) { value = mod(value * other.value); }
	Mod<MOD>& operator/=(const Mod<MOD>& other) { value = mod(value * minv(other.value)); }

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

	long long nice() const {
		return value > MOD / 2 ? value - MOD : value;
	}
};

using M = Mod<1000000007>;

int n, k;
vector<int> nums;

// Problem is equivalent to: let A = product a_i, then k times subtract 1 from
// a random a_i, then let B = product a_i; return expected A - B.  We just need
// B.

// Inverse problem: You have a bunch of a_i, k times add 1 to a random a_i,
// then find expected product. Combinatorially (nonsensical because a_i will be
// negative, but correct as polynomials), you have a_i and add k random balls,
// count the expected number of sets of n balls that are all in distinct bins.
// Every *permutation* of s balls, 0 <= s <= n union and any set of n - s balls
// in n - s specific bins has 1 out of n^s ways to form such a set. That's
// There are P(k, s) * sum (product of every (n - s) elements of a_i) ways to pick sets.
//
// sum(0 <= s <= n)
//   P(k, s) * sum (product of every (n - s) elements of a_i) / n^s

vector<M> b;
vector<M> symSums;
vector<M> symSumsOverall;


void makeSymSums() {
	for (int x : nums) {
		symSums.push_back(M(1)); // all products of s things from the
		// corresponding inclusive prefix
	}
	for (int s = 0; s <= n; s++) {
		symSumsOverall.push_back(symSums.back());

		vector<M> nextSymSums;
		for (size_t i = 0; i < symSums.size(); i++) {
			// Choose (s+1) things from the (i+1) terms up to index i
			M next(0);
			// either it's a sym sum already found
			if (!nextSymSums.empty()) {
				next += nextSymSums.back();
			}
			// or it's this times something old
			if (i == 0) {
				if (s == 0) {
					next += b[0];
				}
			} else {
				next += b[i] * symSums[i - 1];
			}
			// fprintf(stderr, "- nextSymSum: %lld\n", next.nice());
			nextSymSums.push_back(next);
		}
		symSums = nextSymSums;
	}
}

M solve() {
	M bigA(1);
	for (int x : nums) {
		bigA *= M(x);
		b.push_back(M(-x));
	}
	// fprintf(stderr, "bigA: %lld\n", bigA.value);

	makeSymSums();

	M subanswer(0);
	M pks(1); // k*(k-1)*...
	M denominator(1);
	for (int s = 0; s <= n; s++) {
		M addend = pks * symSumsOverall[n - s] / denominator;
		// fprintf(stderr, "- adding: %lld\n", addend.nice());
		subanswer += addend;

		// iterate, preparing s to go to s + 1
		pks *= M(k - s);
		denominator *= M(n);
	}

	if (n % 2 == 1) subanswer = -subanswer;

	// fprintf(stderr, "bigA(%lld) - subanswer(%lld)\n", bigA.nice(), subanswer.nice());
	M wat = bigA - subanswer;
	// fprintf(stderr, "bigA(%lld) - subanswer(%lld): %lld\n", bigA.nice(), subanswer.nice(), wat.nice());

	return bigA - subanswer;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		nums.push_back(x);
	}
	printf("%lld\n", solve().value);
}