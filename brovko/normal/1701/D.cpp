#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

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

        vector <int> l(n), r(n);

        for(int i = 0; i < n; i++)
        {
            l[i] = (i + 1) / (a[i] + 1) + 1;
            r[i] = (a[i] == 0 ? n : (i + 1) / a[i]);
        }

//        {
//            vector <int> L(n, 1e9), R(n, -1e9);
//
//            for(int i = 0; i < n; i++)
//            {
//                for(int j = 1; j <= n; j++)
//                    if((i + 1) / j == a[i])
//                    {
//                        L[i] = min(L[i], j);
//                        R[i] = max(R[i], j);
//                    }
//
//                cout << l[i] << ' ' << r[i] << ' ' << L[i] << ' ' << R[i] << endl;
//            }
//
//        }

        vector <pair <int, int> > v;

        for(int i = 0; i < n; i++)
            v.pb({l[i], i});

        sort(v.begin(), v.end());

        set <pair <int, int> > st;

        int x = 0;
        vector <int> ans(n);

        for(int i = 1; i <= n; i++)
        {
            while(x < n && v[x].f == i)
            {
                st.insert({r[v[x].s], v[x].s});
                x++;
            }

            pair <int, int> p = (*st.begin());
            st.erase(p);
            ans[p.s] = i;
        }

        for(int i = 0; i < n; i++)
            cout << ans[i] << ' ';

        cout << "\n";
    }
}