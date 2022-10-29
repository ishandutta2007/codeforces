#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

#define maxn 400005
#define ll long long 
#define mo 1000000007

using namespace std;



int T,n,i,j,k,a[maxn],b[maxn],fa[maxn];
int father(int x){return (fa[x]==x)?x:fa[x]=father(fa[x]);}



int main(){


	scanf("%d",&T);

	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		for(i=1;i<=n;i++) scanf("%d",&b[i]);
		for(i=1;i<=n;i++) fa[i]=i;
		for(i=1;i<=n;i++) fa[father(a[i])]=father(b[i]);
		ll ans=1;
		for(i=1;i<=n;i++) if (fa[i]==i)
			ans=ans*2%mo;
		printf("%lld\n",ans);
	}

}