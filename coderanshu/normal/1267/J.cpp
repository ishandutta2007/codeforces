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

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,i,num,k,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		map<int,int> m;
		vector<int> v;
		for(i=0;i<n;++i)
		{
			cin>>num;
			m[num]++;
		}
		for(auto j:m)v.pb(j.S);
		sort(all(v));
		int sz=v.size();
		k=v[0];int ans=n;
		for(i=1;i<=k+1;++i)
		{
			int temp=0;bool check=false;
			for(int j=0;j<sz;++j)
			{
				int z=v[j]/i+(v[j]%i!=0);
				if((i-1)*z<=v[j] && i*z>=v[j])
					temp+=z;
				else
					{check=true;break;}
			}
			if(!check)ans=min(ans,temp);
		}
		cout<<ans<<endl;
		m.clear();v.clear();
	}
	return 0;
}