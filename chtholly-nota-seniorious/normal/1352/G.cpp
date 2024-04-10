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
		if (n<=3) {cout<<"-1\n";continue;}
		for (i=n-(n%2^1);i>3;i-=2) cout<<i<<' ';
		cout<<"3 1 4 2";
		for (i=6;i<=n;i+=2) cout<<' '<<i;
		cout<<'\n';
	}
}