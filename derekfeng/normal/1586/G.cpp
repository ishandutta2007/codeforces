#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=1e9+7;
pii a[200004];
int n,b[200004],m,bit[400004],dp[200004],ans,lst=1;
bool v[200004];
void upd(int i,int x){
	for(;i;i-=i&-i)bit[i]=(bit[i]+x)%M;
}
int got(int i){
	int ans=0;
	for(;i<=n+n;i+=i&-i)ans=(ans+bit[i])%M;
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].se,&a[i].fi),b[i]=a[i].fi;
	sort(a+1,a+n+1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int x;scanf("%d",&x),x=b[x];
		v[lower_bound(a+1,a+n+1,make_pair(x,0))-a]=1;
	}
	upd(n+n,1);
	for(int i=1;i<=n;i++){
		dp[i]=got(a[i].se);
		upd(a[i].se,dp[i]);
	}
	for(int i=n;i;i--){
		upd(a[i].se,M-dp[i]);
		if(v[i]&&lst<=a[i].se){
			ans=(ans+got(lst))%M;
			lst=a[i].se;
		}
	}
	printf("%d",ans);
}