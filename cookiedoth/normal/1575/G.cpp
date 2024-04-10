/*

Code for problem G by cookiedoth
Generated 02 Oct 2021 at 03.17 PM


  !
 
                                    
                          
                  




















z_z
>_<
\_()_/

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <complex>
#include <cassert>
#include <random>
#include <cstring>
#include <numeric>
#include <random>
#include <utility>
#include <tuple>
#include <chrono>
#define ll long long
#define ld long double
#define null NULL
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define debug(a) cerr << #a << " = " << a << endl
#define forn(i, n) for (int i = 0; i < n; ++i)
#define length(a) (int)a.size()

using namespace std;

template<class T> int chkmax(T &a, T b) {
	if (b > a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T> int chkmin(T &a, T b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

template<class iterator> void output(iterator begin, iterator end, ostream& out = cerr) {
	while (begin != end) {
		out << (*begin) << " ";
		begin++;
	}
	out << endl;
}

template<class T> void output(T x, ostream& out = cerr) {
	output(x.begin(), x.end(), out);
}

void fast_io() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

const int MAX_N = 1e5 + 228;
const int C = 1e5 + 228;
const int K = 300;
int n, a[MAX_N];

int gcd(int a, int b) {
    if (!a || !b)
        return a | b;
    unsigned shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    do {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}

const int MAX_P = 6;

int pd[C + 1][MAX_P], pd_cnt[C + 1];
int ief[C + 1][1 << MAX_P], pptr[C + 1], mptr[C + 1];

void prepare_mobius() {
	for (int p = 2; p <= C; ++p) {
		if (pd_cnt[p] == 0) {
			for (int x = p; x <= C; x += p) {
				pd[x][pd_cnt[x]++] = p;
			}
		}
	}
	fill(mptr + 1, mptr + C, (1 << MAX_P) - 1);
	for (int i = 1; i <= C; ++i) {
		for (int sub = 1; sub < (1 << pd_cnt[i]); ++sub) {
			int prod = i;
			for (int j = 0; j < pd_cnt[i]; ++j) {
				if ((sub >> j) & 1) {
					prod /= pd[i][j];
				}
			}
			if (__builtin_popcount(sub) % 2 == 0) {
				ief[i][pptr[i]++] = prod;
			} else {
				ief[i][mptr[i]--] = prod;
			}
		}
	}
	// cerr << "prepare_mobius\n";
	// for (int i = 4; i <= 4; ++i) {
	// 	cerr << "i = " << i << '\n';
	// 	cerr << "prime divisors: " << pd_cnt[i] << '\n';
	// 	cerr << "plus:";
	// 	for (int j = 0; j < pptr[i]; ++j) {
	// 		cerr << ' ' << ief[i][j];
	// 	}
	// 	cerr << '\n';
	// 	cerr << "minus:";
	// 	for (int j = mptr[i] + 1; j < (1 << MAX_P); ++j) {
	// 		cerr << ' ' << ief[i][j];
	// 	}
	// 	cerr << '\n';
	// }
}

void read() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
}

ll cnt[C + 1], f[C + 1], res[MAX_N], cache[MAX_N];

void mobius_transform(ll* arr, int len) {
	copy(arr + 1, arr + len + 1, cache + 1);
	for (int i = len; i >= 1; --i) {
		for (int j = 0; j < pptr[i]; ++j) {
			arr[ief[i][j]] += cache[i];
			// if (a[i] != 0) {
			// 	cerr << "add " << ief[i][j] << ' ' << i << '\n';
			// }
		}
		for (int j = mptr[i] + 1; j < (1 << MAX_P); ++j) {
			arr[ief[i][j]] -= cache[i];
			// if (a[i] != 0) {
			// 	cerr << "subtract " << ief[i][j] << ' ' << i << '\n';
			// }
		}
	}
}

void compute_small(int step) {
	// cerr << "compute_small " << step << '\n';
	fill(f, f + C + 1, 0);
	fill(cnt, cnt + C + 1, 0);
	for (int i = step; i <= n; i += step) {
		cnt[a[i]]++;
	}
	for (int i = 1; i <= C; ++i) {
		for (int j = i; j <= C; j += i) {
			f[i] += cnt[j];
		}
	}
	for (int i = 1; i <= C; ++i) {
		f[i] = f[i] * (f[i] - 1) / 2;
	}
	// output(f + 1, f + 7);
	mobius_transform(f, C);
	// output(f + 1, f + 7);
	for (int i = 1; i <= C; ++i) {
		res[step] += f[i] * (ll)i;
	}
	// cerr << "done\n";
	// exit(0);
}

void compute_large(int step) {
	for (int i = step; i <= n; i += step) {
		for (int j = i + step; j <= n; j += step) {
			res[step] += gcd(a[i], a[j]);
		}
	}
}

const ll MOD = 1e9 + 7;
ll ans;

void solve() {
	for (int i = 1; i <= n; ++i) {
		if (i <= K) {
			compute_small(i);
		} else {
			compute_large(i);
		}
	}
	for (int i = 1; i <= n; ++i) {
		res[i] = res[i] % MOD;
	}
	mobius_transform(res, n);
	for (int i = 1; i <= n; ++i) {
		res[i] = (res[i] % MOD + MOD) % MOD;
	}
	for (int i = 1; i <= n; ++i) {
		ans = (ans + res[i] * (ll)i) % MOD;
	}
	ans = (ans + ans) % MOD;
	for (int i = 1; i <= n; ++i) {
		ans = (ans + (ll)a[i] * (ll)i) % MOD;
	}
	cout << ans << '\n';
}

signed main() {
	fast_io();
	read();
	prepare_mobius();
	solve();
}