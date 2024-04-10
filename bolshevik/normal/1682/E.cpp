#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;
const int o=2e5+10;
int n,p[o],m,d[o];bool vis[o];vector<pair<int,int> > e[o];
inline bool cmp(pair<int,int> A,pair<int,int> B){return d[A.first]>d[B.first];}
inline bool Cmp(int A,int B){return d[A]<d[B];}
void dfs(int nw){
	if(vis[nw]) return;
	vis[nw]=1;
	for(int i=e[nw].size();i--;) dfs(e[nw][i].first),printf("%d ",e[nw][i].second);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%d",&p[i]);
	for(int i=1;i<=n;++i) if(!d[i]) for(int j=i,k=0;!d[j];j=p[j]) d[j]=++k;
	for(int i=1,u,v;i<=m;++i){
		scanf("%d%d",&u,&v);
		if(d[u]>d[v]) swap(u,v);
		e[u].push_back(make_pair(v,i));
	}
	for(int i=1;i<=n;++i) sort(e[p[i]=i].begin(),e[i].end(),cmp);
	sort(p+1,p+n+1,Cmp);
	for(int i=1;i<=n;++i) dfs(p[i]);
	return 0;
}