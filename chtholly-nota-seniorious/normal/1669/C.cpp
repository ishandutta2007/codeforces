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
		int c[2][2]={};
		cin>>n;
		for (i=0;i<n;i++)
		{
			cin>>m;
			c[m&1][i&1]=1;
		}
		if (c[0][0]&&c[1][0]||c[0][1]&&c[1][1]) cout<<"NO\n"; else cout<<"YES\n";
	}
}