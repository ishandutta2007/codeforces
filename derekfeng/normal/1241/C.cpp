#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int gcd(int a,int b){
	if (a%b==0) return b;
	return gcd(b,a%b);
}
bool cmp(int a,int b){
	return a>b; 
} 
int n;
int a[200004];
ll num[200004];
ll k; 
int main(){
	int q;cin>>q;
	while (q--){
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		sort (a+1,a+1+n,cmp);
		for (int i=1;i<=n;i++) num[i]=num[i-1]+a[i];
		int x,az,y,b,now=n+1;cin>>x>>az>>y>>b>>k;
		ll mar=1ll*az*b/gcd(az,b);
		if (x<y) swap(x,y),swap(az,b);
		int yes=1;
		for (int i=1;i<=n && yes;i++){
			ll p1=i/mar,p2=i/az-p1,p3=i/b-p1;
			if (num[p1]*(x+y)/100+(num[p2+p1]-num[p1])*x/100+(num[p1+p2+p3]-num[p2+p1])*y/100>=k){
				cout<<i<<"\n";yes=0;
			}
		}
		if (yes) puts("-1");
	}
}