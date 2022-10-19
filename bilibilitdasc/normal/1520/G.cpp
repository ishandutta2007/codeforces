#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
struct point{
	int x;
	int y;
	point(int a=0,int b=0)
	{
		x=a;
		y=b;
	}
};
#define INF 0x3f3f3f3f3f3f3f3fll
long long ans;
int n,m,w;
int num[2003][2003];
const int dx[4]={0,1,0,-1};
const int dy[4]={1,0,-1,0};
vector<point> spc;
long long dist[2003][2003];
queue<point> q;
bool valid(int i,int j)
{
	return 0<=i&&0<=j&&i<n&&j<m;
}
void bfs(int i,int j)
{
	while(!q.empty()) q.pop();
	memset(dist,0x3f,sizeof(dist));
	dist[i][j]=0;
	q.push(point(i,j));
	while(!q.empty())
	{
		point a=q.front();
		q.pop();
		int i=a.x,j=a.y;
		for(int t=0;t<4;t++)
		{
			if(valid(i+dx[t],j+dy[t])&&num[i+dx[t]][j+dy[t]]!=-1&&dist[i+dx[t]][j+dy[t]]==INF)
			{
				dist[i+dx[t]][j+dy[t]]=dist[i][j]+w;
				q.push(point(i+dx[t],j+dy[t]));
			}
		}
	}
}
long long a1=INF,a2=INF;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>w;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
	{
		cin>>num[i][j];
		if(num[i][j]>0) spc.push_back(point(i,j));
	}
	//cout<<spc.size()<<endl;
	//return 0;
	bfs(0,0);
	ans=dist[n-1][m-1];
	for(int i=0;i<spc.size();i++)
	{
		a1=min(a1,dist[spc[i].x][spc[i].y]+num[spc[i].x][spc[i].y]);
	}
	bfs(n-1,m-1);
	for(int i=0;i<spc.size();i++)
	{
		a2=min(a2,dist[spc[i].x][spc[i].y]+num[spc[i].x][spc[i].y]);
	}
	ans=min(ans,a1+a2);
	if(ans==INF) ans=-1;
	cout<<ans<<endl;
	return 0;
}