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
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s,t;
	cin>>s;
	t=s;
	int i;
	int count[26];
	mem0(count);
	for(i=0;s[i];++i)
		count[s[i]-'a']++;
	vector<int> v;
	for(i=0;i<26;++i)
	{
		if(count[i]%2)v.pb(i);
		else count[i]/=2;
	}
	char c;
	if(v.size()%2)
		{
			count[v[v.size()/2]]/=2;
			c=(char)('a'+v[v.size()/2]);
		}
	int sz=v.size()/2;
	for(i=0;i<sz;++i)
	{
		count[v[i]]/=2;count[v[i]]++;
		count[v[v.size()-1-i]]/=2;
	}
	s.clear();int j;
	for(i=0;i<26;++i)
	{
		for(j=0;j<count[i];++j)s+=(char)('a'+i);
	}
	cout<<s;
	if(t.length()%2)cout<<c;
	reverse(all(s));cout<<s;
	return 0;
}