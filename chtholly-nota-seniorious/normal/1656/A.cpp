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
		vector<pair<int,int>> a(n);
		for (i=0;i<n;i++) cin>>a[i].first,a[i].second=i+1;
		sort(all(a));
		cout<<a[0].second<<' '<<a[n-1].second<<'\n';
	}
}