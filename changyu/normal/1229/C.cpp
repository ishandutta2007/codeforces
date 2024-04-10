#include<cstdio>
#include<vector>
const int N=1e5+3;
int n,m,q,d[N];long long ans,f[N];
std::vector<int>s1[N];
int main(){
	int tmp,u,v;
	scanf("%d%d",&n,&m);
	for(;m--;){
	  scanf("%d%d",&u,&v);
	  if(u>v)tmp=u,u=v,v=tmp;
	  s1[u].push_back(v);
	  d[u]++,d[v]++;
	}
	for(u=1;u<=n;u++)ans+=f[u]=(long long)s1[u].size()*(d[u]-s1[u].size());
	printf("%lld\n",ans);
	for(scanf("%d",&q);q--;){
	  scanf("%d",&u);
	  for(int i=0;i<s1[u].size();i++){v=s1[u][i];
		s1[v].push_back(u);
		ans-=f[v];
		f[v]=(long long)s1[v].size()*(d[v]-s1[v].size());
		ans+=f[v];
	  }
	  s1[u].clear();
	  ans-=f[u];
	  f[u]=(long long)s1[u].size()*(d[u]-s1[u].size());
	  ans+=f[u];
	  printf("%lld\n",ans);
	}return 0;
}