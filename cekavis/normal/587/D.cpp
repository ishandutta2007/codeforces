#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 50005, M = N*10;
int n, m, x[N], y[N], c[N], t[N], tt[N];
vector<int> s[N], e[M];
map<int,vector<int>> f[N];
struct two_sat{
	int id, top, cnt, stk[M], dfn[M], low[M], bl[M];
	bool ans[M], instk[M];
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
	bool Solve(int n, int m, int ti){
		id=top=cnt=0, memset(dfn+1, 0, m<<2);
		for(int i=1; i<=n; ++i) if(t[i]>ti) add(i, i+n);
		for(int i=1; i<=m; ++i) if(!dfn[i]) tarjan(i);
		// for(int i=1; i<=m; ++i) e[i].clear();
		for(int i=1; i<=n; ++i) if(t[i]>ti) e[i].pop_back();
		for(int i=1; i<=n; ++i) if(bl[i]==bl[i+n]) return 0;
		for(int i=1; i<=n; ++i) ans[i]=bl[i]<bl[i+n];
		return 1;
	}
	bool &operator[](int x){ return ans[x];}
} wish;
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1; i<=m; ++i){
		scanf("%d%d%d%d", x+i, y+i, c+i, t+i), tt[i]=t[i];
		s[x[i]].push_back(i), s[y[i]].push_back(i);
		f[x[i]][c[i]].push_back(i), f[y[i]][c[i]].push_back(i);
	}
	sort(tt+1, tt+m+1);
	int now=m*2;
	for(int i=1; i<=n; ++i) if((int)s[i].size()>1){
		wish.add(++now, s[i][0]+m);
		for(int j=1; j<(int)s[i].size(); ++j){
			wish.add(s[i][j], now);
			if(j<(int)s[i].size()-1)
				++now, wish.add(now, now-1), wish.add(now, s[i][j]+m);
		}
		reverse(s[i].begin(), s[i].end());
		wish.add(++now, s[i][0]+m);
		for(int j=1; j<(int)s[i].size(); ++j){
			wish.add(s[i][j], now);
			if(j<(int)s[i].size()-1)
				++now, wish.add(now, now-1), wish.add(now, s[i][j]+m);
		}
	}
	for(int i=1; i<=n; ++i) for(auto &a:f[i]) if((int)a.second.size()>1){
		wish.add(++now, a.second[0]);
		for(int j=1; j<(int)a.second.size(); ++j){
			wish.add(a.second[j]+m, now);
			if(j<(int)a.second.size()-1)
				++now, wish.add(now, now-1), wish.add(now, a.second[j]);
		}
		reverse(a.second.begin(), a.second.end());
		wish.add(++now, a.second[0]);
		for(int j=1; j<(int)a.second.size(); ++j){
			wish.add(a.second[j]+m, now);
			if(j<(int)a.second.size()-1)
				++now, wish.add(now, now-1), wish.add(now, a.second[j]);
		}
	}
	int l=0, r=m, ans=-1;
	// printf(">> %d\n", wish.Solve(m, now, tt[m]));
	while(l<=r){
		int mid=(l+r)>>1;
		if(wish.Solve(m, now, tt[mid])) ans=mid, r=mid-1; else l=mid+1;
	}
	// printf(">> %d\n", wish.Solve(m, now, 0));
	if(ans==-1) puts("No");
	else{
		puts("Yes");
		wish.Solve(m, now, ans);
		int cnt=0;
		for(int i=1; i<=m; ++i) cnt+=wish[i];
		printf("%d %d\n", tt[ans], cnt);
		for(int i=1; i<=m; ++i) if(wish[i]) printf("%d ", i);
		puts("");
	}
	return 0;
}