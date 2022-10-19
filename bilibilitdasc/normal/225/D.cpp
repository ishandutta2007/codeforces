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
//ios_base::sync_with_stdio(false);cin
struct pos{
	int r,c,t;
};
char a[20][20];
int dp[20][20][1<<16];
int in[20][20];
const int mr[4]={0,1,0,-1},mc[4]={1,0,-1,0};
int dir(int a,int b,int c,int d)
{
	rep(o,4) if(a+mr[o]==c&&b+mc[o]==d) return o;
}
int n,m,l,tr,tc,ar[9],ac[9];
int main()
{
	cin>>n>>m;
	rep(i,n) rep(j,m)
	{
		cin>>a[i][j];
		if(isdigit(a[i][j]))
		{
			ar[a[i][j]-'1']=i;
			ac[a[i][j]-'1']=j;
			l=max(l,a[i][j]-'0');
		}
		if(a[i][j]=='@') tr=i,tc=j;
	}
	int sr=ar[0],sc=ac[0],st=0,mask=(1<<(2*(l-1)))-1,tag=0;
	for(int i=1;i<l;i++)
	{
		st|=dir(ar[i],ac[i],ar[i-1],ac[i-1])<<(i*2-2);
	}
	queue<pos> q;
	q.push((pos){sr,sc,st});
	memset(dp,-1,sizeof(dp));
	dp[sr][sc][st]=0;
	while(!q.empty())
	{
		int r=q.front().r;
		int c=q.front().c;
		int t=q.front().t;
		q.pop();
		in[r][c]=++tag;
		for(int i=2,dr=r,dc=c,dt=t;i<l;i++)
		{
			int d=(dt&3)^2;
			dr+=mr[d];
			dc+=mc[d];
			dt>>=2;
			in[dr][dc]=tag;
		}
		rep(i,4)
		{
			int dr=r+mr[i],dc=c+mc[i],dt=((t<<2)&mask)|i;
			if(dr<0||dc<0||dr>=n||dc>=m) continue;
			if(a[dr][dc]=='#'||in[dr][dc]==tag||~dp[dr][dc][dt]) continue;
			dp[dr][dc][dt]=dp[r][c][t]+1;
			q.push((pos){dr,dc,dt});
		}
	}
	int ans=2e9;
	rep(i,1<<16) if(~dp[tr][tc][i]) ans=min(ans,dp[tr][tc][i]);
	cout<<((ans==2e9)?-1:ans)<<endl;
	return 0;
}