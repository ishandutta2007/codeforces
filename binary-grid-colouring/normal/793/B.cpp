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
int dp[1010][1010][5][5];
int a[1010][1010];
int dx[] = {-1, 0, 0, 1}; 
int dy[] = {0, -1, 1, 0}; 
int sx, sy, tx, ty; 
int main()
{
	//in;
	int n,m;
	n=read(),m=read();
	for (int i = 0; i < n; i++)
	{
		string s; 
		cin>>s;
		for (int j = 0; j < m; j++)
		{ 
			if (s[j] == '.')
			{ 
				a[i][j] = 0; 
			} 
			else if(s[j]=='*')
			{ 
			   a[i][j] = 1; 
			}
			else if (s[j] == 'S')
			{ 
				sx = i, sy = j; 
			} 
			else
			{ 
				tx = i;
				ty = j; 
			} 
		} 
	}
	queue<pair<pair<int, int>, pair<int, int>>>qpp;
	for (int i = 0; i < 4; i++)
	{ 
		qpp.push({{sx, sy}, {i, 0}}); 
	} 
	while (!qpp.empty())
	{
		auto nxt=qpp.front();qpp.pop();
		int x = nxt.first.first;
		int y = nxt.first.second; 
		int d = nxt.second.first;
		int c = nxt.second.second; 
		for (int i = 0; i < 4; i++)
		{ 
			int ttx = x + dx[i];
			int tty = y + dy[i]; 
			int td = i;
			int tc = c + (i != d); 
			if (tc <= 2 && ttx >= 0 && ttx < n && tty >= 0 && tty < m && !a[ttx][tty])
			{ 
				if (!dp[ttx][tty][td][tc])
				{ 
					
					qpp.push({{ttx, tty}, {td, tc}}); 
					dp[ttx][tty][td][tc]=1; 
				} 
			} 
		} 
	}
	int flag=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<3;j++){
			flag|=dp[tx][ty][i][j];
		}
	}
	if(flag==1){
		puts("YES");
	}
	else puts("NO");
	return 0;
}