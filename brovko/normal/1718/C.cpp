#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
const int N = 2e5 + 5;

vector <int> D[N];
bool np[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i < N; i++)
        if(np[i] == 0)
            for(int j = i * i; j < N; j += i)
                np[j] = 1;

    for(int i = 1; i < N; i++)
        for(int j = i + i; j < N; j += i)
            if(np[j / i] == 0)
                D[j].pb(i);

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector <int> divs = D[n];

//        for(int i = 1; i * i <= n; i++)
//        {
//            if(n % i == 0)
//            {
//                divs.pb(i);
//
//                if(i * i != n && i != 1)
//                    divs.pb(n / i);
//            }
//        }

        int q;
        cin >> q;

        vector <int> a(n);

        for(int i = 0; i < n; i++)
            cin >> a[i];

        vector <vector <int> > v(divs.size());

        for(int i = 0; i < divs.size(); i++)
            v[i].resize(divs[i]);

        set <pair <int, pair <int, int> > > st;

        for(int i = 0; i < divs.size(); i++)
            for(int j = 0; j < n; j++)
            {
                v[i][j % divs[i]] += a[j];
            }

        for(int i = 0; i < divs.size(); i++)
            for(int j = 0; j < divs[i]; j++)
            {
                st.insert({v[i][j] * divs[i], {i, j}});
            }

//        for(auto x:st)
//            cout << x.f << ' ';
//
//        cout << endl;

        int ans = (*st.rbegin()).f;

        cout << ans << "\n";

        while(q--)
        {
            int i, x;
            cin >> i >> x;

            i--;

            int delta = x - a[i];

            a[i] = x;

            for(int p = 0; p < divs.size(); p++)
            {
                int d = divs[p];
                int r = i % d;

                st.erase({v[p][r] * d, {p, r}});

                v[p][r] += delta;

                st.insert({v[p][r] * d, {p, r}});
            }

            cout << (*st.rbegin()).f << "\n";
        }
    }
}

/*
1
4 1
4 1 3 2
2 6

*/