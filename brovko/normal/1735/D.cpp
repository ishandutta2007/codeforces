#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int c[n][k];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < k; j++)
            cin >> c[i][j];

    vector <int> h(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < k; j++)
            h[i] = h[i] * 3 + c[i][j];

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        v.pb({h[i], i});
    }

    sort(v.begin(), v.end());
    v.pb({(int)1e9, 0});

    vector <int> cnt(n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < i; j++)
        {
            int H = 0;

            for(int p = 0; p < k; p++)
            {
                H = H * 3 + (300 - c[i][p] - c[j][p]) % 3;
            }

            int L = -1, R = (int)v.size() - 1;

            while(R - L > 1)
            {
                int M = (L + R) / 2;

                if(v[M].f >= H)
                    R = M;
                else L = M;
            }

//            if(i == 8 && j == 7)
//                cout << R << ' ' << v[R].f << ' ' << v[R].s << ' ' << H << endl;

            int ind = v[R].s;

            if(h[ind] == H && ind < j)
                cnt[i]++, cnt[j]++, cnt[ind]++;
        }

//    for(int i = 0; i < n; i++)
//        cout << cnt[i] << ' ';
//
//    cout << endl;

    li ans = 0;

    for(int i = 0; i < n; i++)
        ans += cnt[i] * 1ll * (cnt[i] - 1) / 2;

    cout << ans;
}