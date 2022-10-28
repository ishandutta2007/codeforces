#pragma GCC optimize("Ofast")

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	ll n,i,num;
	cin>>n;
	map<ll,ll> m;
	for(i=0;i<n;i++)
	{
		cin>>num;
		m[num]++;
	}
	ll ans=0,act=0;
	for(auto i=m.begin();i!=m.end();i++)
	{
		ans=i->S+(m.count(i->F+1)?m[i->F+1]:0)+(m.count(i->F+2)?m[i->F+2]:0)+(m.count(i->F+3)?m[i->F+3]:0)+(m.count(i->F+4)?m[i->F+4]:0)+(m.count(i->F+5)?m[i->F+5]:0);
		act=max(ans,act);
	}
	cout<<act;
	return 0;
}