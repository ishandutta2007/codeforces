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

const int MaxN = 1001234, P = 1e9 + 7;

int n; char s[MaxN], t[MaxN];

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
	int f[MaxN], g[MaxN], l[MaxN];
	int dp() {
		memset(f, 0x3f, sizeof(f));
		f[0] = 0;
		for (int i = 1; i <= n; i++) {
			extend(i);
			for (int p = lst; p; p = par[p]) {
				l[p] = i - len[par[p]] - dif[p];
				if(dif[p] == dif[fail[p]])
					if(f[l[fail[p]]] < f[l[p]])
						l[p] = l[fail[p]];
				if(!(i & 1) && cmin(f[i], f[l[p]] + 1))
					g[i] = l[p];					
			}
			if(!(i & 1) && s[i] == s[i - 1] && cmin(f[i], f[i - 2]))
				g[i] = i - 2;
		}
		if(f[n] > n) return puts("-1"), 0;
		printf("%d\n", f[n]);
		for (int i = n; i; i = g[i])
			if(g[i] + 2 < i)
				printf("%d %d\n", (g[i] >> 1) + 1, i >> 1);
		return 0;
	}
}

int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1) << 1;
	for (int i = 1; i <= n; i += 2)
		PAM :: s[i] = s[i + 1 >> 1];
	for (int i = 2; i <= n; i += 2)
		PAM :: s[i] = t[i >> 1];
	PAM :: init(); 
	PAM :: dp();		
	return 0;
}