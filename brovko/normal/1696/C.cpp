#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;

vector <pair <int, int> > f(vector <int> a, int m)
{
    vector <pair <int, int> > ans;

    int x = -1, k = -1;

    for(int i = 0; i < a.size(); i++)
    {
        int c = 1;

        while(a[i] % m == 0)
        {
            a[i] /= m;
            c *= m;
        }

        if(x == -1 || k == -1)
        {
            x = a[i];
            k = c;
        }
        else if(x == a[i])
        {
            k += c;
        }
        else
        {
            ans.pb({x, k});
            x = a[i];
            k = c;
        }
    }

    ans.pb({x, k});
    return ans;
}

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

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        int k;
        cin >> k;

        vector <int> b(k);

        for(int i = 0; i < k; i++)
            cin >> b[i];

        if(f(a, m) == f(b, m))
            cout << "Yes\n";
        else cout << "No\n";
    }
}