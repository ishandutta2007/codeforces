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
	int n,k,i;
	cin>>n>>k;
	vector<int> a(n);
	for(i=0;i<n;++i)cin>>a[i];
	if(a[k-1]==0)
	{
		--k;
		while(k>=0 && a[k]==0 )--k;
		cout<<k+1;
	}
	else
	{
		int z=a[k-1];
		while(k<n && a[k]==z)++k;
			cout<<k;
	}
	return 0;
}