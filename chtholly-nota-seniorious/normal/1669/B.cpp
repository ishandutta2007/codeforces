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
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		map<int,int> cnt;
		while (n--)
		{
			cin>>m;
			++cnt[m];
		}
		i=1;
		for (auto [x,y]:cnt) if (y>=3) {cout<<x<<'\n',i=0;break;}
		if (i) cout<<"-1\n";
	}
}