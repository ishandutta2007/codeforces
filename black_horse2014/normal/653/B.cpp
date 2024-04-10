#include <cstdio>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cctype>
#include <utility>
#include <queue>
#include <cmath>
#include <complex>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef double DB;

#define pb push_back
#define mset(a, b) memset(a, b, sizeof a)
#define all(x) (x).begin(), (x).end()
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define counti(x) (__builtin_popcount(x))
#define clz(x) (__builtin_clz(x))
#define ctz(x) (__builtin_ctz(x))
#define countl(x) (__builtin_popcountll(x))
#define rep(i, n) for (int (i) = 0; (i) < (int)(n); ++(i))
#define Error(x) cout << #x << " = " << x << endl
#define X first
#define Y second

template <typename T, typename U> 
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y;
}
const int MAXN = 444444;
int n, Q;
int chk[MAXN], T;
char str[40][3], s[40][2];
VI id[7];
int main() {
	
	scanf("%d%d", &n, &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%s%s", str[i], s[i]);
		id[s[i][0] - 'a'].pb(i);
	}
	VI V;
	V.pb(0);
	for (int i = 1; i < n; i++) {
		T++;
		VI V1;
		for (int j = 0; j < V.size(); j++) {
			int a[8], cur = V[j], b[8];
			for (int k = 0; k < i; k++) a[k] = cur % 6, cur /= 6;
			for (int k = 0; k < 1; k++) {
				for (int l = 0; l < id[a[k]].size(); l++) {
					int c = id[a[k]][l];
					for (int it = 0; it < k; it++) b[it] = a[it];
					b[k] = str[c][0] - 'a'; b[k + 1] = str[c][1] - 'a';
					for (int it = k + 1; it < i; it++) b[it + 1] = a[it];
					int state = 0;
					for (int it = i; it >= 0; it--) {
						state = state * 6 + b[it];
					}
					if (chk[state] == T) continue;
					chk[state] = T;
					V1.pb(state);
				}
			}
		}
		V = V1;
//		for (int j = 0; j < V.size(); j++) cout << V[j] << ' ';
//		cout << endl;
	}
	printf("%d\n", V.size());
	return 0;
}