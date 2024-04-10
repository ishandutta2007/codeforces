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
//cin
int n,a[105],ans[105];
int p[105];
void build_tree(int l,int r,int pa)
{
	if(l>r) return;
	if(l==r)
	{
		p[a[l]]=pa;
		return;
	}
	int maxind,mx=0;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>mx)
		{
			mx=a[i];
			maxind=i;
		}
	}
	p[mx]=pa;
	build_tree(l,maxind-1,mx);
	build_tree(maxind+1,r,mx);
}
int getans(int root)
{
	if(ans[root]!=-1) return ans[root];
	if(root==n) return ans[root]=0;
	return ans[root]=(1+getans(p[root]));
}
void solve()
{
	memset(ans,-1,sizeof(ans));
	cin>>n;
	rep(i,n) cin>>a[i];
	build_tree(0,n-1,0);
	for(int i=0;i<n;i++) cout<<getans(a[i])<<((i==n-1)?'\n':' ');
}
int t;
int main()
{
	cin>>t;
	while(t--) solve();
	return 0;
}