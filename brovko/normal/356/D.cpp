#include <bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

using li = long long;

using namespace std;
const int K = 8;

bitset <70005> B[70005 / K + 5];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, s;
    cin >> n >> s;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

//    if(n == 1)
//    {
//        if(s != a[0])
//            cout << -1;
//        else
//        {
//            cout << a[0] << ' ' << 0;
//        }
//
//        return 0;
//    }

    li sum = 0, Max = 0;

    for(int i = 0; i < n; i++)
    {
        sum += a[i];

        if(a[i] > a[Max])
            Max = i;
    }

    int vmax = a[Max];

    if(s > sum || s < vmax)
    {
        cout << -1;
        return 0;
    }

    for(int i = Max + 1; i < n; i++)
        a[i - 1] = a[i];

    a.pop_back();
    n--;

    bitset <70005> b;
    b[0] = 1;

    for(int i = 0; i < n; i++)
    {
        b |= (b << a[i]);

        if(i % K == K - 1)
            B[i / K] = b;
    }

    s -= vmax;

    if(s < 0 || b[s] == 0)
    {
        cout << -1;
        return 0;
    }

    int i = n - 1;

    vector <int> used(n);

    while(i >= 0)
    {
        int k = i % K + 1;

        for(int mask = 0; mask < (1 << k); mask++)
        {
            int S = 0;

            for(int j = 0; j < k; j++)
                if(mask & (1 << j))
                    S += a[i - j];

            if(S <= s && (s == S || i / K > 0 && B[i / K - 1][s - S] == 1))
            {
                for(int j = 0; j < k; j++)
                    if(mask & (1 << j))
                        used[i - j] = 1;

                s -= S;
                i -= k;
                break;
            }
        }
    }

    vector <pair <int, int> > nused;

    for(int i = 0; i < n; i++)
        if(used[i] == 0)
            nused.pb({a[i], (i < Max ? i : i + 1)});

    nused.pb({vmax, Max});

    sort(nused.rbegin(), nused.rend());

    vector <vector <int> > ans(n + 1);

    for(int i = 0; i < (int)nused.size() - 1; i++)
    {
        int j = nused[i].y;

        ans[j].pb(nused[i].x - nused[i + 1].x);
        ans[j].pb(1);
        ans[j].pb(nused[i + 1].y + 1);
    }

    for(int i = 0; i < n + 1; i++)
    {
        if(ans[i].size())
            for(auto x:ans[i])
                cout << x << ' ';
        else cout << (i == Max ? vmax : i > Max ? a[i - 1] : a[i]) << ' ' << 0;

        cout << "\n";
    }
}