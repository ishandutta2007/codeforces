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

        vector <int> b(n);

        for(int i = 0; i < n; i++)
            cin >> b[i];

        map <int, int> m;

        int x = 0;

        for(int i = 0; i < n; i++)
        {
            if(x < n && b[x] == a[i])
            {
                x++;

                while(x < n && b[x] == a[i] && m[a[i]] > 0)
                {
                    m[a[i]]--;
                    x++;
                }
            }
            else
            {
                m[a[i]]++;
            }
        }

        if(x == n)
            cout << "YES\n";
        else cout << "NO\n";
    }
}