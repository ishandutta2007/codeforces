#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#include<functional>
#include<sstream>
#define INF 1000000000ll * 1000000000ll
#define fi first
#define se second
#define N 5005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int x[N], a[N], b[N], c[N], d[N];
LL dp[2][N]; //dp[i][j]  j 
void upd(LL &x, LL y)
{
    if (x == -INF)
        x = y;
    else if (x > y)
        x = y;
}

int main()
{
    int i, j, n, s, e, de = 0; // de 
    cin >> n >> s >> e;
    for (i = 1; i <= n; i++)
        scanf("%d", &x[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for (i = 1; i <= n; i++)
    {
        a[i] += x[i];
        b[i] -= x[i];
        c[i] += x[i];
        d[i] -= x[i];
    }
    int p = 0, q = 1;
    for (j = 0; j <= n; j++)
        dp[p][j] = -INF;
    dp[0][0] = 0;
    LL y;
    for (i = 1; i <= n; i++, swap(p,q))
    {
        LL *f = dp[p], *g = dp[q];
        for (j = 0; j <= n; j++)
            dp[q][j] = -INF;
        for (j = 0; j <= i; j++)
        {
            if (j == 0 && de == 0 && i!=1)
                continue;
            if (f[j] != -INF)
            {
                y = f[j];
                //debug(y);
                if (i == s)
                {
                    if(j - de > 0)
                        upd(g[j], f[j] + c[i]);
                    upd(g[j + 1], f[j] + d[i]);
                }
                else if (i == e)
                {
                    if(j > 0)
                        upd(g[j-1], f[j] + a[i]);
                    upd(g[j], f[j] + b[i]);
                }
                else
                {
                    if (j - de > 0) //
                    {
                        if (j > 0) //
                            upd(g[j - 1], y + a[i] + c[i]);
                        upd(g[j], y + b[i] + c[i]);
                    }
                    if (j > 0)
                        upd(g[j], y + a[i] + d[i]);
                    upd(g[j + 1], y + b[i] + d[i]);
                }
            }
        }
        if (i == s)
            de++;
        else if (i == e)
            de--;
        /*
        if (i == 5)
        {
            debug(i);
            debug(dp[q][1]);
            debug(dp[q][2]);
        }*/
    }
    //debug(dp[q][1]);
    cout << dp[p][0] << endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/