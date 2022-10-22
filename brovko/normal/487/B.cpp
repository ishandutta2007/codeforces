#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define li long long

using namespace std;

int n, s, l, a[100005], t[400015][3], dp2[100005];

int get(int i, int v, int l, int r, int L, int R)
{
    if(L >= R)
        return 1e18;

    if(L == l && R == r)
        return t[v][i];

    int m = (l + r) / 2;

    return min(get(i, 2 * v + 1, l, m, L, min(m, R)), get(i, 2 * v + 2, m, r, max(L, m), R));
}

void update(int i, int v, int l, int r, int pos, int val)
{
    if(r - l == 1)
    {
        t[v][i] = val;
        return;
    }

    int m = (l + r) / 2;

    if(pos < m)
        update(i, 2 * v + 1, l, m, pos, val);
    else update(i, 2 * v + 2, m, r, pos, val);

    t[v][i] = min(t[2 * v + 1][i], t[2 * v + 2][i]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s >> l;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        update(0, 0, 0, n, i, a[i]);
        update(1, 0, 0, n, i, -a[i]);
    }

//    cout << get(0, 0, 0, n, 4, 7) << ' ' << get(1, 0, 0, n, 4, 7) << endl;

    for(int i = 1; i < l; i++)
        update(2, 0, 0, n + 1, i, 1e18);

    dp2[0] = 0;

    for(int i = 1; i < l; i++)
        dp2[i] = 1e18;

    for(int i = l - 1; i < n; i++)
    {
        int L = -1, R = i - l + 2;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

//            if(i == n - 1)
//                cout << "!" << M << endl;

            if(-get(0, 0, 0, n, M, i + 1) - get(1, 0, 0, n, M, i + 1) > s)
                L = M;
            else R = M;
        }

        int dp = get(2, 0, 0, n + 1, L + 1, i - l + 2) + 1;

        if(R == i - l + 2)
            dp = 1e18;

//        cout << L + 1 << ' ' << i - l + 1 << ' ' << dp << endl;
//
//        dp2[i + 1] = 1e18;
//
//        for(int j = 0; j <= i - l + 1; j++)
//        {
//            int Min = 1e18, Max = -1e18;
//
//            for(int z = j; z <= i; z++)
//            {
//                Min = min(Min, a[z]);
//                Max = max(Max, a[z]);
//            }
//
//            if(Max - Min <= s)
//                dp2[i + 1] = min(dp2[i + 1], dp2[j] + 1);
//        }
//
//        cout << dp << ' ' << dp2[i + 1] << endl;

        update(2, 0, 0, n + 1, i + 1, dp);
    }

    int ans = get(2, 0, 0, n + 1, n, n + 1);

    if(ans > 1e17)
        cout << -1;
    else cout << ans;
}