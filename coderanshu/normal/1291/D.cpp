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
int counter[200005][26];
string s;
bool check(int l,int r)
{
	int ans=0;
	for(int k=0;k<26;++k)
	{
		if((counter[r][k]-counter[l-1][k])>0)++ans;
	}
	if(ans==2 && s[r-1]==s[l-1])return true;
	if(ans>1)return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q,l,r,i,n,j,k;
	cin>>s>>q;
	n=s.length();
	for(i=0;i<26;++i)
	{
		counter[0][i]=0;
	}
	for(i=0;i<n;++i)
	{
		for(j=0;j<26;++j)
			counter[i+1][j]=counter[i][j];
		counter[i+1][s[i]-'a']++;
	}
	while(q--)
	{
		cin>>l>>r;
		if(l==r)
		{
			cout<<"Yes\n";
			continue;
		}
		if(check(l,r))
			cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}