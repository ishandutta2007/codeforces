#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int T,n,m,a1[MAXN],a2[MAXN],tot1,tot2,a[MAXN],b[MAXN];
ll sum1[MAXN],sum2[MAXN]; 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		tot1=tot2=0;
		rep(i,1,n){
			scanf("%d",&a[i]);
		}
		rep(i,1,n){
			scanf("%d",&b[i]);
			if(b[i]==1)a1[++tot1]=a[i];
			else a2[++tot2]=a[i];
		}
		sort(a1+1,a1+1+tot1,greater<int>());
		sort(a2+1,a2+1+tot2,greater<int>());
		rep(i,1,tot1)sum1[i]=sum1[i-1]+a1[i];
		rep(i,1,tot2)sum2[i]=sum2[i-1]+a2[i];
		if(sum1[tot1]+sum2[tot2]<m){
			printf("-1\n");continue;
		}
		int ans=1e9;
		rep(i,0,tot1){
			if(sum1[i]>=m){
				ans=min(ans,(int)i);
				break;
			}
			ll rest=m-sum1[i];
			int pos=lower_bound(sum2+1,sum2+1+tot2,rest)-sum2;
			if(pos==tot2+1)continue;
			ans=min(ans,(int)i+pos*2);
		}
		printf("%d\n",ans);
	}
	return 0;
}