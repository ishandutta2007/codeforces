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
	
	int n,k,num;
	map<int,int> m;
	cin>>n>>k;
	while(n--)
	{
		cin>>num;
		m[num%k]++;
	}
	int i,ans=0;
	int z=k/2+k%2;
	for(i=1;i<z;i++)
	{
			ans+=2*min(m[i],m[k-i]);
	}
	if(k%2==0)
		ans+=(m[k/2]/2)*2;
	ans+=(m[0]/2)*2;
	cout<<ans;
	return 0;
}