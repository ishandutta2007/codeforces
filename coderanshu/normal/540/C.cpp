#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2e18
#define endl "\n"

ll power(ll b,ll e,ll m)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b%m,e/2,m)%m;
	return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
	if(e==0) return 1;
	if(e&1) return b*power(b*b,e/2);
	return power(b*b,e/2);
}
char arr[505][505],br[505][505];
int n,m,check=0;
void dfs(int i,int j)
{
	if(br[i][j]=='X')return ;
	br[i][j]='X';
	if(i>1)dfs(i-1,j);
	if(i<n)dfs(i+1,j);
	if(j>1)dfs(i,j-1);
	if(j<m)dfs(i,j+1);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int i,j;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=m;++j)
		{
			cin>>arr[i][j];br[i][j]=arr[i][j];
		}
	}
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	br[a][b]='.';
	br[c][d]='.';
	arr[a][b]='.';
	int count=0;
	if(c>1 && arr[c-1][d]=='.')++count;
	if(c<n && arr[c+1][d]=='.')++count;
	if(d>1 && arr[c][d-1]=='.')++count;
	if(d<m && arr[c][d+1]=='.')++count;
	if(a==c && b==d)
	{
		if(count>0)cout<<"YES";
		else cout<<"NO";
		return 0;
	}
	dfs(a,b);
	if(br[c][d]!='X')
	{
		cout<<"NO";return 0;
	}
	if(arr[c][d]=='X')
	{
		cout<<"YES";return 0;
	}
	
	if(count>1)cout<<"YES";
	else cout<<"NO";
	return 0;
}