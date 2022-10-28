#pragma GCC optimize("Ofast")

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,i,num;
	vector<int> v[2];
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>num;
		v[num%2].pb(num);
	}
	sort(all(v[0]),greater<int>());sort(all(v[1]),greater<int>());
	int z=min(v[0].size(),v[1].size());
	int ans=0;
	for(i=z+1;i<v[0].size();i++)ans+=v[0][i];
	for(i=z+1;i<v[1].size();i++)ans+=v[1][i];
		cout<<ans;
	return 0;

}