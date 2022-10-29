#include<bits/stdc++.h> 
using namespace std;
const int N=1200005;
typedef vector<int> Vec;
typedef vector<Vec> matrix;
typedef pair<int,int> pii;
#define mk make_pair

int n,m,dp[N][21],b[N],w[N];
char color[N];
Vec v[N];
string a[N],dir[N];

int idx(int x,int y)
{
	return (x-1)*m+y;
}

void init()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) 
	{
		a[i].clear();
		a[i].push_back('.');
		string tmp;
		cin>>tmp;
		for(int j=0;j<m;j++) a[i].push_back(tmp[j]),color[idx(i,j+1)]=tmp[j]; 
	}
	for(int i=1;i<=n;i++) 
	{
		dir[i].clear();
		dir[i].push_back('.');
		string tmp;
		cin>>tmp;
		for(int j=0;j<m;j++) dir[i].push_back(tmp[j]); 
	}
}

pii DIR(char c)
{
	if(c=='U') return mk(-1,0);
	if(c=='R') return mk(0,1);
	if(c=='D') return mk(1,0);
	if(c=='L') return mk(0,-1);
}

void ready()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			pii d=DIR(dir[i][j]);
			int now=idx(i,j);
			int xx=i+d.first,yy=j+d.second;
			if(xx<=0||yy<=0||xx>n||yy>m) continue;
			int to=idx(xx,yy);
			dp[now][0]=to;
		}
	}
	n*=m;
	for(int j=1;j<=20;j++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[i][j]=dp[dp[i][j-1]][j-1];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t; cin>>t;
	int ttt=t;
	while(t--)
	{
		init();
		//if(ttt==1) return 0;
		ready();
		for(int i=1;i<=n;i++)
		{
			int now=i;
			for(int j=20;j>=0;j--)//zou n*m bu
			{
				if(n&(1<<j)) now=dp[now][j]; 
			}
			if(color[i]=='1') w[now]=1;
			else b[now]=1;
		}
		int ans=0,mxb=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]) ans++,mxb++;
			else if(w[i]) ans++;
			b[i]=0; w[i]=0;
		}
		cout<<ans<<" "<<mxb<<endl;
	}
}