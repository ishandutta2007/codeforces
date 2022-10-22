#include <bits/stdc++.h>
using namespace std;
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...); 1;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+2;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T;
	while (T--)
	{
		int n,m,i,j,k;
		ll h1,d1,h2,d2,w,a;
		cin>>h1>>d1>>h2>>d2>>k>>w>>a;
		for (i=0;i<=k;i++)
		{
			ll n=d1+i*w;
			__int128 t=(h2+n-1)/(n)-1;
			t*=d2;
			if (t<h1+(k-i)*a) break;
		}
		if (i<=k) cout<<"YES\n"; else cout<<"NO\n";
	}
}