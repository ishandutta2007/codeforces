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
		cin>>n>>m;
		vector<string> a(n);
		vector<int> dn(m,n-1);
		for (auto &s:a) cin>>s;
		for (i=n-1;i>=0;i--)
		{
			for (j=0;j<m;j++) if (a[i][j]=='*')
			{
				swap(a[i][j],a[dn[j]][j]);
				--dn[j];
			}
			for (j=0;j<m;j++) if (a[i][j]!='.') dn[j]=i-1;
		}
		for (auto &s:a) cout<<s<<'\n';
	//	cout<<'\n';
	}
}