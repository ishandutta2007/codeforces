#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, a[105][105];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        int s = 0;

        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];

            if(a[i][j] % 2)
                s++;
        }

        if(s == 1)
            v.pb(i + 1);
    }

    cout << v.size() << "\n";

    for(auto x:v)
        cout << x << ' ';
}