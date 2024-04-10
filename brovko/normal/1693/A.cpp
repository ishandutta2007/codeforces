#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

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

        int L = 0, R = n - 1;

        while(L < R && a[R] == 0)
            R--;

        a[L]--;
        a[R]++;

        li s = 0;
        int F = 1;

        for(int i = 0; i < n; i++)
        {
            s += a[i];

            if(s < 0)
                F = 0;
        }

        if(s)
            F = 0;

        cout << (F ? "Yes\n" : "No\n");
    }
}