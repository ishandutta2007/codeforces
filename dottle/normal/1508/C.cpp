#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#include<set>
#include<vector>
#include<queue>
using namespace std;

const int N=2e5+5;

int n,m,f[N];

int find(int x) {return x==f[x]?x:f[x]=find(f[x]);}

int fr[N],to[N];
long long vl[N],W;

struct Edge {
	int from,to;
	long long val;
	inline Edge (int F=0,int T=0,long long V=0) : from(F),to(T),val(V) {}
	inline bool operator < (const Edge &a) const {return val<a.val;}
}a[N],b[N];

bool flag;
int bel[N],cnt,tot;

set <int> g[N],s;
vector <int> vec;

void bfs(int u) {
	bel[u]=cnt;
	queue <int> q;
	q.push(u);
	while(!q.empty()) {
		int u=q.front();q.pop();vec.clear();
		bel[u]=cnt;
		for(set <int> ::iterator it=s.begin() ; it!=s.end() ; ++it)
			if(g[u].find(*it)==g[u].end()) q.push(*it),vec.push_back(*it);
		for(int i=0 ; i<vec.size() ; ++i) s.erase(vec[i]);
	}
}

long long ans;

int main() {
	scanf("%d%d",&n,&m),W=0;
	long long rem=1LL*n*(n-1)/2-m;
	for(int i=1 ; i<=m ; ++i) {
		scanf("%d%d%lld",&fr[i],&to[i],&vl[i]);
		W^=vl[i],b[i]=Edge(fr[i],to[i],vl[i]);
		g[fr[i]].insert(to[i]),g[to[i]].insert(fr[i]);
	}
	for(int i=1 ; i<=n ; ++i) f[i]=i,s.insert(i);
	sort(b+1,b+m+1);
	int c=0;
	for(int i=1 ; i<=m ; ++i) {
		int u=b[i].from,v=b[i].to;
		int r1=find(u),r2=find(v);
		if(r1==r2) continue ;
		f[r1]=r2,fr[++c]=u,to[c]=v,vl[c]=b[i].val;
	}
	for(int i=1 ; i<=n ; ++i) if(!bel[i]) ++cnt,bfs(i);
	m=c;
	for(int i=1 ; i<=m ; ++i) {
		int u=fr[i],v=to[i];long long w=vl[i];
		if(bel[u]==bel[v]) W=min(W,w);
		else a[++tot]=Edge(bel[u],bel[v],w);
	}
	for(int i=1 ; i<=cnt ; ++i) f[i]=i;
	sort(a+1,a+tot+1);
	for(int i=1 ; i<=tot ; ++i) {
		int u=a[i].from,v=a[i].to;long long w=a[i].val;
		int r1=find(u),r2=find(v);
		if(r1==r2) {W=min(W,w);continue ;}
		f[r1]=r2,ans+=w;
	}
	if(rem>n-cnt) printf("%lld",ans);
	else printf("%lld",ans+W);
	return 0;
}