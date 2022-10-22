#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, a[100005];

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
        int Min = 1e18;

        if(i > 0)
            Min = a[i] - a[i - 1];

        if(i < n - 1)
            Min = min(Min, a[i + 1] - a[i]);

        int Max = max(a[i] - a[0], a[n - 1] - a[i]);

        cout << Min << ' ' << Max << "\n";
    }


}