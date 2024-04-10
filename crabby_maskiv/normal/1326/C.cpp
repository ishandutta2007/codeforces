#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;
int n,m;
int a[N];
int main(){
	int i,j;
	cin>>n>>m;
	cout<<ll(m)*(n-m+1+n)/2<<" ";
	ll ans=1;int pre=0;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>n-m){
			if(pre) ans=ans*(i-pre)%mod;
			pre=i;
		}
	}
	cout<<ans;
	return 0;
}