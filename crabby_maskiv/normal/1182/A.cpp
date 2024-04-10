#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	if(n&1){
		cout<<0;
		return 0;
	}
	else{
		ll ans=1;
		for(i=1;i<=n;i+=2) ans*=2;
		cout<<ans;
	}
	
	return 0;
}