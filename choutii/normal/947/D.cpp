// B = C
// 
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

const int MaxN = 101234;
char s[MaxN], t[MaxN];

int sa[MaxN], ta[MaxN], tb[MaxN], sb[MaxN], ans[MaxN], n, m;

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		if(s[i] == 'A')
			sa[i] = sa[i - 1] + 1;
		sb[i] = sb[i - 1] + (s[i] != 'A');	
	} 
	scanf("%s", t + 1); m = strlen(t + 1);
	for (int i = 1; i <= m; i++) {
		if(t[i] == 'A')
			ta[i] = ta[i - 1] + 1;
		tb[i] = tb[i - 1] + (t[i] != 'A');	
	} 
	int q = read();
	for (int i = 1; i <= q; i++) {
		int la = read(), ra = read();
		int lb = read(), rb = read();
		int cs = sb[ra] - sb[la - 1];
		int ct = tb[rb] - tb[lb - 1];
		int ds = min(sa[ra], ra - la + 1);
		int dt = min(ta[rb], rb - lb + 1);
		if(!cs && ct) {
			if(ds <= dt)
				continue;
		}
		if(cs > ct)
			continue;
		else if(cs == ct) 
			ans[i] = (ds >= dt && (ds - dt) % 3 == 0);
		else
			ans[i] = ds >= dt && !(ct - cs & 1);
	}
	for (int i = 1; i <= q; i++) putchar('0' + ans[i]);
	return 0;
}