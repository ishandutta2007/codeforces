#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k;
string a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < k; i++)
    {
        vector <int> v;

        for(int j = i; j < n + k; j += k)
        {
            if(j < n && a[j] == "?")
                v.pb(j);
            else if(v.size())
            {
                int x = -1e18;

                if(v[0] - k >= 0)
                    x = stoll(a[v[0] - k]);

                int y = 1e18;

                if(j < n)
                    y = stoll(a[j]);

                int pos = -((int)v.size() / 2);
                pos = max(pos, x + 1);
                pos = min(pos, y - v.size());

                for(int z = j - k * (int)v.size(); z < j; z += k)
                    a[z] = to_string(pos++);

                v.clear();
            }
        }
    }

    for(int i = k; i < n; i++)
        if(stoll(a[i]) <= stoll(a[i - k]))
        {
            cout << "Incorrect sequence";
            return 0;
        }

    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}