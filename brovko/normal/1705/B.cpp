#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

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

        int L = 0;

        while(L < n - 1 && a[L] == 0)
            L++;

        li ans = 0;

        for(int i = L; i < n - 1; i++)
        {
            ans += max(1, a[i]);
        }

        cout << ans << "\n";
    }
}