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

	ll tests,n,i;
	cin>>tests;
	while(tests--)
	{
		cin>>n;
		vector<ll> a(n),v;set<ll> s;ll k=1e10,l=-1,m1=-1;
		for(i=0;i<n;++i)cin>>a[i];
		for(i=0;i<n;++i)
		{
			if(a[i]==-1)
			{
				if(i>0 && a[i-1]!=-1)
					{
						k=min(k,a[i-1]);l=max(l,a[i-1]);}
				if(i<n-1 && a[i+1]!=-1)
				{
					k=min(k,a[i+1]);l=max(l,a[i+1]);
				}
			}
			
		}
		ll sum=0;
		if(l==-1)sum=0;
		else
		sum=(l+k)/2;
		//sum=(*s.begin()+*(--s.end()))/2;
		
		for(i=0;i<n;++i)
		{
			if(a[i]==-1)a[i]=sum;
			if(i>0)
			m1=max(m1,abs(a[i]-a[i-1]));
		}
		cout<<m1<<" ";
		 cout<<sum<<endl;
	}
	return 0;
}