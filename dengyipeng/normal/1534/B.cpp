#include<cstdio>

#include<algorithm>

#include<cmath>

#include<cstring>

#define maxn 400005
#define ll long long 

using namespace std;



int T,n,i,j,k,a[maxn];



int main(){

	scanf("%d",&T);

	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		ll ans=0;
		a[0]=a[n+1]=0;
		for(i=1;i<=n+1;i++) ans+=abs(a[i]-a[i-1]);
		for(i=1;i<=n;i++) if (a[i]>a[i-1]&&a[i]>a[i+1])
			ans-=min(a[i]-a[i-1],a[i]-a[i+1]);
		printf("%lld\n",ans);
	}

}