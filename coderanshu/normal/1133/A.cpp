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
	string s1,s2;
	cin>>s1>>s2;
	int t1=stoi(s1.substr(0,2));
	int t2=stoi(s2.substr(0,2));
	int m1=stoi(s1.substr(3,2));
	int m2=stoi(s2.substr(3,2));
	int check=(t2-t1)*60+m2-m1;
	check/=2;
	t1+=(m1+check)/60;
	m1=(m1+check)%60;
	if(t1<10)cout<<0;
	cout<<t1<<":";
	if(m1<10)cout<<0;
	cout<<m1;
	return 0;
}