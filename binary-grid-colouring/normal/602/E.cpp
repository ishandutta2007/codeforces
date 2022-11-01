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
const int maxn=110000; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read(){
int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int n,m;
int a[N];
double dp[N][maxn];
double s[N][maxn];
int main()
{
	   //freopen("in.txt","r",stdin); 
   		n=read(),m=read();
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(m==1) // 
        {
            printf("%.9lf",1.0);
            return 0;
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=m-1;
        s[0][0]=0;
        for(int i=1;i<=n*m+1;i++)
        {
            s[0][i]=m-1;
        }
        for(int i=1;i<=n;i++)
        {
            s[i][0]=0;  
            s[i][1]=0; 
            for(int j=1;j<=n*m;j++)
            {
                int r=j;
				int l=max(0,j-m);
                dp[i][j]+=(s[i-1][r]-s[i-1][l])*1.0/(m-1);
                
                if(j-a[i]>=0)
                {
                	dp[i][j]=dp[i][j]-dp[i-1][j-a[i]]*1.0/(m-1);
				}     
                s[i][j+1]=s[i][j]+dp[i][j];
            }
        }
        printf("%.9lf",s[n][sum]+1);
    return 0;
}