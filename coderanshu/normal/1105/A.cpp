#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007LL
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
#define llevel 20
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
int _runtimeTerror_()
{
	int n,i;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];
	int anst=-1,ansval=1e9;
	for(int t=1;t<=100;++t)
	{
		int calc=0;
		for(int i=0;i<n;++i)
			calc+=abs(t-v[i])-(abs(t-v[i])>0);
		if(calc<ansval)
		{
			ansval=calc;anst=t;
		}
	}
	cout<<anst<<" "<<ansval;
	return 0;	
}

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

	int TESTS=1;
	//cin>>TESTS;
	while(TESTS--)
		_runtimeTerror_();
	return 0;
}