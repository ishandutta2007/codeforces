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
		ll n;
		cin>>n;
		if (n&1) {cout<<"2\n";continue;}
		ll x=1ll<<__lg(n&-n);
		if (n==x) cout<<"-1\n"; else
		{
			cout<<min(x*2,n/x)<<'\n';
		}
	}
}