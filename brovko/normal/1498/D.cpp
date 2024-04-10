#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, m, used[100005], used2[100005], ans[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    used[0] = 1;

    for(int i = 0; i < n; i++)
    {
        int t, x, y;
        cin >> t >> x >> y;

        for(int j = 0; j <= m; j++)
            if(used[j] == 1 && used2[j] < y)
            {
                int p;

                if(t == 1)
                    p = j + (x + 99999) / 100000;
                else p = (j * x + 99999) / 100000;

//                cout << i << ' ' << j << ' ' << p << ' ' << t << ' ' << x << ' ' << y << endl;

                if(p <= m && (used[p] == 0 || used2[p] > used2[j] + 1))
                {
                    if(used[p] == 0)
                        ans[p] = i + 1;

                    used[p] = 1;
                    used2[p] = used2[j] + 1;
                }
            }

        for(int j = 0; j <= m; j++)
        {
            if(used[j])
                used2[j] = 0;
            else used2[j] = 1e9;
        }
    }

    for(int i = 1; i <= m; i++)
    {
        if(ans[i] == 0)
            cout << "-1 ";
        else cout << ans[i] << ' ';
    }
}