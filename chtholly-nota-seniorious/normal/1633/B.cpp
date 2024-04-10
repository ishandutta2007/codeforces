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
		int n,m,i,j;
		int a[2]={0,0};
		string s;
		cin>>s;
		for (auto c:s) ++a[c-'0'];
		if (a[0]==a[1]) cout<<(a[0]-1)<<'\n'; else cout<<min(a[0],a[1])<<'\n';
	}
}