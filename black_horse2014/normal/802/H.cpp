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

const int N = 1000000+10;
int hd[N];
char pat[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main() {
	hd[1] = 0;
	for (int i = 2; i < N; i ++) {
		int p = 31-__builtin_clz(i-1);
		int j = 1<<p;
		while (1) {
			if (hd[i-j]>=p-1) {
				hd[i] = p;
				break;
			}
			j >>= 1;
			--p;
		}
	}
	int n; scanf("%d", &n);
	if (n == 1) {
		puts("a a");
		return 0;
	}
	vector<int> vec;
	while (n) {
		vec.push_back(hd[n]);
		n -= 1<<(hd[n]);
	}
//	for (int i = 0; i < vec.size(); i ++) cout << vec[i] << " ";
	int l = vec.size();
	int la = vec[l-1];
	vector<int> A, B;
	A.resize(l-1), B.resize(l-1);
	for (int i = 0; i < l-1; i ++) {
		if (vec[i]>vec[i+1]) {
			A[i] = 2;
			B[i] = 1;
		}
	}
	for (int i = 0, cur = 0; i < l-1 and cur < la; i ++) {
		if (vec[i]==vec[i+1]) {
			A[i] = B[i] = 2;
			++ cur;
		}
	}
	for (int i = 0; i < l-1; i ++) {
		if (!A[i]) A[i] = B[i] = 1;
	}
	int res = 0;
	for (int i = 0; i < l; i ++) {
		int mul = 1;
		for (int j = 0; j < i; j ++) {
			mul*=B[j];
		
		}
		for (int j = i; j < l-1; j ++) {
			mul*=A[j];
		}
		res += mul;
	}
//	cerr << res << endl;
	for (int i = 0; i < l-1; i ++) {
		for (int j = 0; j < B[i]; j ++) {
			printf("%c", pat[i]);
		}
	}
	for (int i = 0; i < l-1; i ++) {
		for (int j = 0; j < A[i]; j ++) {
			printf("%c", pat[i]);
		}
	}
	printf(" ");
	for (int i = 0; i < l-1; i ++) printf("%c", pat[i]);
	return 0;
}