#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, a[1000005], b[1005], used[1005];
queue <int> q;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        b[a[i]] = 1;
    }

    q.push(n);

    while(!q.empty())
    {
        int x = q.front();
        int y = used[x];

        if(x == n && y > 0)
        {
            cout << y;
            return 0;
        }

        for(int i = 0; i < 1005; i++)
            if(b[i] == 1 && x + i - n >= 0 && x + i - n <= 1000 && used[x + i - n] == 0)
        {
            used[x + i - n] = y + 1;
            q.push(x + i - n);
        }

        q.pop();
    }

    cout << -1;
}