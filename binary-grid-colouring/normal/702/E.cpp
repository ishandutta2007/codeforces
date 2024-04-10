#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
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
#define pii pair<int,int>
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
const int N = 2e5+10; 
const int M=100010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
	
const int MAXN=100005;
ll f[MAXN],w[MAXN],d[MAXN][35],sum[MAXN][35],mi[MAXN][35];
int main()
{
	#ifndef ONLINE_JUDGE
   // freopen("in.txt","r",stdin);
    #endif
    ll n,k;
    scanf("%I64d%I64d",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%I64d",&f[i]);
    for(int i=0;i<n;i++)
        scanf("%I64d",&w[i]);
    for(int i=0;i<n;i++)
        d[i][0]=f[i],sum[i][0]=mi[i][0]=w[i];
    for(int j=1;j<35;j++)
        for(int i=0;i<n;i++)
        {
            d[i][j]=d[ d[i][j-1] ][j-1];
            sum[i][j]=sum[i][j-1]+sum[ d[i][j-1] ][ j-1 ];
            mi[i][j]=min( mi[i][j-1],mi[d[i][j-1]][j-1] );
        }
    for(int i=0;i<n;i++)
    {
        ll rsum=0,rmin=(1LL<<30)-1;
        int x=i;
        for(int j=34;j>=0;--j)
            if(k&(1LL<<j))
            {
                rsum+=sum[x][j];
                rmin=min(rmin,mi[x][j]);
                x=d[x][j];
            }
        printf("%I64d %I64d\n",rsum,rmin);
    }
    return 0;
}