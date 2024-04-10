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
#define INF 

ll power(ll b,ll e,ll m)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b%m,(e-1)/2,m)%m;
	else
		return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0)
		return 1;
	if(e%2)
		return b*power(b*b,(e-1)/2);
	else
		return power(b*b,e/2);
}
vector<int> v;
void insert(char c)
{
	switch(c)
	{
		case '2':v.pb(2);break;
		case '3':v.pb(3);break;
		case '4':v.pb(2);v.pb(2);v.pb(3);break;
		case '5':v.pb(5);break;
		case '6':v.pb(3);v.pb(5);break;
		case '7':v.pb(7);break;
		case '8':v.pb(7);v.pb(2);v.pb(2);v.pb(2);break;
		case '9':v.pb(3);v.pb(3);v.pb(2);v.pb(7);break;
	}
	return ;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char c;
	int n;
	cin>>n;
	for(auto i=0;i<n;i++)
	{
		cin>>c;
		insert(c);
	}
	sort(all(v),greater<int>());
	for(auto j:v)
	{
		cout<<j;
	}
	return 0;
}