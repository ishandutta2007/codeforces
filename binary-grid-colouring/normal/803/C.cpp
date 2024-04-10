#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n , k;
	cin>>n>>k;
	if(k>1000000)return 0*puts("-1");
	
	ll ans = -1;
	ll maxx =k*(k+1)/2;
	for(ll i=1;i*i<=n;i++){
		
		if(n%i==0)
		{
			ll x = n/i;
			if(x>=maxx){
				ans=max(ans,i);
			}
			if(i>=maxx){
				ans=max(ans,x);
			}
		}
		
	}
	ll sum=0;
	if(ans<=0)return 0*puts("-1");
	else
	{
		for(int i=1;i<k;i++){
			cout<<i*ans<<" ";
			sum+=i*ans;
		}
		cout<<n-sum<<endl;
	}
	return 0;
}