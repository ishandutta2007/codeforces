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
		int n,m,i,j,flg=0;
		string s;
		cin>>n>>s;
		vector<int> p(1,-1);
		for (i=0;i<n;i++) if (s[i]=='W') p.push_back(i);
		p.push_back(n);m=p.size();
		for (i=1;i<m;i++) if (p[i-1]<p[i]-1)
		{
			int c[2]={};
			for (j=p[i-1]+1;j<p[i];j++) c[s[j]=='R']=1;
			if (!(c[0]&&c[1])) flg=1;
		}
		if (flg) cout<<"NO\n"; else cout<<"YES\n";
	}
}