#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

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

        int x = 0, y = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> a[i];

            if(a[i] % 2)
                x++;
            else y++;
        }

        cout << min(x, y) << "\n";
    }
}