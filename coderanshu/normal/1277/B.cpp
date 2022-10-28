#include<bits/stdc++.h>
using namespace std ;

#define modulo 1000000007
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(i=a;i<b;i++)

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e==1)
		return b;
	if(e%2==0)
		return power(b*b%m,e/2,m);
	else
		return b*power(b*b%m,(e-1)/2,m)%m;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<ll ,ll > m;
	ll t,n,i,ans,count,num;
	cin>>t;
	while(t--)
	{
		m.clear();
		cin>>n;
		ans=0;
		for(i=0;i<n;i++)
		{
			cin>>num;
			count=0;
			if(num%2==0)
			{
				while(num%2==0)
				{
					count++;
					num/=2;
				}
				m[num]=max(m[num],count);
			}
		}
		for(auto j:m)
		{
			ans+=j.second;
		}
		cout<<ans<<"\n";

	}
	return 0;
}