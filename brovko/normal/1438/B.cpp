#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, b[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> b[i];

        int f = 0;

        map <int, int> m;

        for(int i = 0; i < n; i++)
        {
            m[b[i]]++;

            if(m[b[i]] == 2)
                f = 1;
        }

        if(f)
            cout << "YES\n";
        else cout << "NO\n";
    }
}