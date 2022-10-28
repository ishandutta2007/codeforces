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
#define INF 2e9
#define endl "\n"

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
	ll m,k,i;
	vector<ll> v;
	cin>>m;
	k=sqrt(m);
	if(k*k==m)k--;
	for(i=1;i<=k;i++)
	{
		if(m%i==0)
		{
			v.pb((m/i)*(i+m)/2+m/i-m);
			v.pb(i*(m+m/i)/2+i-m);
		}
	}
	k++;
	if(k*k==m)
		v.pb((k*(k+m)/2)+k-m);
	sort(all(v));
	for(auto j:v)cout<<j<<" ";
	return 0;
}