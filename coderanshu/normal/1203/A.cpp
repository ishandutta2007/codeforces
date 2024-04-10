#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define rep(i,a,b) for(i=a;i<b;i++)
#define F first
#define S second
#define pi 3.1415926536

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],in,i;
		for(auto i=0;i<n;i++)
		{
			cin>>a[i];
			if(a[i]==1)in=i;
		}
		bool ans1,ans2;
		ans1=ans2=true;
		for(i=in+1;i<n;i++)
		{
			if(a[i]-a[i-1]!=1){ans1=false;break;}
		}
		if(ans1)
		{
			for(i=in-1;i>=0;i--)
			{
				if(i==in-1 && a[i]!=n ){ans1=false;break;}
				else if(a[i+1]-a[i]!=1 && i<in-1){ans1=false;break;}
			}
		}
		for(i=in+1;i<n;i++)
		{
			if(i==in+1 && a[i]!=n){ans2=false;break;}
			else if(a[i-1]-a[i]!=1 && i>in+1){ans2=false;break;}
		}
		if(ans2)
		{
			for(i=in-1;i>=0;i--)
			{
				if(a[i]-a[i+1]!=1){ans2=false;break;}
			}
		}
		if(ans1 || ans2)
			cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}