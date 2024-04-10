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
	
	int a,b;
	cin>>a>>b;
	if(b-a==1)
		cout<<a<<" "<<b;
	else if(b==a)
		cout<<10*a<<" "<<10*a+1;
	else if(a==9 && b==1)cout<<a<<" "<<10;
	else cout<<-1;
	return 0;

}