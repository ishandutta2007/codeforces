#include <bits/stdc++.h>
//#define int long long
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

        int k = 0;

        for(int i = 0; i < n; i++)
            if(a[i] < 0)
                k++;

        for(int i = 0; i < n; i++)
            if(i < k)
                a[i] = -abs(a[i]);
            else a[i] = abs(a[i]);

        bool F = 1;

        for(int i = 0; i < n - 1; i++)
            if(a[i] > a[i + 1])
                F = 0;

        cout << (F ? "YES\n" : "NO\n");
    }
}