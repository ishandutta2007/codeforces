#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, x, a[505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> x;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int r = n - 1;

        while(r > 0 && a[r - 1] <= a[r])
            r--;

        int ans = 0;

        for(int i = 0; i < r; i++)
        {
            if(a[i] > x)
            {
                ans++;
                swap(a[i], x);
            }
        }

//        for(int i = 0; i < n; i++)
//            cout << a[i] << ' ';
//
//        cout << endl;

        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1])
                ans = -1;

        cout << ans << "\n";
    }
}

/*

1
4 1
2 3 5 4

*/