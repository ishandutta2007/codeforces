#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m; 
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	ll x;cin>>x;
	if(!(x&1)) cout<<x/2;
	else{
		ll k;
		for(k=2;k*k<=x;k++){
			if(x%k==0) break;
		}
		if(k*k>x) cout<<1;
		else cout<<(x-k)/2+1;
	}
	return 0;
}