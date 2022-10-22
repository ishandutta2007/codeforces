#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;

using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        vector <int> a(m);

        for(int i = 0; i < m; i++)
            cin >> a[i];

        sort(a.begin(), a.end());

        vector <int> v(m);

        for(int i = 0; i < m; i++)
            v[i] = (a[i] - a[(i - 1 + m) % m] + 100 * n - 1) % n;

        sort(v.rbegin(), v.rend());

        int k = 0, free = 0;

        for(auto x:v)
        {
            if(x - k >= 3)
            {
                free += x - k - 1;
                k += 4;
            }
            else if(x - k >= 1)
            {
                k += 2;
                free++;
            }
        }

        cout << n - free << "\n";
    }
}