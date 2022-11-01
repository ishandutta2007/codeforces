#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)  
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 2010; 
const int M=100010;
const int maxn=2e3+7; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int n,m,q,p;
int flag[N],num[N],ok[N];
char str[20];
ll a[N][N];
struct fuck
{
	int x,y,w;
	
}b[N][N];

void update(int x,int y,ll w)
{
	int j;
	while(x<=n)
	{
		j=y;
		while(j<=m){
		  a[x][j]+=w;
		  j+=lowbit(j);
	   }
	    x+=lowbit(x);
	}
}

ll getsum(int x,int y)
{
	ll ans,j;
	ans=0;
	while(x>0)
	{
		j=y;
		while(j>0){
		  ans+=a[x][j];
	      j-=lowbit(j);
	   }
    	x-=lowbit(x);
	}
	return ans;
}
/*
void update(int x,int y,int w)
{
    for(int i=x;i<maxn;i+=lowbit(i))
        for(int j=y;j<maxn;j+=lowbit(j))
            a[i][j]+=w;
}

ll getsum(int x,int y)
{
    ll ans = 0;
    for(int i=x;i>0;i-=lowbit(i))
        for(int j=y;j;j-=lowbit(j))
            ans+=a[i][j];
    return ans;
}
*/
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
	int i,j,k,x1,x2,y1,y2;
	memset(flag,0,sizeof(flag));
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=p;i++)
	{
		scanf("%d",&num[i]);
		for(j=1;j<=num[i];j++)
		{
			scanf("%d%d%d",&b[i][j].x,&b[i][j].y,&b[i][j].w);
		}
		ok[i]=1;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%s",str+1);
		if(str[1]=='S') //switch
		{
	       scanf("%d",&k);
		   ok[k]^=1;
		}
		else //ask
		{
			
			for(i=1;i<=p;i++)
			{
				if(ok[i])
			   {
				 for(j=1;j<=num[i];j++)
				 {
				 	update(b[i][j].x, b[i][j].y, b[i][j].w*((flag[i]==1?(-1):1)) );
				 }	  
				  flag[i]^=1;
				  ok[i]=0;
			   }
			}			  
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			printf("%I64d\n",getsum(x2,y2)-getsum(x1-1,y2)-getsum(x2,y1-1)+getsum(x1-1,y1-1));
			
		}
	}
	return 0;
}