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
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
char mp[1005][1005];
int vis1[1005][1005],vis2[1005][1005];
int dx[5] = { -1,0,0,1 }, dy[5] = { 0,-1,1,0 };
int main()
{
    int n, m, i, j, k, l,tx,ty;
    int flag = 0;
    cin >> n >> m;
    memset(mp, '*', sizeof(mp));
    for (i = 1; i <= n; i++)
    {
        scanf("%s", mp[i] + 1);
        mp[i][m + 1] = '*';
    }
    for (i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if (mp[i][j] == 'S')
            {
                for (k = 0; k < 4; k++)
                {
                    tx = i;
                    ty = j;
                    while (mp[tx][ty]!='*')
                    {
                        vis1[tx][ty] = 1;
                        //debug(tx);
                        //debug(ty);
                        tx = tx + dx[k];
                        ty = ty + dy[k];
                        
                    }
                }
            }
            else if (mp[i][j] == 'T')
            {
                for (k = 0; k < 4; k++)
                {
                    tx = i;
                    ty = j;
                    while (mp[tx][ty] != '*')
                    {
                        //debug(tx);
                        //debug(ty);
                        vis2[tx][ty] = 1;
                        tx = tx + dx[k];
                        ty = ty + dy[k];
                    }
                }
            }
    //return 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (vis1[i][j])
            {
                for (k = 0; k < 4; k++)
                {
                    tx = i;
                    ty = j;
                    while (mp[tx][ty] != '*')
                    {
                        flag |= vis2[tx][ty];
                        tx = tx + dx[k];
                        ty = ty + dy[k];
                    }
                }
            }
    if (flag)
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*

*/