#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, k, a, m, x[200005], used[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k >> a >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> x[i];
        x[i]--;
    }

    int L = -1, R = m;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        int cnt = 0, y = 0;

        for(int i = 0; i < n; i++)
            used[i] = 0;

        for(int i = 0; i <= M; i++)
            used[x[i]] = 1;

        for(int i = 0; i < n; i++)
        {
            if(used[i] == 0)
                y++;
            else
            {
                cnt += (y + 1) / (a + 1);
                y = 0;
            }
        }

        cnt += (y + 1) / (a + 1);

        if(cnt >= k)
            L = M;
        else R = M;
    }

    if(R == m)
        cout << -1;
    else cout << R + 1;
}