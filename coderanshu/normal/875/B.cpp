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
	
	int n;
	cin>>n;
	int last=n;
	int ans=1,num,i;
	bool vis[300005];
	memf(vis);
	cout<<ans<<" ";
	for(i=0;i<n;i++)
	{
		cin>>num;
		vis[num]=true;
		ans++;
		if(num==last)
		{
			while(vis[last])
			{
				last--;ans--;
			}
		}
		cout<<ans<<" ";
	}

	return 0;

}