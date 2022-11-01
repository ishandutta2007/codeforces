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
const int N = 3e5+7; 
const int M=100010;
const int maxn=2e3+7; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int map1[410][410],map2[410][410];  //
int n,m;
void dij(int map[][410])       
{
    int res[410];       //
    int vis[410];       //
    int v,min;          //
    for(int i = 1 ; i <= n ; i++ )      //
    {
        vis[i] = 0;
        res[i] = map[1][i];             
    }
    for (int i = 1 ; i <= n ; i++ )
    {
        min = 1<< 29;
        for (int j = 1 ; j <= n ; j++ )
        {
            if (vis[j] == 0 && res[j] < min )  // 
            {
                v = j;
                min = res[j];
            }
        }
        vis[v] = 1;
        for (int j = 1 ; j <= n ; j++ )
        {
            if(vis[j] == 0 && res[j] > map[v][j] + res[v])      //check 
            {
                res[j] = map[v][j] +res[v];
            }
        }
    }
    if (res[n] == INF)      // 
    {
        puts("-1");
        return ;
    }
    else 
       cout<<res[n];
}
int main()
{
	    n=read(),m=read();
        for (int i = 1 ; i <= n ; i++ )         //
        {
            for (int j = 1 ; j <= n ; j++ )
            {
                if (i ==j)
                {
                    map1[i][j] = 0;
                    map1[i][j] = 0;
                }
                else 
                {
                    map1[i][j] = map1[j][i] = INF;
                    map2[i][j] = map2[j][i] = INF;
                }
            }
        }
        int flag = 0;
        for (int i = 0 ; i < m ; i++ )
        {   
            int a,b;
            scanf("%d%d",&a,&b);
            if ( (a == 1 && b == n) || (a == n && b == 1) ) //
            {
                flag = 1;
            }
            map1[a][b] = 1;
            map1[b][a] = 1;
        }
        for (int i = 1 ; i <= n ; i ++ )
        {
            for (int j = 1 ; j <= n ; j++ )
            {
                if ( map1[i][j] == INF || map1[i][j] == 0)
                {
                    map2[i][j] = 1;
                    map2[j][i] = 1;
                }
            }
        }
        if (m == n*(n-1)/2) //
        {
            puts("-1");
            return 0;
        }    
        if (flag)      //
        {
            dij(map2);
        }
        else if (!flag )  //
        {
            dij(map1);
        }
    return 0;
}