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
#define N 600005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
pii p[N];
//bool cmp(pii a, pii b
int vis[N];
int rel[N];
int main()
{
    int k, n, st, i, now;
    LL ans = 0;
    cin >> n >> k;
    st = k + 1;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &p[i].fi);
        p[i].se = i;
    }
    sort(p + 1, p + 1 + n);
    reverse(p + 1, p + 1 + n);
    for (i = 1; i <= n; i++)
    {
        now = max(st, p[i].second);
        ans += (LL)(now - p[i].second)*p[i].first;
        rel[p[i].second] = now;
        vis[now] = 1;
        while (vis[st])
            st++;
    }
    cout << ans << endl;
    for (i = 1; i <= n; i++)
        printf("%d ", rel[i]);
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/