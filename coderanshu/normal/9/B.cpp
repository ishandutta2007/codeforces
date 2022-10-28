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
int xu,yu;
double distance(int k)
{
	return sqrt(((double)k-xu)*((double)k-xu)+((double)yu)*yu);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,i;
	double vb,vs;
	cin>>n>>vb>>vs;
	vector<int> v(n);
	for(i=0;i<n;++i)
	{
		cin>>v[i];
	}
	cin>>xu>>yu;
	double time=1e15,in=-1,ud=1e15;
	for(i=1;i<n;++i)
	{
		double x=distance(v[i])/vs;
		double y=(double)v[i]/vb;
		if(x+y<time)
		{
			in=i;time=x+y;ud=x;
		}
		else if(x+y==time && x<ud)
		{
			in=i;time=x+y;ud=x;
		}
	}
	cout<<in+1;
	return 0;
}