#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
ll n,m,l,r,ans;
ll BinaryPow(ll a,ll b) //a^b
{
	ll s=1;
	while(b)
	{
		if(b&1) s=s*a%MOD;
		a=a*a%MOD,b>>=1; 
	} 
	return s;
}
int main()
{
	cin>>n>>m>>l>>r;
	if(n%2&&m%2) ans=BinaryPow(r-l+1,n*m);
	else if((r-l+1)%2) ans=((BinaryPow(r-l+1,n*m)+1)*BinaryPow(2,MOD-2))%MOD;
	else ans=(BinaryPow(r-l+1,n*m)*BinaryPow(2,MOD-2))%MOD;
	cout<<ans<<endl;
	return 0;
}