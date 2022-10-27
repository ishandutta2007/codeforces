#include <bits/stdc++.h>
#ifdef LOCAL
#include "txm/debug.h"
#endif
#define int long long
using namespace std;
using ll=long long;
const int N=200005;
int n,a[N];
void solve()
{
	cin>>n;
	if(n==3) {cout<<"2 1 3\n"; return;}
	bool bj=0;
	if(n%2) n--,bj=1;
	for(int i=1;i<=n;i+=2) a[i]=i/2+1;
	for(int i=2;i<=n;i+=2) a[i]=i/2;
	if(n%4==0)
	{
		for(int i=2;i<=n;i+=2) a[i]|=(1<<30);
	}
	else
	{
		for(int i=2;i<n;i+=2) a[i]|=(1<<30);
		for(int i=n;i>=4;i-=2) a[i]|=(1<<29);
	}
	if(bj) a[++n]=0;
	for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}