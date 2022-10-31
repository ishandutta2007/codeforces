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
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#define X first
#define Y second

#define Error(x) cout << #x << " = " << x << endl

template <typename T, typename U>
inline void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
inline void chkmin(T& x, U y) {
	if (y < x) x = y; 
}
 
int a[222], b[222];
 
int main() {
	
	int n; cin >> n;
	VI V;
	for (int i = 0; i < n; i++) {
		int s, d; cin >> s >> d;
		bool flg = 1;
		for (int j = 0; flg && j < i; j++) {
			int l = max(a[j], s), r = min(b[j], s + d - 1);
			if (l <= r) flg = 0;
		}
		if (flg) {
			a[i] = s, b[i] = s + d - 1;
		} else {
			V.clear();
			V.push_back(1);
			for (int j = 0; j < i; j++) V.push_back(b[j]+1);
			sort(all(V));
			V.erase(unique(all(V)), V.end());
			for (int k = 0; k < V.size(); k++) {
				int L = V[k], R = V[k] + d - 1;
				bool bf = 1;
				for (int j = 0; bf && j < i; j++) {
					int l = max(a[j], L), r = min(b[j], R);
					if (l <= r) bf = 0;
				}
				if (bf) {
					a[i] = L, b[i] = R;
					break;
				}
			}
		}
		printf("%d %d\n", a[i], b[i]);
	}
	return 0;
}