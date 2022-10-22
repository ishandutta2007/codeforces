#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=2e5+3;
int n,fa[N],d[N],siz[N];ll a[N],fs[N],fx[N];
int main(){
	int u;
	scanf("%d",&n);
	for(u=2;u<=n;u++)scanf("%d",fa+u),++d[fa[u]];
	for(u=1;u<=n;u++)scanf("%lld",a+u);
	for(u=n;u;u--){
	  if(!d[u])fx[u]=fs[u]=a[u],siz[u]=1;
	  else{
		fs[u]+=a[u];
		fx[u]=std::max(fx[u],fs[u]/siz[u]+(fs[u]%siz[u]!=0));
	  }
	  fx[fa[u]]=std::max(fx[fa[u]],fx[u]);
	  fs[fa[u]]+=fs[u];
	  siz[fa[u]]+=siz[u];
	}printf("%lld\n",fx[1]);
	return 0;
}