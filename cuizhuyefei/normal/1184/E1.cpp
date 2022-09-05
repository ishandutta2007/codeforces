#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct edge{
	int a,b,e;
	inline void in(){cin>>a>>b>>e;}
}E[N];
int n,m,i,j,g[N],id[N];
inline bool cmp(int x,int y){
	return E[x].e<E[y].e;
}
int gfa(int x){
	return g[x]==x?x:g[x]=gfa(g[x]);
}
inline bool ck(int v){
	int i,z;
	for(i=1;i<=n;++i)g[i]=i;
	for(i=2;i<=m;++i){
		if(v<=E[id[i]].e)return gfa(E[1].a)!=gfa(E[1].b);
		z=id[i];int x=E[z].a,y=E[z].b;
		if(gfa(x)==gfa(y))continue;
		g[gfa(x)]=gfa(y);
	}
	return gfa(E[1].a)!=gfa(E[1].b);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;for(i=1;i<=m;++i)E[id[i]=i].in();
	sort(id+2,id+m+1,cmp);
	int l=0,r=1e9,md;
	for(;l<r;){
		md=l+r+1>>1;
		if(ck(md))l=md;else r=md-1;
	}
	cout<<l<<endl;
	return 0;
}