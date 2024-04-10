#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll a[N],s[N];
inline ll f(ll t){
	int p=lower_bound(a+1,a+n+1,-t)-a;
	if(p==1) return (s[n]-s[1]+(n-1)*t)*(a[1]+t)-(n-1)*t*t;
	if(p>n) return (s[n-1]+(n-1)*t)*(a[n]+t)-(n-1)*t*t;
	return (s[p-1]-s[1]+(p-2)*t)*(a[n]+t)+(s[n-1]-s[p-1]+(n-p)*t)*(a[1]+t)+(a[1]+t)*(a[n]+t)-(n-1)*t*t;
}
void solve(){
	int i;
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int l=-1e6,r=1e6;
	while(l<r){
		int mid=l+r>>1;
		ll f1=f(mid),f2=f(mid+1);
		if(f1==f2){
			cout<<f1<<endl;
			return;
		}
		if(f1<f2) l=mid+1;
		else r=mid;
	}
	ll f1=f(l),f2=f(l+1),f3=f(l-1);
	if(f1>=f2&&f1>=f3) cout<<f1<<endl;
	else cout<<"INF"<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		solve();
		for(i=1;i<=n;i++) a[i]=s[i]=0;
	}
	return 0;
}