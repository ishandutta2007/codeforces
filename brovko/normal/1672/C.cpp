#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int Min = 1e9, Max = -1e9;

        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] == a[i + 1])
            {
                Min = min(Min, i);
                Max = max(Max, i);
            }
        }

        if(Min == 1e9 || Min == Max)
            cout << "0\n";
        else cout << max(1ll, Max - Min - 1) << "\n";
    }
}