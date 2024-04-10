#include <bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define SZ(x) ((int) (x).size())
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef unsigned long long u64;
typedef vector<int> VI;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}

int read() {
	int x = 0, f = 1;char ch;
	for (ch = getchar(); !isdigit(ch); ch = getchar())
		if (ch == '-') f = -1;
	for (; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}

const int MaxN = 2001234, P = 1e9 + 7;

int n; char s[MaxN];

namespace PAM {
	char s[MaxN];
	int ch[MaxN][26], fail[MaxN], len[MaxN], par[MaxN], dif[MaxN], lst, cnt;
	void extend(int i) {
		int p = lst, c = s[i] - 'a';
		while(s[i - len[p] - 1] != s[i])
			p = fail[p];
		if(!ch[p][c]) {
			int np = ++cnt, q = fail[p]; len[np] = len[p] + 2;
			while(s[i - len[q] - 1] != s[i])
				q = fail[q];
			fail[np] = ch[q][c]; ch[p][c] = np; dif[np] = len[np] - len[fail[np]];
			if(dif[np] == dif[fail[np]])
				par[np] = par[fail[np]];
			else
				par[np] = fail[np];
		}
		lst = ch[p][c];
	}
	void init() {
		cnt = fail[0] = 1; len[1] = -1; len[0] = 0; 
	} 
	int f[MaxN], g[MaxN];
	int dp() {
		f[0] = 1;
		for (int i = 1; i <= n; i++) {
			extend(i);
			for (int p = lst; p; p = par[p]) {
				g[p] = f[i - len[par[p]] - dif[p]];
				if(dif[p] == dif[fail[p]])
					(g[p] += g[fail[p]]) %= P;
				(f[i] += g[p]) %= P;
			}
			if(i & 1)
				f[i] = 0;
		}
		return f[n];
	}
}

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i * 2 <= n; i++) {
		PAM ::s[i * 2 - 1] = s[i];
		PAM ::s[i * 2] = s[n - i + 1]; 
	}
	PAM ::init();
	cout << PAM ::dp();
	return 0;
}