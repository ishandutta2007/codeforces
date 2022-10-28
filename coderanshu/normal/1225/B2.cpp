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
	
	int t,i,n,k,d;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>d;
		vector<int> v(n);
		map<int,int> m;
		for(i=0;i<n;i++)cin>>v[i];
		for(i=0;i<d;i++)m[v[i]]++;
		int ans=m.size();
		for(i=d;i<n;i++)
		{
			if(m.count(v[i-d]))
			{
				if(m[v[i-d]]==1)m.erase(v[i-d]);
				else --m[v[i-d]];
			}
			m[v[i]]++;
			int z=m.size();
			ans=min(ans,z);
		}
		cout<<ans<<endl;
		v.clear();
		m.clear();
	}
	return 0;

}