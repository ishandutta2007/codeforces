// @betaveros :: vim:set fdm=marker syntax=cppc:
// #define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
// #include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define fori0(i,e) for(int i = 0; i < ((int)e); i++)
#define fori1(i,e) for(int i = 1; i <= ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
// const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}


// dp[i][j][k] = if it's possible to use j instances of the numbers up to and including a[i], each at least once, to make a total of k where k >= j(j-1)/2; if so, how many instances of a[i] to use.
// i is at most 30
// Dumb bound: the numbers sum to at most j*30 so j(j-1)/2 <= k <= j*30 so j <= 60ish, k < 60ish*30.

const int N = 33;
int dp[35][70][3000];
int n;
int a[N];

int solve() {
	fori (j, 1, 70) {
		int i = 0;
		int k = j*a[0];
		if (k >= j*(j-1)/2) {
			dp[0][j][j*a[0]] = j;

			if (i == n-1 && k == j*(j-1)/2 && dp[i][j][k] > 0) {
				return j;
			}
		}
	}

	fori (i, 1, n) {
		fori (j, 1, 70) {
			fori (k, j*(j-1)/2, 3000) {
				// 2 ways to get here: use dp[i-1][j-1][k-a[i]] or dp[i][j-1][k-a[i]].
				int prev = k - a[i];
				if (prev >= 0) {
					if (dp[i-1][j-1][prev] > 0) {
						dp[i][j][k] = 1;
					} else if (dp[i][j-1][prev] > 0) {
						dp[i][j][k] = dp[i][j-1][prev] + 1;
					}
				}

				if (i == n-1 && k == j*(j-1)/2 && dp[i][j][k] > 0) {
					return j;
				}
			}
		}
	}
	return 0;
}

vector<int> exemplifyDegrees(int j) {
	int i = n - 1;
	int rest = j*(j-1)/2;
	vector<int> ret;
	while (true) {
		int curCount = dp[i][j][rest];
		assert(curCount > 0);
		repeat (curCount) {
			ret.push_back(a[i]);
			rest -= a[i];
			j -= 1;
		}
		assert(rest >= 0);

		if (i == 0) {
			assert(rest == 0);
			return ret;
		}
		i--;
	}
}

int winsSoFar[80];
int lossesSoFar[80];
char output[80][80];
int main() {
	scan_d(n);
	fori (i, 0, n) scan_d(a[i]);
	sort(a, a + n);

	int j = solve();
	if (j == 0) {
		puts("=(");
	} else {
		vector<int> degs = exemplifyDegrees(j);
		sort(allof(degs));
		int s = degs.size();
		printf("%d\n", s);

		// dumpBetween(allof(degs));

		fori (i, 0, s) {
			output[i][i] = '0';
		}

		fori (i, 0, s) {
			vector<int> later;
			fori (j, i + 1, s) {
				later.push_back(j);
			}
			// who needs losses the most?
			sort(allof(later), [&](int j1, int j2) { return (s - 1 - degs[j1] - lossesSoFar[j1]) > (s - 1 - degs[j2] - lossesSoFar[j2]); });

			int neededWins = degs[i] - winsSoFar[i];
			for (int jj = 0; jj < later.size(); jj++) {
				int j = later[jj];
				if (jj < neededWins) {
					// i wins
					assert(lossesSoFar[j] < s - 1 - degs[j]);
					output[i][j] = '1';
					output[j][i] = '0';
					winsSoFar[i]++;
					lossesSoFar[j]++;
				} else {
					assert(winsSoFar[j] < degs[j]);
					output[i][j] = '0';
					output[j][i] = '1';
					winsSoFar[j]++;
					lossesSoFar[i]++;
				}
			}

			/*
			for (int j = s - 1; j > i; j--) {
				if (lossesSoFar[i] < (s - 1 - degs[i]) && winsSoFar[j] < degs[j]) {
					output[i][j] = '0';
					output[j][i] = '1';
					winsSoFar[j]++;
					lossesSoFar[i]++;
				} else {
					assert(winsSoFar[i] < degs[i]);
					assert(lossesSoFar[j] < (s - 1 - degs[j]));
					output[i][j] = '1';
					output[j][i] = '0';
					winsSoFar[i]++;
					lossesSoFar[j]++;
				}
				// Greedily have i beat low people.
				if (winsSoFar[i] < degs[i] && lossesSoFar[j] < (s - 1 - degs[j])) {
					output[i][j] = '1';
					output[j][i] = '0';
					winsSoFar[i]++;
					lossesSoFar[j]++;
				} else {
					assert(lossesSoFar[i] < (s - 1 - degs[i]));
					assert(winsSoFar[j] < degs[j]);
					output[i][j] = '0';
					output[j][i] = '1';
					winsSoFar[j]++;
					lossesSoFar[i]++;
				}
			}
			*/
			puts(output[i]);
		}
	}
}