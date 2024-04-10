#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=202;
int dx[]={0,1,-1,0};
int dy[]={1,0,0,-1};

int n,m,k,vis[N][N],sum=0,T;
char a[N][N];

int P(int x,int y)
{
	return (x-1)*m+y;
}

int rest,x,y;
void dfs(int id)
{
	if(x>n) return;
	if(a[x][y]=='R') 
	{
		if(!rest) return;
		else rest--;
	}
	vis[x][y]=id;
	if(x%2==1)
	{
		if(y==m) x++;
		else y++;
	}
	else 
	{
		if(y==1) x++;
		else y--;
	}
	dfs(id);
}

void print(int x)
{
	if(x<=10) printf("%c",x-1+'0');
	else if(x<=36) printf("%c",x-11+'a');
	else printf("%c",x-37+'A'); 
}

int main() 
{
	cin>>T;
	while(T--)
	{
		sum=0;
		memset(vis,0,sizeof(vis));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++) 
		{
			scanf("%s",a[i]+1);
			for(int j=1;j<=m;j++) if(a[i][j]=='R') sum++;
		}
		int d=sum/k, r=sum%k, now=0;
		x=1,y=1;
		while(P(x,y)<=m*n)
		{
			if(r) rest=d+1,dfs(++now),r--; 
			else rest=d,dfs(++now);
//			if(x%2==1)
//			{
//				if(y==m) x++;
//				else y++;
//			}
//			else 
//			{
//				if(y==1) x++;
//				else y--;
//			}
		}
		for(int i=1;i<=n;i++) 
		{
			for(int j=1;j<=m;j++)
			{
				print(vis[i][j]);
			}
			puts("");
		}
	}
	return 0;
}