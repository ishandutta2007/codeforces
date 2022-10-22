#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;
const int N = 2e5 + 13;

int st[N][20], mx2[N];

int get(int L, int R)
{
    int d = R - L;

    return max(st[L][mx2[d]], st[R - (1 << mx2[d])][mx2[d]]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> a(m);

    for(int i = 0; i < m; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        st[i][0] = a[i];

    for(int j = 1; j < 20; j++)
        for(int i = 0; i + (1 << j) <= m; i++)
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);

    for(int i = 2; i <= m; i++)
        mx2[i] = mx2[i / 2] + 1;

    int q;
    cin >> q;

    while(q--)
    {
        int x1, y1, x2, y2, k;
        cin >> x1 >> y1 >> x2 >> y2 >> k;

        if(y1 > y2)
        {
            swap(x1, x2);
            swap(y1, y2);
        }

        bool F = ((get(y1 - 1, y2) - x1 + k) / k * k + x1 <= n && (x1 - x2) % k == 0 && (y1 - y2) % k == 0);
        cout << (F ? "YES\n" : "NO\n");
    }
}