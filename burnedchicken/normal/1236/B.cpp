#include <bits/stdc++.h>
 
#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

ll Pow(ll a, ll b, ll mod){
	ll y=1;
	ll z=a%mod;
	while(b>0){
		if(b%2==1){
			y=(y*z)%mod;
			b--;
		}
		b=b/2;
		z=(z*z)%mod;
	}
	return y;
}

int main(){
	ll m,n,ans;
	cin >> n >> m;
	ll t=1e9+7;
	//(2^m-1)^n;
	ans=Pow(2,m,t)-1;
	ans=Pow(ans,n,t);
	cout << ans << endl;
	return 0;
}