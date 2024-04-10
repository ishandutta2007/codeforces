#include<bits/stdc++.h>

#define fir first
#define sec second
using namespace std;
typedef long long LL;

template <typename T> inline bool cmin(T & a, const T & b) { return a > b ? a = b, 1 : 0;}
template <typename T> inline bool cmax(T & a, const T & b) { return a < b ? a = b, 1 : 0;}
int inp() {
	int x = 0, f = 1;char ch;
	for(ch = getchar(); !isdigit(ch); ch = getchar())
		if(ch == '-') f = -1;
	for(; isdigit(ch); x = x * 10 + ch - '0', ch = getchar());
	return x * f;
}
const int MAXN = 41234, MAXM = 4001234;
struct edge{
	int to, nxt, cap;
}e[MAXM]; int cnt = 1, lst[MAXN];
void ins(int a, int b, int c){ e[++cnt] = (edge){b, lst[a], c}; lst[a] = cnt;}
void lnk(int a, int b, int c){ ins(a, b, c); ins(b, a, 0);}
int h[MAXN]; queue<int>q;
bool bfs(int s, int t){
	memset(h, -1, sizeof(h));
	h[s] = 0; q.push(s);
	while(!q.empty()){
		int c = q.front(); q.pop();
		for(int i=lst[c], b; b = e[i].to, i; i = e[i].nxt){
			if(!~h[b] && e[i].cap > 0){
				h[b] = h[c] + 1;
				q.push(b);
			}
		}
	}
	return ~h[t];
}
int dfs(int v, int t, int f){
	if(v == t) return f;
	int used = 0, w;
	for(int i = lst[v], b; b = e[i].to, i; i = e[i].nxt)
		if(h[b] > h[v] && e[i].cap > 0){
			w = dfs(b, t, min(f - used, e[i].cap));
			e[i].cap -= w; e[i ^ 1].cap += w;
			if((used += w) == f) return f; 
		}
	if(!used) h[v] = -1;
	return used;
}
int max_flow(int s, int t){
	int ans = 0;
	while(bfs(s, t))
		ans += dfs(s, t, ~0U>>1);
	return ans;	
} 
int n, m, g, t, ans, K[MAXN], w[MAXN], s[MAXN], v[MAXN], G[MAXN];
int main() {
	int i, p, q, o;
	n = inp(); m = inp(); g = inp();
	for(i = 1; i <= n; i++) s[i] = inp();
	for(i = 1; i <= n; i++) v[i] = inp();
	t = n + m + 1;
	for(i = 1; o = s[i], i <= n; i++)
		if(s[i]) lnk(0, i, v[i]);
		else lnk(i, t, v[i]);		
	for(i = 1; i <= m; i++){
		G[i] = inp();  w[i] = inp(); K[i] = inp();
		for(p = 1; p <= K[i]; p++) {
			q = inp();
			if(G[i]) lnk(n + i, q, ~0U >> 1);
			else lnk(q, n + i, ~0U >> 1); 
		}
		ans += w[i]; int isf = inp();
		if(isf) w[i] += g;
		if(G[i]) lnk(0, n + i, w[i]);
		else lnk(n + i, t, w[i]);
	}
	cout<<ans - max_flow(0, t);
	return 0;
}