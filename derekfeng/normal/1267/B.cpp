/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define fi first
#define se second
#define pb push_back
#define mpr make_pair

using namespace std;

const LL MOD=1e9+7;

string s;
vector <pii> v;

int main()
{
	cin>>s;
	int i=0;
	while(i<s.size())
	{
		int p=i;
		while(p<s.size()&&s[i]==s[p]) p++;
		v.pb(mpr(s[i],p-i));
		i=p;
	}
	if(v.size()%2==0)
	{
		puts("0");
		return 0;
	}
	rep(i,v.size()/2)
	{
		if(v[i].fi!=v[v.size()-i-1].fi||v[i].se+v[v.size()-i-1].se<3)
		{
			puts("0");
			return 0;
		}
	}
	if(v[v.size()/2].se>=2) cout<<v[v.size()/2].se+1<<endl;
	else puts("0");
	return 0;
}