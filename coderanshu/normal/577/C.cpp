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
int n;
vector<bool> vis(1005,false);
void seive()
{
	int k=sqrt(n),i,j;
	for(i=2;i<=k;i++)
	{
		for(j=i*i;j<=n;j+=i)
		{
			vis[j]=true;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	seive();
	vector<int> v;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			for(int k=i;k<=n;k*=i)
				v.pb(k);
		}
	}
	cout<<v.size()<<endl;
	for(auto j:v)cout<<j<<" ";
	return 0;
}