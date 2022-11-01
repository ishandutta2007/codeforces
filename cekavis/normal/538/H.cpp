#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005, M = N*9*2;
struct two_sat{
	int id, top, cnt, stk[M], dfn[M], low[M], bl[M];
	bool ans[M/2], instk[M];
	vector<int> e[M];
	void add(int x, int y){ e[x].push_back(y);}
	void tarjan(int u){
		dfn[u]=low[u]=++cnt;
		instk[stk[++top]=u]=1;
		for(int v:e[u])
			if(!dfn[v]) tarjan(v), low[u]=min(low[u], low[v]);
			else if(instk[v]) low[u]=min(low[u], dfn[v]);
		if(low[u]==dfn[u]){
			++id;
			do instk[stk[top]]=0, bl[stk[top]]=id; while(stk[top--]!=u);
		}
	}
	bool Solve(int n){
		id=top=cnt=0, memset(dfn+1, 0, n<<3);
		for(int i=1; i<=n<<1; ++i) if(!dfn[i]) tarjan(i);
		for(int i=1; i<=n<<1; ++i) e[i].clear();
		for(int i=1; i<=n; ++i) if(bl[i]==bl[i+n]) return 0;
		for(int i=1; i<=n; ++i) ans[i]=bl[i]<bl[i+n];
		return 1;
	}
	bool &operator[](int x){ return ans[x];}
} wish;
int t1, t2, n, m, cnt, l[N], r[N], a[N*4];
void add(int x){
	a[++cnt]=x;
	if(x<=t1) a[++cnt]=t1-x;
}
int main() {
	scanf("%d%d%d%d", &t1, &t2, &n, &m);
	add(0);
	for(int i=1; i<=n; ++i){
		scanf("%d%d", l+i, r+i), add(l[i]), add(r[i]);
		if(l[i]>t2) return puts("IMPOSSIBLE"), 0;
	}
	sort(a+1, a+cnt+1), cnt=unique(a+1, a+cnt+1)-a-1;
	int tot=cnt*2+n;
	for(int i=1; i<cnt; ++i)
		wish.add(i+1, i), wish.add(tot+i, tot+i+1),
		wish.add(i+cnt+1, i+cnt), wish.add(tot+i+cnt, tot+i+cnt+1);
	for(int i=1; i<=cnt; ++i){
		int x=lower_bound(a+1, a+cnt+1, t1-a[i-1])-a;
		if(x<=cnt){
			wish.add(tot+i, x+cnt), wish.add(tot+x+cnt, i);
			wish.add(tot+i+cnt, x), wish.add(tot+x, i+cnt);
		}
		x=upper_bound(a+1, a+cnt+1, t2-a[i])-a;
		if(x<=cnt){
			wish.add(i, tot+x+cnt), wish.add(x+cnt, tot+i);
			wish.add(i+cnt, tot+x), wish.add(x, tot+i+cnt);
		}
	}
	while(m--){
		int x, y;
		scanf("%d%d", &x, &y);
		wish.add(x+cnt*2, tot+y+cnt*2);
		wish.add(y+cnt*2, tot+x+cnt*2);
		wish.add(tot+x+cnt*2, y+cnt*2);
		wish.add(tot+y+cnt*2, x+cnt*2);
	}
	for(int i=1; i<=n; ++i){
		int x=lower_bound(a+1, a+cnt+1, l[i])-a;
		wish.add(tot+x, tot+i+cnt*2), wish.add(i+cnt*2, x);
		wish.add(tot+x+cnt, i+cnt*2), wish.add(tot+i+cnt*2, x+cnt);
		x=upper_bound(a+1, a+cnt+1, r[i])-a;
		if(x<=cnt)
			wish.add(x, tot+i+cnt*2), wish.add(i+cnt*2, tot+x),
			wish.add(cnt+x, i+cnt*2), wish.add(tot+i+cnt*2, tot+cnt+x);
	}
	if(wish.Solve(tot)){
		puts("POSSIBLE");
		for(int i=cnt; i; --i) if(wish[i]){ printf("%d ", a[i]); break;}
		for(int i=cnt; i; --i) if(wish[i+cnt]){ printf("%d\n", a[i]); break;}
		for(int i=1; i<=n; ++i) putchar('2'-wish[i+cnt*2]);
		puts("");
	}
	else puts("IMPOSSIBLE");
	return 0;
}