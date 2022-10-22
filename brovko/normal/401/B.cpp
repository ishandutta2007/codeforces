#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int x, k, used[4005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x >> k;

    while(k--)
    {
        int t;
        cin >> t;

        if(t == 1)
        {
            int x, y;
            cin >> x >> y;

            used[x] = 1;
            used[y] = 1;
        }
        else
        {
            int x;
            cin >> x;

            used[x] = 1;
        }
    }

    int Max = 0, Min = 0;

    for(int i = 1; i < x; i++)
    {
        if(used[i] == 0)
            Max++;
    }

    for(int i = 1; i < x; i++)
    {
        if(used[i] == 0)
        {
            Min++;
            used[i + 1] = 1;
        }
    }

    cout << Min << ' ' << Max;
}