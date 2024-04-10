#include<cstdio>
#include<algorithm>
using namespace std;
const int o=1010;
int n,fa[o],s[o],d,z,ans,a[o],cnt;
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i) s[fa[i]=i]=1;
	for(int u,v;d--;printf("%d\n",ans-1),ans=cnt=0){
		scanf("%d%d",&u,&v);
		if((u=fr(u))==(v=fr(v))) ++z;
		else s[fa[v]=u]+=s[v];
		for(int i=1;i<=n;++i) if(fa[i]==i) a[++cnt]=s[i];
		sort(a+1,a+cnt+1);
		for(int i=cnt-z;i<=cnt;++i) ans+=a[i];
	}
	return 0;
}