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
/*
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
*/
//-1
vector<int>G[100010];  
vector<int>ans[2];  
int vis[100010];  
int flag;  
int type[100010];  
void dfs(int u,int fa,int ty)  
{  
     ans[ty].push_back(u);  
     vis[u]=1;  
     type[u]=ty;  
     for(int i = 0;i<G[u].size();i++)  
     {  
         int v = G[u][i];  
         if(v==fa)  
             continue;  
         if(vis[v]&&type[v]==type[u])  
             flag=1;  
         if(vis[v])  
             continue;  
         dfs(v,u,1-ty);  
     }  
}  
int main()  
{  
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    int n,m;  
    flag = 0;  
    scanf("%d%d",&n,&m);  
    for(int i=0;i<m;i++)  
    {  
        int u,v;  
        scanf("%d%d",&u,&v);  
        G[u].push_back(v);  
        G[v].push_back(u);  
    }  
    for(int i = 1;i <= n; i++)  
        if(!vis[i]&&!flag)  
            dfs(i,-1,0);  
    if(flag)  
    {  
       puts("-1");
        return 0;  
    }  
    printf("%d\n",ans[0].size());
    for(int i=0;i<ans[0].size()-1;i++)  
        printf("%d ",ans[0][i]);  
    printf("%d\n",ans[0][ans[0].size()-1]);
    
    printf("%d\n",ans[1].size());
    for(int i=0;i<ans[1].size()-1; i++)  
       printf("%d ",ans[1][i]);
    printf("%d\n",ans[1][ans[1].size()-1]);
    return 0;
}