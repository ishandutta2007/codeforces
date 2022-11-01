#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
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
const int N =110; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
ll dp[N][N][N];
int a[N], d[N][N];
int main ()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)cin>>a[i];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin>>d[i][j];
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= n; k++) 
			  dp[i][j][k] = inf;
			  
    dp[0][0][0] = 0;
    for (int i = 0; i < n; i++)
	{
        for (int j = 0; j <= m; j++)
		{
            for (int k = 0; k <= i; k++)
			  if (dp[i][j][k] != inf)
			  {
                if (a[i + 1]){
                    dp[i + 1][a[i + 1]][k + (a[i + 1] != j)] = min (dp[i + 1][a[i + 1]][k + (a[i + 1] != j)], dp[i][j][k]);
                }
				else
				{
                    for (int l = 1; l <= m; l++) {
                        dp[i + 1][l][k + (l != j)] = min (dp[i + 1][l][k + (l != j)], dp[i][j][k] + d[i + 1][l]);
                    }
                }
            }
        }
    }
    ll ans = inf;
    for (int i = 1; i <= m; i++) ans = min (ans, dp[n][i][k]);
    if (ans == inf) cout << -1;
    else cout << ans;
    return 0;
}