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

        sort(a.begin(), a.end());

        int k = 0, Max = 0;

        for(int i = 0; i < n; i++)
        {
            if(i == 0 || a[i] != a[i - 1])
                k = 1;
            else k++;

            Max = max(Max, k);
        }

        int knew = 0;
        int m = Max;

        while(Max < n)
        {
            Max *= 2;
            knew++;
        }

        cout << knew + (n - m) << "\n";
    }
}