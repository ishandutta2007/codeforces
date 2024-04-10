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
int a[N];
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j;
		cin>>n;
		for (i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		n=unique(a+1,a+n+1)-a-1;
		if (a[1]>1||a[1]==0&&(n==1||a[2]>1)) {cout<<"YES\n";continue;}
		int x=0;
		for (i=2;i<=n;i++) if (a[i]==a[i-1]+1) break;
		if (i<=n) cout<<"NO\n"; else cout<<"YES\n";
	}
}