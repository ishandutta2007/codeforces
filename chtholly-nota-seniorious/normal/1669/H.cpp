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
		int n,m,i,j,r=0;
		cin>>n>>m;
		vector<int> cnt(31);
		for (i=0;i<n;i++)
		{
			int x;
			cin>>x;
			for (j=0;j<=30;j++) cnt[j]+=x>>j&1;
		}
		for (i=30;i>=0&&m;i--) if (m>=n-cnt[i])
		{
			m-=n-cnt[i];
			cnt[i]=n;
		}
		for (i=30;i>=0;i--) if (cnt[i]==n) r|=1<<i;
		cout<<r<<'\n';
	}
}