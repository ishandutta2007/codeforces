#include <bits/stdc++.h>

using namespace std;

int n;
const int MAXN = 500005;

vector<long long> arr(MAXN);

int st[MAXN * 7];

int build(int l, int r, int v)
{
    if (l == r)
        return st[v] = l;
    int m = l+r>>1;
    int ll = build(l, m, v<<1);
    int rr = build(m+1, r, v<<1|1);
    return st[v] = arr[ll] < arr[rr] ? ll : rr;
}

int query(int l, int r, int v, int li, int ri)
{
    if (l > ri || r < li)
        return 0;
    if (l >= li && r <= ri)
        return st[v];
    int m = l+r>>1;
    int ll = query(l, m, v<<1, li, ri);
    int rr = query(m+1, r, v<<1|1, li, ri);
    return arr[ll] < arr[rr] ? ll : rr;
}

long long conq(int l, int r)
{
    if (r < l)
        return 0;
    int i = query(1, n, 1, l, r);
    long long ll = conq(l, i-1), rr = conq(i+1, r);
    long long ans = 0;
    if (ll + (r - i) * arr[i] > rr + (i - l) * arr[i])
        for (int x = i; x <= r; x++)
            arr[x] = arr[i];
    else
        for (int x = l; x <= i; x++)
            arr[x] = arr[i];
    for (int x = l; x <= r; x++)
        ans += arr[x];
    return ans;
}

int main()
{
    arr[0] = LONG_MAX;
    scanf("%i", &n);
    for (int x = 1; x <= n; x++)
        scanf("%lli", &arr[x]);
    build(1, n, 1);
    conq(1, n);
    for (int x = 1; x <= n; x++)
        printf("%lli ", arr[x]);
}