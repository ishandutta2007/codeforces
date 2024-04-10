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
#define N 200005
#define P 1000000007
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
int tot, sum[N * 20], lch[N * 20], rch[N * 20], rt[N], qk, ql, qr, qw;
int loc[N], n;
struct Tri
{
    int l, r, d, u;
}Q[N];

void Add(int &x, int pre, int L, int R)
{
    x = ++tot;
    lch[x] = lch[pre];
    rch[x] = rch[pre];
    sum[x] = sum[pre]+1;
    
    if (L == R) return;
    int mid = (L + R) >> 1;
    if (qk <= mid)
    {
        Add(lch[x], lch[pre], L, mid);
    }
    else
        Add(rch[x], rch[pre], mid+1, R);
}

void Query(int x, int L, int R)
{
    //debug(x);
    //debug(L);
    //debug(R);
    if (L >= ql && R <= qr || x == 0)
    {
        qw += sum[x];
        return;
    }
    int mid = (L + R) >> 1;
    if (ql <= mid)
        Query(lch[x], L, mid);
    if (qr > mid)
        Query(rch[x], mid + 1, R);
}

int get_rel(int l, int r, int d, int u)
{
    if (l > n || r < 1 || d > n || u < 1)
        return 0;
    int rel = 0;
    ql = l;
    qr = r;
    qw = 0;
    Query(rt[u], 1, n);
    rel += qw;
    qw = 0;
    Query(rt[d-1], 1, n);
    rel -= qw;
    return rel;
}

int main()
{
    int q, i, u;
    cin >> n >> q;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &loc[i]);
    }
    for (i = 1; i <= q; i++)
    {
        Tri tmp;
        scanf("%d%d%d%d", &tmp.d, &tmp.l, &tmp.u, &tmp.r);
        Q[i] = tmp;
    }
    for (i = 1; i <= n; i++)
    {
        qk = loc[i];
        Add(rt[i], rt[i - 1], 1, n);
    }
    for (i = 1; i <= q; i++)
    {
        //int A, B, C, D, E, F, G, H, I;
        LL sum = 0, E = get_rel(Q[i].l, Q[i].r, Q[i].d, Q[i].u);
        LL EFHI = get_rel(Q[i].l, n, Q[i].d, n);
        sum += (LL)get_rel(1, Q[i].l - 1, 1, Q[i].d - 1) * EFHI;
        sum += (LL)get_rel(1, Q[i].l - 1, Q[i].d, Q[i].u) * get_rel(Q[i].l, n, 1, n);
        sum += (LL)get_rel(1, Q[i].l - 1, Q[i].u + 1, n) * get_rel(Q[i].l, n, 1, Q[i].u);
        sum += (LL)get_rel(Q[i].l, Q[i].r, 1, Q[i].d - 1) * EFHI;
        LL GHI = get_rel(Q[i].r + 1, n, 1, n);
        sum += E * GHI;
        LL F = get_rel(Q[i].l, Q[i].r, Q[i].u + 1, n);
        sum += E * F;
        sum += F * get_rel(Q[i].r+1, n, 1, Q[i].u);
        sum += (LL)(E - 1)*E / 2;
        printf("%I64d\n", sum);
    }
    return 0;
}
// davidlee1999WTK 2017/
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
//#include<bits/stdc++.h>
/*

*/