#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 5005
#define ll long long 
using namespace std;

int T,n,i,j,k;
ll ans,sum,d[maxn],a[maxn],v[maxn];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%lld",&a[i]);
		memset(d,0,sizeof(d));
		memset(v,0,sizeof(v));
		ans=sum=0;
		for(i=1;i<=n;i++) {
			sum+=d[i];
			k=max(sum+v[i]-(a[i]-1),0ll);
			ans+=max(0ll,a[i]-1-sum-v[i]);
			d[i+2]++,d[min(1ll*n+1,i+a[i]+1)]--;
			v[i+1]+=k;
		}
		printf("%lld\n",ans);
	}
}