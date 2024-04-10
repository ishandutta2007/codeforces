#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[200005], c[200005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
    {
        if(a[i] % 2 != c[i] % 2)
        {
            c[i]++;
            c[i + 1]++;
        }

        if(a[i] < c[i] || c[n] > 0)
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}