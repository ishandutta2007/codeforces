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
typedef pair<int,int> pii;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
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
const int N =1e6+6; 
const int M=100010;
const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int sz[N], n, par[N], up[N], dw[N];
vector<int> adj[N]; // 
void dfs_sz(int v, int p =-1)
{
    par[v] = p;
    sz[v] = 1;
    for(auto u : adj[v])
    {
        if (u != p){
        	dfs_sz(u,v);
			sz[v] += sz[u];
		}           
    }        
}
void dfs_up(int v, int val = 0, int p = -1)
{
    up[v] = max((n - sz[v] <= n / 2 ? n - sz[v]: 0), val);
    int mx0 = 0, mx1 = 0;
    for(auto u : adj[v])
    {
        if(u != p)
        {
            if (dw[u] >= mx0)
                mx1 = mx0, mx0 = dw[u];
            else if (dw[u] >= mx1)
                mx1 = dw[u];
        }
    }
        
    for (auto u : adj[v])
    {
        if(u != p)
        {
            dfs_up(u, max(up[v], mx0 == dw[u] ? mx1 : mx0), v);
        }
    }      
}
void dfs_down(int v, int p = -1)
{
    dw[v] = (sz[v] <= n / 2 ? sz[v]: 0);
    for (auto u : adj[v])
    {
        if(u != p)
        {
        	dfs_down(u,v);
		    dw[v] = max(dw[v],dw[u]);
		}           
    }      
}
int main()
{   
	int u,v;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {      
        cin>>u>>v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_sz(0);
    dfs_down(0);
    dfs_up(0);
    for(int v = 0; v < n; v++)
    {
        int ans = 1;
        for(auto u : adj[v])
        {
            if(u == par[v])
            {
                if (n - sz[v] - up[v] > n / 2)
                    ans = 0;
            } 
            else
            {
                if(sz[u] - dw[u] > n / 2)
                    ans = 0;
            }
        }
        cout <<ans<<' ';
    }
    return 0; 
}