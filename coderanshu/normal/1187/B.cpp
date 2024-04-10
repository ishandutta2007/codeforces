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
long f[200005][26],f2[26];
bool check(ll l)
{
	for(auto i=0;i<26;i++)
	{
		if(f[l-1][i]<f2[i])
			return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	ll n,m,be,en,i,j;
	cin>>n>>s>>m;
	f[0][s[0]-'a']++;
	for(i=1;i<n;i++)
	{
		for(j=0;j<26;j++)
			f[i][j]=f[i-1][j];

		f[i][s[i]-'a']++;
	}
	while(m--)
	{
		cin>>t;
		j=0;
		mem0(f2);
		for(i=0;t[i];i++)
			f2[t[i]-'a']++;
		be=1;en=n;
		while(be<=en)
		{
			ll mid=(be+en)>>1;
			if(check(mid))
				en=mid-1;
			else
				be=mid+1;
		}
		cout<<be<<endl;
	}

	return 0;
}