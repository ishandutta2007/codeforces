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
#define INF 

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
ll n,p[500005],r[500005],size[500005];
void initialize()
{
	for(auto i=1;i<=n;i++)
	{
		r[i]=0;p[i]=i;size[i]=1;
	}
}
ll parent(ll i)
{
	if(i==p[i])return i;
	return p[i]=parent(p[i]);
}
void union_(ll x,ll y)
{
	ll px=parent(x);
	ll py=parent(y);
	if(r[px]>r[py])
	{
		p[py]=px;
		size[px]=size[py]+size[px];
	}
	else
	{
		p[px]=py;
		size[py]=size[py]+size[px];
	}
	if(r[px]==r[py])
		r[px]++;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll m,num,num2,k;
	cin>>n>>m;
	initialize();
	while(m--)
	{
		cin>>k;
		if(k==0)continue;
		cin>>num;
		k--;
		while(k--)
		{
			cin>>num2;
			if(parent(num)!=parent(num2))
				union_(num,num2);
		}
	}
	for(auto i=1;i<=n;i++)
		cout<<size[parent(i)]<<" ";
	return 0;
}