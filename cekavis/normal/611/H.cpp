#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int inf = 1e9;
struct MaxFlow{
	struct edge{ int to, f, id;};
	bool gap;
	int n, S, T;
	vector<int> cur, cnt, d;
	vector<vector<edge>> e;
	void ext(int x){ if(++x>n) e.resize(n=x);}
	inline void add(int x, int y, int z){
		// printf("add: %d %d %d\n", x, y, z);
		ext(x), ext(y);
		e[x].push_back((edge){y, z, (int)e[y].size()});
		e[y].push_back((edge){x, 0, (int)e[x].size()-1});
	}
	int sap(int u, int flow){
		if(u==T || !flow) return flow;
		int now=0;
		for(unsigned i=cur[u]; i<e[u].size(); ++i){
			edge &v=e[u][i];
			if(d[v.to]+1==d[u]){
				int tmp=sap(v.to, min(flow-now, v.f));
				v.f-=tmp, now+=tmp, e[v.to][v.id].f+=tmp, cur[u]=i;
				if(gap) return now;
			}
			if(now==flow) return flow;
		}
		cur[u]=0;
		if(!--cnt[d[u]]) gap=1;
		else ++cnt[++d[u]];
		return now;
	}
	int solve(int s, int t){
		cur.resize(n), cnt.resize(n), d.resize(n);
		S=s, T=t, cnt[0]=n-1, gap=0;
		int ans=0;
		while(!gap && d[S]<n) ans+=sap(s, inf);
		return ans;
	}
	void clear(){ n=0, cur.clear(), cnt.clear(), d.clear(), e.clear();}
} wish;
const int N = 8;
int n, m, Id, p[N], c[N], d[N], a[N][N], b[N][N], id[N][N];
pair<int,int> e[N];
char s[N], t[N];
void dfs(int x){
	if(x==m-1){
		p[x]=1;
		for(int i=1; i<m; ++i) ++d[p[i]];
		priority_queue<int> q;
		for(int i=1; i<=m; ++i) if(!d[i]) q.push(i);
		memcpy(b, a, sizeof a);
		for(int i=1; i<m; ++i){
			int u=q.top(), v=p[i];
			q.pop();
			if(!--d[v]) q.push(v);
			if(u>v) swap(u, v);
			// printf("%d %d\n", u, v);
			--b[u][v], e[i]=make_pair(u, v);
		}
		wish.clear();
		int sum=0;
		for(int i=1, now=1; i<=m; ++i, now*=10){
			int cnt=(i<m?now*9:n-now+1)-1-a[i][i];
			if(cnt<0) return;
			wish.add(id[i][i], Id+2, cnt), sum+=cnt;
		}
		for(int i=1; i<m; ++i) for(int j=i+1; j<=m; ++j)
			if(b[i][j]<0) return;
			else
				wish.add(Id+1, id[i][j], b[i][j]),
				wish.add(id[i][j], id[i][i], inf),
				wish.add(id[i][j], id[j][j], inf);
		// printf("qaq: %d\n", wish.solve(Id+1, Id+2));
		// return;
		if(wish.solve(Id+1, Id+2)==sum){
			c[1]=1, d[1]=2;
			for(int i=2; i<=m; ++i) d[i]=1+(c[i]=c[i-1]*10);
			for(int i=1; i<m; ++i)
				printf("%d %d\n", c[e[i].first], c[e[i].second]);
			for(int i=1; i<=m; ++i) for(int j=0; j<a[i][i]; ++j)
				printf("%d %d\n", c[i], d[i]++);
			for(int i=1; i<m; ++i) for(int j=i+1; j<=m; ++j){
				// printf("flow: %d %d\n", wish.e[id[i][j]][1].f, wish.e[id[i][j]][2].f);
				for(int k=0; k<inf-wish.e[id[i][j]][1].f; ++k)
					printf("%d %d\n", c[j], d[i]++);
				for(int k=0; k<inf-wish.e[id[i][j]][2].f; ++k)
					printf("%d %d\n", c[i], d[j]++);
			}
			exit(0);
		}
		return;
	}
	for(p[x]=1; p[x]<=m; ++p[x]) dfs(x+1);
}
int main() {
	scanf("%d", &n);
	if(n<10){
		for(int i=1; i<n; ++i) printf("%d %d\n", i, i+1);
		return 0;
	}
	for(int i=n; i; i/=10, ++m);
	for(int i=1; i<n; ++i){
		scanf("%s%s", s, t);
		++a[strlen(s)][strlen(t)];
	}
	for(int i=1; i<m; ++i) for(int j=i+1; j<=m; ++j) a[i][j]+=a[j][i];
	for(int i=1; i<=m; ++i) for(int j=i; j<=m; ++j) id[i][j]=++Id;
	dfs(1);
	puts("-1");
	return 0;
}