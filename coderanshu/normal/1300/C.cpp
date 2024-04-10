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
int arr[32],ar2[100005][32];
void cvt(ll n,ll i)
{
	int k=0;
	while(n!=0)
	{
		arr[k]+=n%2;
		ar2[i][k]=n%2;++k;
		n/=2;
	}
	return ;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n,in;cin>>n;
	mem0(arr);mem0(ar2);
	ll a[n],i,j,temp;
	for(i=0;i<n;++i)
	{
		cin>>a[i];
		cvt(a[i],i);
	}
	ll ans=-1;
	for(i=0;i<n;++i)
	{
		temp=0;
		for(j=0;j<32;++j)
		{
			if(ar2[i][j]==1 && arr[j]==1)
			{
				temp+=power(2,j);
			}
		}
		if(temp>ans)
		{
			in=i;ans=temp;
		}
	}
	cout<<a[in]<<" ";
	for(i=0;i<n;++i)
	{
		if(i!=in)cout<<a[i]<<" ";
	}
	return 0;
}