#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int Min[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        Min[i] = 1e9;

    int l[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
    {
        if(i == 0 || a[i][j] < a[i - 1][j])
            l[i][j] = i;
        else l[i][j] = l[i - 1][j];

        Min[i] = min(Min[i], l[i][j]);
    }

    int q;
    cin >> q;

    while(q--)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        if(Min[r] <= l)
            cout << "Yes\n";
        else cout << "No\n";
    }
}