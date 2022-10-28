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
	int n;
	cin>>n;
	set<int> s;
	int i,num;
	vector<int> ans;
	cin>>num;
	s.insert(1);
	for(i=0;i<n-1;++i)
	{
		cin>>num;
		if(num==1)
		{
			ans.pb(*s.rbegin());
			s.clear();s.insert(1);
		}
		else s.insert(num);
	}
	ans.pb(*s.rbegin());
	cout<<ans.size()<<endl;
	for(auto j:ans)cout<<j<<" ";
	return 0;
}