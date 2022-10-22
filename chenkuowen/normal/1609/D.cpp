#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
struct DSF{
	int fa[N],sz[N];
	void init(int n){
		for(int i=1;i<=n;++i) fa[i]=i,sz[i]=1;
	}
	int fs(int x){
		if(fa[x]!=x) fa[x]=fs(fa[x]);
		return fa[x];
	}
	void merge(int x,int y){
		x=fs(x),y=fs(y);
		fa[y]=x; sz[x]+=sz[y];
	}
	int gsz(int x){ return sz[fs(x)]; }
}dsf;
int main(){
	int n,d; scanf("%d%d",&n,&d);
	dsf.init(n); int cnt=0;
	for(int i=1;i<=d;++i){
		int x,y; scanf("%d%d",&x,&y);
		if(dsf.fs(x)!=dsf.fs(y))
			dsf.merge(x,y); 
		else ++cnt;
		vector<int> g;
		for(int x=1;x<=n;++x)
			if(x==dsf.fs(x)) g.push_back(dsf.gsz(x));
		sort(g.begin(),g.end());
		reverse(g.begin(),g.end());
		int ans=0;
		for(int i=0;i<cnt+1&&i<g.size();++i)
			ans+=g[i];
		printf("%d\n",ans-1);
	}
	return 0;
}