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

        int x = 0;

        while(x * x < n - 1)
            x++;

        vector <int> a(n);

        while(n > 0)
        {
            for(int i = n - 1; i >= x * x - (n - 1); i--)
                a[i] = x * x - i;

            n = x * x - n + 1;

            while(x >= 0 && x * x >= n - 1)
                x--;

            x++;

//            cout << x << endl;
        }

        for(auto x:a)
            cout << x << ' ';

        cout << "\n";
    }
}