/*********************
*  Author: xuziyuan  * 
*********************/

#include <bits/stdc++.h>

#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define replet(c) for(char c='a';c<='z';c++) 
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
#define sqr(a) ((a)*(a))

using namespace std;

const LL MOD=1e9+7;

int n,m,a[100010],dp[100010];
pii b[100010];

int main()
{
	cin>>n>>m;
	rep(i,n) scanf("%d",&a[i]);
	rep(i,m) scanf("%d%d",&b[i].fi,&b[i].se);
	sort(b,b+m);
	dp[0]=b[0].se;
	repn(i,m-1) dp[i]=dp[i-1]+b[i].se;
	rep(i,n)
	{
		int pos=lower_bound(b,b+m,mpr(a[i]+1,0))-b-1;
		cout<<dp[pos]<<' ';
	}
	cout<<endl;
	rt0;
}