#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	ll ans=inf;
	for(i=1;i<=n;i++){
		if(i!=n){
			ans=min(ans,min(a[n],a[i])/(n-i));
		}
		if(i!=1){
			ans=min(ans,min(a[1],a[i])/(i-1));
		}
	}
	cout<<ans;
	return 0;
}