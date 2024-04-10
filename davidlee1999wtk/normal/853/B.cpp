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
#include<ctime>
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
struct Tic
{
    int d, f, c;
    Tic(int D = 0, int F = 0, int C = 0)
    {
        d = D, f = F, c = C;
    }
    bool operator <(const Tic &t) const
    {
        return d < t.d;
    }
}go[N], back[N];
int flag_g[N], flag_b[N];
LL cost_g[N], cost_b[N];
int vis[N],cnt;

int main()
{
    int n, m, k, d, f, t, c, i, ng=0, nb=0;
    LL ans = (LL)INF * INF;
    cin >> n >> m >> k;
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d%d%d", &d, &f, &t, &c);
        if (t == 0)
        {
            ng++;
            go[ng] = Tic(d,f,c);
        }
        else
        {
            nb++;
            back[nb] = Tic(d, t, c);
        }
    }
    sort(go + 1, go + 1 + ng);
    sort(back + 1, back + 1 + nb);
    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (i = nb; i; i--)
    {
        cost_b[i] = cost_b[i + 1];
        if (!vis[back[i].f])
        {
            cnt++;
            vis[back[i].f] = back[i].c;
            cost_b[i] += back[i].c;
        }
        else if (back[i].c < vis[back[i].f])
        {
            cost_b[i] += back[i].c - vis[back[i].f];
            vis[back[i].f] = back[i].c;
        }
        if (cnt == n)
            flag_b[i] = 1;
    }

    memset(vis, 0, sizeof(vis));
    cnt = 0;
    for (i = 1; i <= ng; i++)
    {
        cost_g[i] = cost_g[i - 1];
        if (!vis[go[i].f])
        {
            cnt++;
            vis[go[i].f] = go[i].c;
            cost_g[i] += go[i].c;
        }
        else if (go[i].c < vis[go[i].f])
        {
            cost_g[i] += go[i].c - vis[go[i].f];
            vis[go[i].f] = go[i].c;
        }
        if (cnt == n)
            flag_g[i] = 1;
        if (flag_g[i])
        {
            int ret = go[i].d + k, j;
            //debug(ret);
            j = upper_bound(back + 1, back + 1 + nb, Tic(ret, 0, 0)) - back;
            //debug(j);
            //debug(flag_b[j]);
            //debug(cost_g[i]);
            if (flag_b[j])
                ans = min(ans, cost_g[i] + cost_b[j]);
        }
    }
    if (ans == (LL)INF*INF)
        ans = -1;
    cout << ans << endl;
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/