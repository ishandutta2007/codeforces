#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
ll a[N],b[N];
inline ll f(ll x){
	return (x<0?-x:x);
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=m;i++) cin>>b[i];
	ll g=0;
	for(i=2;i<=n;i++) g=__gcd(f(a[i]-a[i-1]),g);
	for(i=1;i<=m;i++) cout<<__gcd(a[1]+b[i],g)<<" ";
	return 0;
}