#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, k, a[1000005], t[20000005], l[20000005], r[20000005], y;

void push(int v, int x, int N)
{
    t[v]++;

    if(x == 0)
        return;

    if((N & (1ll << x - 1)) > 0)
    {
        if(r[v] > 0)
            push(r[v], x - 1, N);
        else
        {
            r[v] = y;
            y++;
            push(r[v], x - 1, N);
        }
    }
    else
    {
        if(l[v] > 0)
            push(l[v], x - 1, N);
        else
        {
            l[v] = y;
            y++;
            push(l[v], x - 1, N);
        }
    }
}

int get(int v, int x, int N)
{
    if(x == 0)
        return t[v];

    if((k & (1ll << x - 1)) > 0)
    {
        if(l[v] > 0 && (N & (1ll << x - 1)) > 0)
            return get(l[v], x - 1, N);

        if(r[v] > 0 && (N & (1ll << x - 1)) == 0)
            return get(r[v], x - 1, N);

        return 0;
    }
    else
    {
        int ans = 0;

        if(l[v] > 0 && (N & (1ll << x - 1)) == 0)
            ans += get(l[v], x - 1, N);

        if(r[v] > 0 && (N & (1ll << x - 1)) > 0)
            ans += get(r[v], x - 1, N);

        if((N & (1ll << x - 1)) == 0 && r[v] > 0)
            ans += t[r[v]];

        if((N & (1ll << x - 1)) > 0 && l[v] > 0)
            ans += t[l[v]];

        return ans;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    y = 1;

    int s = 0;
    int ans = 0;

    push(0, 31, 0);

    for(int i = 0; i < n; i++)
    {
        s ^= a[i];
        ans += get(0, 31, s);
        push(0, 31, s);
    }

    cout << ans;
}