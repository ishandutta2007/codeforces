#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
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

        int f = 0, F = 1;

        for(int i = 0; i < n - 1; i++)
        {
            if(a[i] > a[i + 1])
                f = 1;

            if(a[i] < a[i + 1] && f)
                F = 0;
        }

        cout << (F ? "YES\n" : "NO\n");
    }
}