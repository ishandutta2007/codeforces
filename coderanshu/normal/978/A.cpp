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
	int n,num,i;
	bool vis[1005];
	memf(vis);
	cin>>n;
	vector<int> v;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		
	}
	for(i=n-1;i>=0;i--)
	{
		if(!vis[a[i]])
		{
			v.pb(a[i]);vis[a[i]]=true;
		}
	}
	reverse(all(v));
	cout<<v.size()<<endl;
	for(auto j:v)cout<<j<<" ";
	return 0;
}