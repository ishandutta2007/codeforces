#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, p[3005], c[3005];

void update()
{
    for(int i = 0; i < n; i++)
        c[i] = -1;

    for(int i = 0; i < n; i++)
        if(c[i] == -1)
        {
            int j = i;

            while(c[j] == -1)
            {
                c[j] = i;
                j = p[j];
            }
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[i]--;
    }

    cin >> m;

    m = n - m;

    update();

    int cnt = 0;

    for(int i = 0; i < n; i++)
        if(i == c[i])
            cnt++;

    cout << abs(m - cnt) << "\n";

    while(cnt != m)
    {
        if(cnt > m)
        {
            cnt--;
            update();

            int x = 0;

            while(x != c[x])
                x++;

            int y = x + 1;

            while(y != c[y])
                y++;

            cout << x + 1 << ' ' << y + 1 << ' ';
            swap(p[x], p[y]);
        }
        else
        {
            cnt++;
            int x = 0;

            while(x == p[x])
                x++;

            int j = p[x], Min = 1e9;

            while(j != x)
            {
                Min = min(Min, j);
                j = p[j];
            }

            cout << x + 1 << ' ' << Min + 1 << ' ';
            swap(p[x], p[Min]);
        }
    }
}