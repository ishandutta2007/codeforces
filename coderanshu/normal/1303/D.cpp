#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll tests;
	cin>>tests;
	while(tests--)
	{
		ll n,m,i,j,num,sum=0,count;map<ll,ll> mapp;
		cin>>n>>m;
		for(i=0;i<m;++i)
		{
			count=0;
			cin>>num;sum+=num;
			while(num%2==0)
			{
				num/=2;++count;
			}
			mapp[count]++;
		}
		if(sum<n)
		{
			cout<<-1<<endl;continue;
		}
		sum=0;ll ans=0,k;
		for(j=0;j<31;++j)
		{
			if((1<<j)&n)
			{
				if(mapp[j]>0)--mapp[j];
				else if(sum>=power(2,j))
				{
					sum-=power(2,j);
				}
				else
				{
					for(k=j+1;k<31;++k)
					{
						if(mapp[k]>0)
						{
							--mapp[k];ans+=k-j;
							for(ll l=j;l<k;++l)
								mapp[l]++;
							break;
						}
					}
				}
			}
			sum+=mapp[j]*power(2,j);
		}
		cout<<ans<<endl;
	}
	return 0;
}
// greedy approach works very often