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

int chk[11111][111];
int x[111], cnt[111], id[111], cn[111];
int sm, n;
int p[111];

int calc(int k) {
	if (k == 0) return 1;
	multiset<int> ms;
	ms.clear();
	multiset<int> :: iterator it;
	for (int i = 0; i < n; i++) ms.insert(x[i]);
	if ((sm - n * k) % 2) {
		if (n < 3) return 0;
		it = ms.end();
		for (int i = 0; i < 3; i++) {
			it--;
			p[i] = 	*it;
		}
		for (int i = 0; i < 3; i++) {
			it = ms.end();
			it--;
			ms.erase(it);
		}
		for (int i = 0; i < 3; i++) ms.insert(p[i] - 1);
	}
	while (1) {
		it = ms.begin();
		if (*it < k) return 0;
		it = ms.end();
		it--;
		if (*it == k) return 1;
		it = ms.end();
		for (int i = 0; i < 2; i++) {
			it--;
			p[i] = 	*it;
		}
		for (int i = 0; i < 2; i++) {
			it = ms.end();
			it--;
			ms.erase(it);
		}
		for (int i = 0; i < 2; i++) ms.insert(p[i] - 1);
	}
}

bool cmp(int i, int j) {
	return x[i] > x[j];
}

int main() {

	scanf("%d", &n);
	int l = 111;
	for (int i = 0; i < n; i++) scanf("%d", x + i), cnt[x[i]]++, chkmin(l, x[i]), sm += x[i];
	int t = 0;
	for (int k = l; k >= 0; k--) {
		if (calc(k)) {
			for (int i = 0; i < n; i++) id[i] = i;
			if (k && n > 2 && (sm - k * n) % 2) {
				sort(id, id + n, cmp);
				for (int i = 0; i < 3; i++) chk[t][id[i]] = 1, x[id[i]]--;
				t++;
			}
			while (1) {
				for (int i = 0; i < n; i++) id[i] = i;
				sort(id, id + n, cmp);
				if (x[id[0]] <= k) break;
				for (int i = 0; i < 2; i++) chk[t][id[i]] = 1, x[id[i]]--;
				t++;
			}
			cout<<k<<endl;
			break;
		}
	}
	cout<<t<<endl;
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", chk[i][j]);
		}
		cout<<endl;
	}
	return 0;
}