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
const int N = 110; 
const int M=100010;
const int maxn=1001; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}

int id[maxn][maxn],n,m,edge,mat[2][maxn][maxn],ret,ans[100*maxn]; 
void dfs(int p,int a,int b,int c1,int c2) {
    int t=mat[1^p][b][c1]; 
    mat[p][a][c1]=b,mat[1^p][b][c1]=a;
    if (t==-1) {
        mat[1^p][b][c2]=-1;return ;
    }
    dfs(1^p,b,t,c2,c1); 
}   
    
int main()
{
    scanf("%d%d%d",&n,&m,&edge); 
    memset(mat,255,sizeof(mat)); 
    for (int i=1;i<=edge;i++)
	{
        int a,b,c1=1,c2=1; 
        scanf("%d%d",&a,&b); 
        id[a][b]=i;
        while ( mat[0][a][c1]!=-1) c1++; 
        while (mat[1][b][c2]!=-1) c2++; 
        ret=max(ret,max(c1,c2)); 
        if (c1==c2) mat[0][a][c1]=b,mat[1][b][c1]=a;
        else dfs(0,a,b,c1,c2); 
    }
    for ( int i=1;i<=n;i++)
        for(int j=1;j<=ret;j++) 
            if (mat[0][i][j]!=-1) ans[id[i][mat[0][i][j]]]=j; 
    printf("%d\n",ret);
    for(int i=1;i<=edge;i++) printf("%d ",ans[i]); 
    return 0; 
}