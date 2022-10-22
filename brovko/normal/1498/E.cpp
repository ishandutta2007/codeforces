#include <bits/stdc++.h>
#define int long long

using namespace std;

int t, n, a[505];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    t = 1;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <pair <int, pair <int, int> > > v;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
        {
            if(a[i] < a[j])
                v.push_back({a[i] - a[j], {j, i}});
            else v.push_back({a[j] - a[i], {i, j}});
        }

        sort(v.begin(), v.end());

        int f = 0;

        for(auto to:v)
            if(f == 0)
        {
            cout << "? " << to.second.first + 1 << ' ' << to.second.second + 1 << endl;

            string s;
            cin >> s;

            if(s == "Yes")
            {
                f = 1;
                cout << "! " << to.second.first + 1 << ' ' << to.second.second + 1 << endl;
            }
        }

        if(f == 0)
            cout << "! 0 0" << endl;
    }
}