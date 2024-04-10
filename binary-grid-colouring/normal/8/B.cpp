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
int g[1010][1010];
char s[110];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int main()
{
	scanf("%s",s);
	g[200][200]=1;
	int len=strlen(s);
	int flag=0,x=200,y=200;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='L')
		{
			y--;
			if(g[x][y])
			{
				flag = 1;
				break;
			}
			g[x][y]=1;
		}
		else if(s[i]=='R')
		{
			y++;
			if(g[x][y])
			{
				flag = 1;
				break;
			}
			g[x][y]=1;
		}
		else if(s[i]=='U')
		{
			x--;
			if(g[x][y])
			{
				flag = 1;
				break;
			}
			g[x][y]=1;
		}
		else if(s[i]=='D')
		{
			x++;
			if(g[x][y])
			{
				flag = 1;
				break;
			}
			g[x][y]=1;
		}
		int count = 0;
		for(int j=0;j<4;j++)
		{
			int n_x=x+dir[j][0];
			int n_y=y+dir[j][1];
			if(g[n_x][n_y])count++;
		}
		if(count!=1)
		{
			flag=1;break;
		}
		
	}
	if(flag==0){
		puts("OK");
	}
	else 
	puts("BUG");
	return 0;
}