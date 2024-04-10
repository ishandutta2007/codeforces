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
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,m,cnt;
bool c[55][55];
bool vi[55][55];
void dfs(int a,int b)
{
	if(vi[a][b]) return ;
	vi[a][b]=1;
	rep(i,4)
	{
		int x=a+dx[i],y=b+dy[i];
		if(x<0||x>=n||y<0||y>=m) continue;
		if(c[a][b]==0) continue;
		dfs(x,y);
	}
}
bool is_one(int a,int b)
{
	if(!c[a][b]) return 0;
	rep(i,n) rep(j,m) vi[i][j]=0;
	c[a][b]=0;
	int xx,yy;
	rep(i,n) rep(j,m) if(c[i][j])
	{
		xx=i;yy=j;
	}
	dfs(xx,yy);
	c[a][b]=1;
	rep(i,n) rep(j,m)
	{
		if(c[i][j]==1&&vi[i][j]==0)
		return 1;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n) rep(j,m)
	{
		char ch;
		cin>>ch;
		c[i][j]=(ch=='#');
		vi[i][j]=(ch=='.');
		cnt+=(ch=='#');
	}
	if(cnt<=2)
	{
		cout<<"-1\n";
		return 0;
	}
	rep(i,n) rep(j,m)
	{
		if(is_one(i,j))
		{
			cout<<"1\n";
			return 0;
		}
	}
	cout<<"2\n";
	return 0;
}
/*
5 5
#####
#...#
#####
#...#
#####
*/