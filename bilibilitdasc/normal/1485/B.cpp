#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
int a[100005];
int n,q,k;
int l,r;
void solve()
{
	cin>>l>>r;
	cout<<k+a[r]-a[l]-2*(r-l)-1<<endl;
}
int main()
{
	cin>>n>>q>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(q--) solve();
	return 0;
}