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
		int n,m,i,j,b=0;
		cin>>n>>m;set<int> s;
		for (i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			if (s.count(x-m)||s.count(x+m)) b=1;
			s.insert(x);
		}
		if (b) cout<<"YES\n"; else cout<<"NO\n";
	}
}