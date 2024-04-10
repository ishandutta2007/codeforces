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
#include <bitset>

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
void chkmax(T& x, U y) {
	if (x < y) x = y;
}

template <typename T, typename U>
void chkmin(T& x, U y) {
	if (y < x) x = y;
}

const int MAXN = 111111;
int m;
char s[MAXN];
int ans[30], cnt[30];
VPII V;

int main() {
	
	scanf("%d%s", &m, s);
	for (int i = 0; s[i]; i++) {
		cnt[s[i] - 'a']++;
	}
	V.push_back(PII(0, strlen(s)));
	for (int i = 0; i < 26; i++) {
		int flg = 0;
		for (int j = 0; j < V.size() && !flg; j++) {
			int l = V[j].first, r = V[j].second;
			int last = l;
			for (int k = l; k < r; k++) if (s[k] == i + 'a') {
				if (k - last >= m) flg = 1;
				last = k + 1;
			}
			if (r - last >= m) flg = 1;
		}
		if (flg) {
			VPII tmp;
			for (int j = 0; j < V.size(); j++) {
				int l = V[j].first, r = V[j].second;
				int last = l;
				for (int k = l; k < r; k++) if (s[k] == i + 'a') {
					if (k - last >= m) {
						tmp.push_back(PII(last, k));
					}
					last = k + 1;
				}
				if (r - last >= m) {
					tmp.push_back(PII(last, r));
				}
			}
			V = tmp;
			ans[i] = cnt[i];
		} else {
			for (int j = 0; j < V.size(); j++) {
				int l = V[j].first, r = V[j].second;
				VI v;
				for (int k = l; k < r; k++) if (s[k] == i + 'a') {
					v.push_back(k);
				}
				int last = l;
				int ptr = 0;
				while (r - last >= m) {
					for (; ptr < v.size(); ptr++) {
						if (v[ptr] - last >= m) break;
					}
					ptr--;
					ans[i]++;
					last = v[ptr]+1;
				}
			}
			break;
		}
	}
	
	for (int i = 0; i < 26; i++) for (int j = 0; j < ans[i]; j++) putchar(i + 'a');
	puts("");
	return 0;
}