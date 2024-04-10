#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
typedef double db;
using namespace std;
const int MAXN=2e5+10;
int T,n,m,k,u[MAXN],v[MAXN],cnt1[MAXN],cnt2[MAXN];
ll ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n)cnt1[i]=0;
		rep(i,1,m)cnt2[i]=0;
		ans=0;
		rep(i,1,k){
			scanf("%d",&u[i]);
			cnt1[u[i]]++;
		}
		rep(i,1,k){
			scanf("%d",&v[i]);
			cnt2[v[i]]++;
		}
		rep(i,1,k){
			ans+=(k-cnt1[u[i]]-cnt2[v[i]]+1);
		}
		printf("%lld\n",ans/2);
	} 
	return 0;
}