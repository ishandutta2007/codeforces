#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 500005
#define maxp 61
#define ll long long
#define mo 1000000007
using namespace std;

int T,n,i,j,k;
ll a[maxn],c[61];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++) {
			scanf("%lld",&a[i]);
			for(j=0;j<maxp;j++) if (a[i]>>j&1)
				c[j]++;
		}
		ll ans=0;
		for(i=1;i<=n;i++){
			ll s1=0,s2=0;
			for(j=0;j<maxp;j++) if (a[i]>>j&1){
				s1+=(1ll<<j)%mo*c[j];
				s2+=(1ll<<j)%mo*n;
			} else s2+=(1ll<<j)%mo*c[j];
			s1%=mo,s2%=mo,(ans+=s1*s2)%=mo;
		}
		printf("%lld\n",ans);
	}
}