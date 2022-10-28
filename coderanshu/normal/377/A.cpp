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
bool ans=true;
char a[505][505];
bool vis[505][505];
int n,m,k,countvar;
void dfs(int i,int j)
{
	if(countvar==k)
	return ;
	if(vis[i][j])return ;
	vis[i][j]=true;
	countvar--;
	if(i>0 && a[i-1][j]=='.')dfs(i-1,j);
	if(j>0 && a[i][j-1]=='.')dfs(i,j-1);
	if(i<n-1 && a[i+1][j]=='.')dfs(i+1,j);
	if(j<m-1 && a[i][j+1]=='.')dfs(i,j+1);		
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i,j;
	cin>>n>>m>>k;
	int ii,ij;
	countvar=0;
	memf(vis);
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			cin>>a[i][j];
			if(a[i][j]=='.')
			{
				countvar++;
				ii=i;ij=j;
			}
		}
	}
	dfs(ii,ij);
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			if(a[i][j]=='#')cout<<"#";
			else if(vis[i][j])cout<<".";
			else cout<<"X";
		}
		cout<<endl;
	}
	return 0;
}