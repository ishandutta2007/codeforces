#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
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
const int INF = 1e9; 
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
int dx[] = {-1, 0, 0, 1}; 
int dy[] = {0, -1, 1, 0}; 
int sx, sy, tx, ty;
/*
struct Mice  
{ 
	ll x, y; Mice () {} 
	Mice (ll a, ll b) 
	{ 
		x = a, y = b; 
		if (y < 0)
		{ 
			y = -y; x = -x; 
		} 
	} 
	friend bool operator>(const Mice &a, const Mice &b) 
	{ 
		return a.x * b.y > a.y * b.x; 
	} 
	friend bool operator<(const Mice &a, const Mice &b) 
	{ 
		return a.x * b.y < a.y * b.x; 
	} 
}; 
ll x11, y11, x22, y22; 

//double ans; 
*/
vector<pair<int, int>>V[85]; 
//ll dp[85][85][85][85]; //MLE
int dp[81][81][81][81];
int dfs(int l, int r, int p, int k)
{ 
	if (k==0) return 0; 
	if (l>r) return INF; 
	if (dp[l][r][p][k] ==-1)
	{ 
		dp[l][r][p][k] = INF; 
		for (auto x : V[p]) 
		{ 
			int v = x.first;
			int c = x.second; 
			if (v>=l&&v<=r)
			{ 
				dp[l][r][p][k]=min(dp[l][r][p][k], dfs(l, v-1,v,k-1)+c); 
				dp[l][r][p][k]=min(dp[l][r][p][k], dfs(v + 1, r, v, k-1) + c); 
			} 
		} 
	} 
	return dp[l][r][p][k]; 
}
/*
7 4
4
1 6 2
6 2 2
2 4 2
2 7 1

6
*/
int main()
{
	//in;
	memset(dp, -1, sizeof(dp)); 
	int n, k, m; 
	n=read(),k=read(),m=read();
	for (int i = 0; i<m; i++) 
	{ 
		int u, v, w; 
		u=read(),v=read(),w=read();
		V[u].push_back({v, w}); 
	} 
	int ans = INF; //INF:1e9
	for(int i=1;i<=n;i++) 
	{ 
		ans=min(ans,dfs(1, i - 1, i, k-1)); 
		ans=min(ans,dfs(i + 1, n, i, k-1)); 
	} 
	if (ans<INF)
	{ 
		return 0*printf("%d\n",ans);
	} 
	else
	{ 
		return 0*puts("-1");
	} 
	return 0;
}