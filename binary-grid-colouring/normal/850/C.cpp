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
//const ll mod = (1LL<<32);
//const int N =2000000; 
//const int M=100010;
//const int maxn=1001;
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
map<int,int>mp;
int SG(int x,int N)
{
	if(mp.find(x)!=mp.end())
	{
		return mp[x];
	}
	while(N > 0 && ( x &(1<<(N-1)))==0)
	{
		N--;
	}
	if(N==0){
		return 0;
	} 
	
	bool vis[34]={0};
	
	for(int i=1;i<=N;i++)
	{
		int now = x>>i;
		now|=x&((1<<(i-1))-1);
		vis[SG(now,max(N-i,i-1))] = 1;
	}
	for(int i=0;;i++)
	{
		if(!vis[i])
		{
			return mp[x] = i;
		}
	}
	
}
int ans;
int a[123];
int n;
void gao(int x)
{
	int t=0;
	int Max=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=a[i];
		int now=0;
		while(tmp%x==0)
		{
			tmp/=x;
			now++;
		}		
		if(now)
		{
			t|=1<<(now-1);
		}
		Max=max(Max,now);
	}
	ans^=SG(t,Max);
}
int cnt;
int s[1000010];
void check(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			s[++cnt]=i;
			while(x%i==0)
			{
				x/=i;
			}
		}		
	}
	if(x>1)
	{
		s[++cnt]=x;
	}	
}
/*
4
1 1 17 289
Arpa
*/
int main()
{
	//in;
    //timer tim;
    //int n;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	a[i]=read();
    	check(a[i]);
	}
	sort(s+1,s+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(s[i]!=s[i-1])
		{
			gao(s[i]);
		}
	}
	if(!ans)puts("Arpa");
	else puts("Mojtaba");
	return 0;
}