#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, p[1005], used[1005], k[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=2; i<=n; i++)
    {
        cin >> p[i];
        used[p[i]]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(used[i] == 0)
            k[p[i]]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(used[i] > 0 && k[i] < 3)
        {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
}