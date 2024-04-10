#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m; 
char a[N];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	cin>>(a+1);
	for(i=n-1;i;i--)
		if(a[i]!=a[i+1]) break;
	for(j=2;j<=n;j++)
		if(a[j]!=a[j-1]) break;
	if(i<j-1){
		cout<<(ll(n)*(n+1)/2)%mod;
		return 0;
	}
	ll l1=j-1,l2=n-i;
	if(a[1]==a[n]){
		cout<<(l1+1)*(l2+1)%mod;
		return 0;
	}
	cout<<(l1+l2+1)%mod;
	return 0;
}