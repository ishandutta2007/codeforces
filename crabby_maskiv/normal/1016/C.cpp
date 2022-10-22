#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a[2][N];
ll s[2][N];
ll sum[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[0][i];
	for(i=1;i<=n;i++) cin>>a[1][i];
	ll ans1=0,ans2=0;
	for(i=n;i;i--){
		ans1+=(i-1)*a[0][i];
		ans1+=(n-i+n)*a[1][i];
		s[0][i]=ans1;
	}
	ans1=0;
	for(i=n;i;i--){
		ans1+=(n-i+n)*a[0][i];
		ans1+=(i-1)*a[1][i];
		s[1][i]=ans1;
	}
	for(i=n;i;i--) sum[i]=sum[i+1]+a[0][i]+a[1][i];
	ll ans=s[0][1];
	for(i=1;i<=n;i++){
		if(i&1){
			ans2+=((i-1)*2)*a[0][i];
			ans2+=((i-1)*2+1)*a[1][i];
		}
		else{
			ans2+=((i-1)*2+1)*a[0][i];
			ans2+=((i-1)*2)*a[1][i];
		}
		ans=max(ans,ans2+i*sum[i+1]+s[i&1][i+1]);
	}
	cout<<ans;
	return 0;
}