#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[2005], used[2005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    int k = n / m;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];

        if(a[i] <= m)
            used[a[i]]++;
    }

    int x = 1;
    int y = 0;

    for(int i = 0; i < n; i++)
    {
        while(used[x] >= k)
            x++;

        if((a[i] > m || used[a[i]] > k) && x <= m)
        {
            if(a[i] <= m)
                used[a[i]]--;

            used[x]++;
            a[i] = x;
            y++;
        }
    }

    cout << k << ' ' << y << "\n";

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}