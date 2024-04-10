#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define pb push_back
#define INF 2e16
#define mod 998244353
#define eps 1e-9
#define abs(x) ((x)>=0?(x):-(x))
#define y1 solai
#define fi first
#define se second
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
const ll N=1000100;
ll n,n2,a[N],p[N],s,ans[N],sz,w[N],cur;
vector<ll>v[N];
void dfs(ll x, ll d)
{
	if(d==cur)
		s+=x,ans[++sz]=x;
	w[x]=1;
	for(ll to:v[x])
		if(!w[to])
			dfs(to,d^1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	if(!(n&1))
	{
		cout<<"First"<<endl;
		for(ll j=1;j<=2;j++)
			for(ll i=1;i<=n;i++)
				cout<<i<<" ";
		cout<<endl;
		return 0;
	}
	n2=2*n;
	cout<<"Second"<<endl;
	for(ll i=1;i<=n2;i++)
	{
		cin>>a[i];
		if(p[a[i]])
			v[i].pb(p[a[i]]),
			v[p[a[i]]].pb(i);
		p[a[i]]=i;
	}
	for(ll i=1;i<=n;i++)
		v[i].pb(n+i),v[n+i].pb(i);
	for(cur=0;cur<=1;cur++)
	{
		s=sz=0;
		for(ll i=1;i<=n2;i++)
			w[i]=0;
		for(ll i=1;i<=n2;i++)
			if(!w[i])
				dfs(i,0);
		if(s%n2==0)
		{
			for(ll i=1;i<=sz;i++)
				cout<<ans[i]<<" ";
			cout<<endl;
			return 0;
		}
	}
}