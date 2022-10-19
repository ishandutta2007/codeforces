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
const int dx[]={-1,-1,-1,0,0,1,1,1};
const int dy[]={-1,0,1,-1,1,-1,0,1};
int l[8][8];
int d[8][8];
queue<int> q;
vector<str> v;
int main()
{
	ios::sync_with_stdio(false);
	str a,b;
	cin>>a>>b;
	int y1=a[0]-'a',x1=a[1]-'1',y2=b[0]-'a',x2=b[1]-'1';
	rep(i,8) rep(j,8) d[i][j]=66666;
	d[x1][y1]=0;
	q.push(x1);q.push(y1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		int y=q.front();q.pop();
		rep(i,8)
		{
			int X=x+dx[i],Y=y+dy[i];
			if(X<0||Y<0||X>=8||Y>=8) continue;
			if(d[x][y]+1>=d[X][Y]) continue; 
			d[X][Y]=d[x][y]+1;
			l[X][Y]=i;
			q.push(X);
			q.push(Y);
		}
	}
	cout<<d[x2][y2]<<endl;
	while(x2!=x1||y2!=y1)
	{
		str s="";
		int xx=dx[l[x2][y2]],yy=dy[l[x2][y2]];
		if(yy==-1) s+="L";
		if(yy==1) s+="R";
		if(xx==-1) s+="D";
		if(xx==1) s+="U";
		x2-=xx,y2-=yy;//tui
		v.pb(s); 
	}
	per(i,v.size())
	cout<<v[i]<<endl;
	return 0;
}
//