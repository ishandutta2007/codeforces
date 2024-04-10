#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll lcm(ll a,ll b){
	return a*b/__gcd(a,b);
}
int T,n;
ll a[100004];
void solve(){
	scanf("%d",&n);
	ll cur=1;
	bool ok=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(cur<=2e9)cur=lcm(cur,i+1);
		ll A=a[i];
		if(A%cur==0)ok=0;
	}
	if(ok)puts("YES");
	else puts("NO");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
}