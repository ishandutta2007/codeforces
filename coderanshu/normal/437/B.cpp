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
#define PI 3.1415926536

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

	ll a[20],take[20],i,j,sum,limit,count,max_count,temp;
	vector<ll> v[20];
	mem0(a);
	mem0(take);
	cin>>sum>>limit;
	max_count=0;
	for(i=1;i<=limit;i++)
	{
		j=i;
		count=0;
		if(j%2==0)
		{
			while(j%2==0)
			{
				j/=2;count++;
			}
		}
		max_count=max(count,max_count);
		a[count]++;
		v[count].pb(i);
	}
	for(i=max_count;i>=0;i--)
	{
		temp=power(2,i);
		if(temp*a[i]>=sum)
		{
			take[i]=sum/temp;
			sum=sum%temp;
		}
		else
		{
			sum-=a[i]*temp;
			take[i]=a[i];
		}
	}
	ll check=0;
	for(i=0;i<=max_count;i++)check+=take[i];
	if(sum>0)
		cout<<-1;
	else
	{
		cout<<check<<endl;
		for(i=0;i<=max_count;i++)
		{
			for(j=0;j<take[i];j++)
				cout<<v[i][j]<<" ";
		}
	}
	
	return 0;
}