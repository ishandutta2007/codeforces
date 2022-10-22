#include<bits/stdc++.h>
typedef long long ll;
const int M=1e9+7,N=5e5+3;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int n,m,p[N],siz[N],ans;
std::set<int>s;
int Find(int k){return p[k]==k?k:p[k]=Find(p[k]);}
signed main(){
	int u,v,o;
	scanf("%d%d",&m,&n),++n;
	for(u=1;u<=n;u++)p[u]=u,siz[u]=1;
	for(int j=1;j<=m;j++){
	  scanf("%d",&o);
	  if(o==1)scanf("%d",&u),v=n;
	  else scanf("%d%d",&u,&v);
	  u=Find(u),v=Find(v);
	  if(u!=v){
		p[u]=v,siz[v]+=siz[u];
		s.insert(j);
	  }
	}
	ans=1;
	for(u=1;u<=n;u++)if(p[u]==u){
	  ans=(ll)ans*Pow(2,siz[u]-1)%M;
	}
	printf("%d %d\n",ans,s.size());
	for(std::set<int>::iterator it=s.begin();it!=s.end();it++)printf("%d ",*it);puts("");
	return 0;
}