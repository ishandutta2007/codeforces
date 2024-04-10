#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
char buf[1 << 23], *ps = buf, *pt = buf;
#define getchar() (ps == pt && (pt = (ps = buf) + fread(buf, 1, 1 << 23, stdin), ps == pt) ? EOF : *ps++)
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int read(char *s){
	int n = 0;
	char ch = getchar();
	for (; isspace(ch) && ch != EOF; ch = getchar()) ;
	for (; !isspace(ch) && ch != EOF; ch = getchar()) s[n++] = ch;
	return s[n] = '\0', n;
}
char pbuf[1 << 23], *pp = pbuf;
#define putchar(x) (pp == pbuf + (1 << 23) ? fwrite(pbuf, 1, 1 << 23, stdout), pp = pbuf : 0, *pp++ = x)
struct __IO_flusher{ ~__IO_flusher(){ fwrite(pbuf, 1, pp - pbuf, stdout); } } IO_flusher;
void print(int x, char ch = '\n'){
	if (x == 0) return putchar('0'), putchar(ch), void(0);
	int cnt = 0, num[25];
	for (x < 0 ? putchar('-'), x = -x : 0; x; x /= 10) num[++cnt] = x % 10;
	while (cnt) putchar(num[cnt] ^ '0'), --cnt;
	putchar(ch);
}
void print(const char *s, int n = -1, char ch = '\n'){
	if (n == -1) n = strlen(s);
	for (register int i = 0; i < n; ++i) putchar(s[i]);
	putchar(ch);
}
const int N = 205;
int n, vis[26], cnt;
char s[N], ans[30];
std::vector<int> E[26];
void dfs(int u){
	vis[u] = 1, ans[++cnt] = 'a' + u;
	for (int v : E[u]) if (!vis[v]) dfs(v);
}
void solve(){
	n = read(s + 1);
	for (register int i = 0; i < 26; ++i) E[i].clear(), vis[i] = 0;
	for (register int i = 2; i <= n; ++i)
		E[s[i] - 'a'].push_back(s[i - 1] - 'a'), E[s[i - 1] - 'a'].push_back(s[i] - 'a');
	for (register int i = 0; i < 26; ++i)
		std::sort(E[i].begin(), E[i].end()), E[i].erase(std::unique(E[i].begin(), E[i].end()), E[i].end());
	for (register int i = 0; i < 26; ++i){
		int d = E[i].size();
		if (d > 2) return print("NO"), void(0);
	}
	cnt = 0;
	for (register int i = 0; i < 26; ++i)
		if (!vis[i] && (int)E[i].size() < 2) dfs(i);
	if (cnt < 26) return print("NO"), void(0);
	print("YES"), print(ans + 1, cnt);
}
int main(){
	int T = read();
	while (T--) solve();
}