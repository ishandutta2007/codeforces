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
		cin>>n;
		vector<int> a(n+1),sm(n+2),bs(n+2);
		for (i=1;i<=n;i++) cin>>a[i];
		for (i=1;i<=n;i++) sm[i]=sm[i-1]+a[i];
		for (i=n;i;i--) bs[i]=bs[i+1]+a[i];
		map<int,int> s;
		for (i=n+1;i;i--) s[bs[i]]=n+1-i;
		for (i=1;i<=n;i++)
		{
			s.erase(s.find(bs[i]));
			if (s[sm[i]]) r=i+s[sm[i]];
		}
		cout<<r<<'\n';
	}
}