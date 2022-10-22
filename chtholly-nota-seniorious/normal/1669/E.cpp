#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int cnt[26][2];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		memset(cnt,0,sizeof cnt);
		int n,m,i,j;
		ll r=0;
		cin>>n;
		r=(ll)n*(n-1)/2;
		vector<string> a(n);
		for (auto &x:a) cin>>x;
		//for (auto x:a) cout<<x<<'\n';
		map<string,int> cc;
		int cntt=0;
		for (auto &x:a)
		{
			x[0]-='a';x[1]-='a';
			r-=cntt-(cnt[x[0]][0]+cnt[x[1]][1]-cc[x]);
			++cntt;
			++cnt[x[0]][0];
			++cnt[x[1]][1];
			++cc[x];
		}
		for (auto [x,y]:cc) r-=(ll)y*(y-1)/2;
		cout<<r<<'\n';
	}
}