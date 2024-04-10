#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define ll long long 
using namespace std;

int n,i,j,k,a[maxn];
ll ans;

int main(){
	int T;	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		ans=a[n];
		ll sum=0;
		for(i=1;i<=n;i++){
			ans-=1ll*a[i]*(i-1)-sum;
			sum+=a[i];
		}
		printf("%lld\n",ans);	
	}
}