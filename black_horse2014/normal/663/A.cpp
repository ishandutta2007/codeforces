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
char str[555555], s[555555];
int sn = 0, n, sz1, sz2;
VI V, V1;

int main() {
	
	gets(str);
	for (int i = 0; str[i]; i++) if (str[i] != ' ') {
		s[sn++] = str[i];
	}
	for (int i = 0; i < sn; i++) if (s[i] == '=') {
		for (int j = i + 1; j < sn; j++) n = n * 10 + s[j] - '0';
		break;
	}
	for (int i = 0; i < sn; i++) if (s[i] == '?') {
		if (i == 0 || s[i - 1] == '+') sz1++;
		else sz2++;
	}
	if (sz1 - (LL)n * sz2 > n) {
		puts("Impossible");
		return 0;
	}
	if ((LL)sz1 * n - sz2 < n) {
		puts("Impossible");
		return 0;
	}
	puts("Possible");
	if (sz1 > sz2) {
		if (sz1 > sz2 + n) {
			for (int i = 0; i < sz1; i++) V.push_back(1);
			int sum =sz1 - n;
			for (int i = 0; i < sz2; i++) {
				if (sum <= n + sz2 - i - 1) {
					int c = sum - sz2 + i + 1;
					V1.push_back(c);
					for (int j = i + 1; j < sz2; j++) V1.push_back(1);
					break;
				} else {
					V1.push_back(n);
					sum -= n;
				}
			}
		} else {
			int dif = sz1 - sz2;
			for (int i = 0; i < dif - 1; i++) V.push_back(1);
			V.push_back(n - dif + 1);
			for (int i = 0; i < sz2; i++) V.push_back(1), V1.push_back(1);
		}
	} else if (sz1 == sz2) {
		V.push_back(n);
		V.push_back(2);
		for (int i = 2; i < sz1; i++) V.push_back(1);
		for (int i = 0; i < sz2; i++) V1.push_back(1);
	} else {
		for (int i = 0; i < sz1; i++) V.push_back(n);
		LL sum = (LL)(sz1 - 1) * n;
		for (int i = 0; i < sz2; i++) {
			if (sum <= n + sz2 - i - 1) {
				int c = sum - sz2 + i + 1;
				V1.push_back(c);
				for (int j = i + 1; j < sz2; j++) V1.push_back(1);
				break;
			} else {
				V1.push_back(n);
				sum -= n;
			}
		}
	}
	int st = 0, st1 = 0;
	for (int i = 0; i < sn; i++) {
		if (s[i] != '?') {
			if (s[i] == '+' || s[i] == '-' || s[i] == '=') {
				putchar(' ');
				putchar(s[i]);
				putchar(' ');
				continue;
			}
			putchar(s[i]);
		}
		else {
			if (i == 0 || s[i - 1] == '+') {
				printf("%d", V[st++]);
			} else {
				printf("%d", V1[st1++]);
			}
		}
	}
	puts("");
	return 0;
}