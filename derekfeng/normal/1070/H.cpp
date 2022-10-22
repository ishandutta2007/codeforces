//************************
//*  Date: 2018.10.19    *
//*  Problem:            *
//*  Author: xuziyuan    * 
//************************

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++)
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

LL n,q;
map <string,set <LL> > mp;
string s,t;
vector <string> sv;

int main()
{
	LL n,q;
	cin>>n;
	rep(i,n)
	{
		cin>>s;
		sv.pb(s);
		rep(j,s.size())
		{
			for(int k=j;k<s.size();k++)
			{
				t=s.substr(j,k-j+1);
				mp[t].insert(i);
			}
		}
	}
	cin>>q;
	rep(i,q)
	{
		cin>>t;
		cout<<mp[t].size()<<' '<<(mp[t].size()==0 ? "-":sv[*mp[t].begin()])<<endl;
	}
	rt0;
}