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
bool ed[8002];
int a[8002],s[8002];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,r=0;
		cin>>n;
		fill_n(ed,n+1,0);
		for (i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
		for (i=0;i<=n;i++) for (j=i+2;j<=n;j++) if (s[j]-s[i]<=n) ed[s[j]-s[i]]=1;
		for (i=1;i<=n;i++) r+=ed[a[i]];
		cout<<r<<'\n';
	}
}