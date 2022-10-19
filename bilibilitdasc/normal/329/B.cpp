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
const int dr[]={-1,0,1,0},dc[]={0,-1,0,1};
int r,c,mr,mc,er,ec,ans;
char s[1005][1005];
int len[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>r>>c;
	rep(i,r) rep(j,c)
	{
		len[i][j]=1e8;
		cin>>s[i][j];
		if(s[i][j]=='S')
		mr=i,mc=j;
		if(s[i][j]=='E')
		er=i,ec=j,len[i][j]=0;
	}
	queue<int> q;
	q.push(er);
	q.push(ec);
	while(!q.empty())
	{
		int rr=q.front();q.pop();
		int cc=q.front();q.pop();
		rep(i,4)
		{
			int r_=rr+dr[i];
			int c_=cc+dc[i];
			if(r_<0||c_<0||r_>=r||c_>=c) continue;
			if(s[r_][c_]=='T') continue;
			if(len[r_][c_]!=1e8) continue;
			len[r_][c_]=len[rr][cc]+1;
			q.push(r_);
			q.push(c_);
		}
	}
	//cout<<len[mr][mc];
	rep(i,r) rep(j,c)
	{
		//cout<<len[i][j]<<endl;
		ans+=(isdigit(s[i][j]))*(len[i][j]<=len[mr][mc])*(s[i][j]-'0');
	}
	cout<<ans<<endl;
	return 0;
}
/*
2 4
SE23
2023
*/