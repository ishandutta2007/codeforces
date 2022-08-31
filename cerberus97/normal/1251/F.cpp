/* cerberus97 - Hanit Banga */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

constexpr int mod = 998244353;
constexpr int gen = 973800541;
// gen should be 5^((p - 1) / fft_wrapper_size)

template<int P>
struct field_t {
    ll v;
    field_t(ll x) : v(x % P) {}
    field_t() : v(0) {}
    field_t & operator+=(const field_t &other) {
        v += other.v;
        if (v >= P) {
            v -= P;
        }
        return (*this);
    }
    field_t operator+(const field_t &other) {
        field_t cpy = *this;
        cpy += other;
        return cpy;
    }
    field_t & operator-=(const field_t &other) {
        v += P - other.v;
        if (v >= P) {
            v -= P;
        }
        return (*this);
    }
    field_t operator-(const field_t &other) {
        field_t cpy = *this;
        cpy -= other;
        return cpy;
    }
    field_t operator*=(const field_t &other) {
        v *= other.v;
        v %= P;
        return (*this);
    }
    field_t operator*(const field_t &other) {
        field_t cpy = *this;
        cpy *= other;
        return cpy;
    }
    field_t modexp(ll b) {
        field_t ans = 1, res = *this;
        while (b) {
            if (b % 2) {
                ans *= res;
            }
            res *= res;
            b /= 2;
        }
        return ans;
    }
};

template<typename fpt, int gen>
struct fft_wrap {
	vector<fpt> roots; //stores the N-th roots of unity.
	int N;
	fft_wrap(int _N) : roots(_N), N(_N)	{
        roots[0] = 1;
		for (int i = 1; i < N; ++i) {
            roots[i] = roots[i - 1] * gen;
            if (i != N - 1) {
                assert(roots[i].v != 1);
            }
		}
	}
	void fft(fpt *in, fpt *out, int size, int dir) {
		bit_reverse(in, out, size);
		for (int s = 0; (1 << s) < size; ++s) {
			int s_ = s + 1;
			for (int k = 0; k < size; k += (1 << s_)) {
				for (int j = 0; j < (1 << s); ++j) {
					int id = (N + dir * (N >> s_) * j) & (N - 1);
					fpt w = roots[id];
					fpt t = w * out[k + j + (1 << s)];
					fpt u = out[k + j];
					out[k + j] = u + t;
					out[k + j + (1 << s)] = u - t;
				}
			}
		}
	}
	void bit_reverse(fpt *in, fpt *out, int size) {
		for (int i = 0; i < size; ++i) {
			int rev = 0, i_copy = i;
			for (int j = 0; (1 << j) < size; ++j) {
				rev = (rev << 1) + (i_copy & 1);
				i_copy >>= 1;
			}
			out[rev] = in[i];
		}
	}
};

using fpt = field_t<mod>;
fft_wrap<fpt, gen> fft_wrapper(1 << 20);

vector<fpt> polymul(vector<fpt> P1, vector<fpt> P2) {
    int fsize = P1.size() + P2.size() - 1;
    int N = max(P1.size(), P2.size());
    while(N & (N - 1)) {
        ++N;
    }
    N *= 2;
    P1.resize(N); P2.resize(N);
    vector<fpt> temp(N);
    fft_wrapper.fft(&P1[0], &temp[0], N, 1);
    fft_wrapper.fft(&P2[0], &P1[0], N, 1);
    for (int i = 0; i < N; ++i) {
        P1[i] *= temp[i];
    }
    fft_wrapper.fft(&P1[0], &temp[0], N, -1);
    field_t<mod> inv(N);
    inv = inv.modexp(mod - 2);
    for (int i = 0; i < N; ++i) {
        temp[i] *= inv;
    }
    temp.resize(fsize);
    return temp;
}

const int N = 3e5 + 10, L = N, Q = 2 * (N + L);

int w[N], r[N];
fpt p2[N], fact[N], finv[N];
fpt ans[Q];

fpt choose(int n, int k);

int main() {
	fast_cin();
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
	}
	for (int i = 1; i <= k; ++i) {
		cin >> r[i];
	}
	sort(w + 1, w + 1 + n);
	sort(r + 1, r + 1 + k);
	p2[0] = fact[0] = finv[0] = 1;
	for (int i = 1; i <= n; ++i) {
		p2[i] = p2[i - 1] * 2;
		fact[i] = fact[i - 1] * i;
		finv[i] = fact[i].modexp(mod - 2);
	}
	int a = 0, b = 0, p = 1;
	for (int j = 1; j <= k; ++j) {
		int l = r[j];
		while (p <= n and w[p] < l) {
			int cnt = 0, cur = w[p];
			while (w[p] == cur) {
				++cnt;
				++p;
			}
			if (cnt == 1) {
				++a;
			} else {
				++b;
			}
		}
		vector<fpt> P1(a + 1, 0);
		vector<fpt> P2(2 * b + 1, 0);
		for (int i = 0; i <= a; ++i) {
			P1[i] = choose(a, i) * p2[i];
		}
		for (int i = 0; i <= 2 * b; ++i) {
			P2[i] = choose(2 * b, i);
		}
		vector<fpt> P = polymul(P1, P2);
		for (int i = 0; i <= a + 2 * b; ++i) {
			ans[2 * (i + l + 1)] += P[i];
		}
	}
	int q; cin >> q;
	while (q--) {
		int x; cin >> x;
		cout << ans[x].v << '\n';
	}
}

fpt choose(int n, int k) {
	return fact[n] * finv[k] * finv[n - k];
}