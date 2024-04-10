#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef pair<int, LL> PIL;
typedef pair<LL, int> PLI;
typedef vector<int> VI;
typedef vector<PII> VPII;
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

vector<long long> V;

int chk[11111], prv[11111];

LL n;

int main() {
	
	cin >> n;
	if (n == 1) {
		puts("1\n0");
		return 0;
	}
	for (int m = 1; 1LL*m*m <= n; m++) {
		if (n % m == 0) {
			if (m > 1) V.push_back(m);
			if (m < n / m) V.push_back(n/m);
		}
	}
	sort(all(V));
	for (int i = 0; i < V.size(); i++) {
		int flg = 0;
		for (int j = 0; j < i; j++) {
			if (V[i] % V[j] == 0) {
				flg++;
				if (!chk[j]) {
					chk[i] = 1;
					prv[i] = j;
					break;
				}
			}
		}
		if (!flg) chk[i] = 1, prv[i] = -1;
	}
	if (chk[sz(V)-1]) {
		puts("1");
		if (prv[sz(V)-1] == -1) {
			puts("0");
		} else {
			cout << V[prv[sz(V)-1]] << endl;
		}
		return 0;
	}
	puts("2");
	return 0;
}