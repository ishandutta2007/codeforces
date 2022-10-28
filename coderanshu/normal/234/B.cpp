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
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long n,k;
	ifstream i;
	ofstream o;
	i.open("input.txt");
	long num;
	i>>n;i>>k;
	vector<pair<long,long>> v;
	for(auto j=0;j<n;j++)
	{
		i>>num;
		v.pb({num,j+1});
	}
	sort(all(v));
	i.close();
	o.open("output.txt");
	o<<v[n-k].F<<endl;
	for(auto j=n-1;j>=n-k;j--)
		o<<v[j].S<<" ";
	o.close();

	return 0;
}