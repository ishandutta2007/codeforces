//#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int dp[1<<24];
int pre[1<<24];
int dis[30][30],x[30],y[30];
int n;
int dfs1(int cur)//n*2^n 
{
	if(dp[cur]!=-1)return dp[cur];
	dp[cur]=1e9;
	for(int i=0;i<n;i++)
	{
		if(cur&(1<<i))
		{
		//	cout<<"i="<<(cur^(1<<i))<<endl;
			int nxt = dfs1 (cur^(1<<i));
			if(dp[cur] > nxt + dis[n][i] + dis[i][n] )
			{
				dp[cur] = nxt + dis[n][i] + dis[i][n];
				//printf("dp[%d]=%d\n",cur,dp[cur]);
				pre[cur] = cur^(1<<i);
			}
			for(int j=i+1;j<n;j++)
			{
				if(cur&(1<<j))
				{			
						//cout<<"j="<<(cur^(1<<j))<<endl;
					//	cout<<"ij="<<(cur^(1<<i)^(1<<j))<<endl;
						nxt = dfs1(cur^(1<<i)^(1<<j));
						if(dp[cur] > nxt + dis[n][i] + dis[i][j] + dis[j][n])
						{
							dp[cur] = nxt + dis[n][i] + dis[i][j] + dis[j][n];
						//	printf("dp[%d]=%d\n",cur,dp[cur]);
							pre[cur] = cur^(1<<i)^(1<<j);
 						}
				}

			}
			break;// TLE
		}
	}
	return dp[cur];
}
int dfs2(int cur)
{
	if(cur)
	{
		for(int i=0;i<n;i++)
		{
			//if((cur^cur^(1<<i))||cur^cur^(1<<i)&&(1<<i))
			if((cur^pre[cur])&(1<<i))	
			{
				cout<<i+1<<" ";
			}
		}
		cout<<"0 ";// 
		dfs2(pre[cur]);
	}
}
int main()
{
	cin>>x[0]>>y[0];
	cin>>n;
	x[n]=x[0];y[n]=y[0];
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			dis[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		}
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	cout<<dfs1((1<<n)-1)<<endl;
	cout<<"0 ";
	dfs2((1<<n)-1);
	cout<<endl;
	return 0;
}