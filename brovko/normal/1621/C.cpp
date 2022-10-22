#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int p[10005];

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

        int used[n] = {0};

        for(int i = 0; i < n; i++)
            if(used[i] == 0)
            {
                vector <int> v;

                while(v.size() < 2 || v[0] != v.back())
                {
                    cout << "? " << i + 1 << endl;

                    int x;
                    cin >> x;

                    x--;
                    used[x] = 1;

                    v.pb(x);
                }

                for(int i = 1; i < v.size(); i++)
                    p[v[i - 1]] = v[i];
            }

        cout << "! ";

        for(int i = 0; i < n; i++)
            cout << p[i] + 1 << ' ';

        cout << endl;
    }
}