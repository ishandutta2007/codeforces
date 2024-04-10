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
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int ans[1234],tot;
int mp[1234][5];
int main()
{
	//in;
    //timer tim;
    int n;
    n=read();
	for(int i=1;i<=n;i++)
		for(int j=0;j<5;j++)
		{
			mp[i][j]=read();
		}
		
	for(int i=1;i<=n;i++)
	{
		int flag=1;
		for(int a=1;flag&&a<=n;a++)if(a!=i)
		{
			for(int b=1;flag&&b<a;b++)if(b!=i)
			{
				ll res=0;
				for(int k=0;k<5;k++){
					res+=(mp[a][k]-mp[i][k])*(mp[b][k]-mp[i][k]);
				}
				if(res>0)flag=0;
			}
		}
		
		if(flag)ans[++tot]=i;
	}
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}