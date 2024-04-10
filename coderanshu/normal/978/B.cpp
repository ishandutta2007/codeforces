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
	
	int n;string s;
	cin>>n>>s;
	int i,j,ans=0;
	for(i=0;i<n;i++)
	{
		if(s[i]=='x')
		{
			j=i;
			while(s[i]=='x' && i<n)i++;
			if(i-j>2)
				ans+=(i-j-2);
		}
	}
	cout<<ans;
	return 0;
}