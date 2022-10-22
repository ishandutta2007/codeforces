#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m;
char a[1005][1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    set <int> q;

    for(int i = 0; i < n; i++)
    {
        int x = 0;

        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == 'G')
                x -= j;

            if(a[i][j] == 'S')
                x += j;
        }

        if(x < 0)
        {
            cout << -1;
            return 0;
        }

        q.insert(x);
    }

    cout << q.size();
}