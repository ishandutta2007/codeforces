#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 200005
#define ll long long 
#define mo 998244353
using namespace std;

int T,n,m,i,j,k,a[maxn],b[maxn],c[maxn],bz[maxn];
ll ans;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++) scanf("%d",&a[i]),b[a[i]]=i,bz[i]=0;
		for(i=1;i<=m;i++) scanf("%d",&c[i]),bz[c[i]]=i;
		ans=1;
		for(i=1;i<=m;i++){
			int x=b[c[i]];
			ll ans0=0;
			if (x>1&&bz[a[x-1]]<=i) ans0+=ans;
			if (x<n&&bz[a[x+1]]<=i) ans0+=ans;
			ans=ans0%mo;
		}
		printf("%lld\n",ans);
	}
}