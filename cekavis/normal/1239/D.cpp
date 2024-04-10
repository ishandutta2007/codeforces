#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005;
int T, n, m, num, cnt, tot, top, d[N], stk[N], bl[N], dfn[N], low[N], h[N], e[N], pre[N];
bool instk[N];
void add(int x, int y){ e[++num]=y, pre[num]=h[x], h[x]=num;}
void tarjan(int u){
	dfn[u]=low[u]=++cnt;
	instk[stk[++top]=u]=1;
	for(int i=h[u]; i; i=pre[i]){
		if(!dfn[e[i]]) tarjan(e[i]), low[u]=min(low[u], low[e[i]]);
		else if(instk[e[i]]) low[u]=min(low[u], dfn[e[i]]);
	}
	if(dfn[u]==low[u]){
		++tot;
		do bl[stk[top]]=tot, instk[stk[top]]=0; while(stk[top--]!=u);
	}
}
int main() {
	// freopen("1.in", "r", stdin);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d", &n, &m);
		for(int i=1; i<=m; ++i){
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y);
		}
		memset(dfn+1, 0, n<<2), tot=0;
		for(int i=1; i<=n; ++i) if(!dfn[i]) tarjan(i);
		// for(int i=1; i<=n; ++i) printf("[%d]%c", bl[i], " \n"[i==n]);
		memset(d+1, 0, tot<<2);
		for(int i=1; i<=n; ++i) for(int j=h[i]; j; j=pre[j])
			if(bl[i]!=bl[e[j]]) ++d[bl[e[j]]];
		for(int i=1; i<=tot; ++i) if(!d[i]){
			int x=0;
			for(int j=1; j<=n; ++j) x+=bl[j]==i;
			if(x==n) continue;
			puts("Yes");
			printf("%d %d\n", n-x, x);
			for(int j=1; j<=n; ++j) if(bl[j]!=i) printf("%d ", j);
			puts("");
			for(int j=1; j<=n; ++j) if(bl[j]==i) printf("%d ", j);
			puts("");
			goto ok;
		}
		puts("No");
		ok:;
		memset(h+1, 0, n<<2), num=0;
	}
	return 0;
}