#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define mp make_pair

using namespace std;

int n, A, cf, cm, m, a[100005], b[100005], ps[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> A >> cf >> cm >> m;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[i] = a[i];

    sort(b, b + n);

    for(int i = 0; i < n; i++)
        ps[i + 1] = ps[i] + b[i];

    int ans = 0, kf = 0, Min = 0;

    for(int i = 0; i <= n; i++)
    {
        int f = (n - i) * A - (ps[n] - ps[i]);
        int x = (n - i) * cf;

        int L = 0, R = A + 1;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            int l = -1, r = i;

            while(r - l > 1)
            {
                int m = (l + r) / 2;

                if(b[m] <= M)
                    l = m;
                else r = m;
            }

            if(M * r - ps[r] + f <= m)
                L = M;
            else R = M;
        }

        x += L * cm;

        if(f <= m && x > ans)
        {
            ans = x;
            kf = n - i;
            Min = L;
        }
    }

    vector <pair <int, int> > v;

    for(int i = 0; i < n; i++)
    {
        v.pb({a[i], i});
    }

    sort(v.rbegin(), v.rend());

    for(int i = 0; i < kf; i++)
        a[v[i].y] = A;

    cout << ans << "\n";

    for(int i = 0; i < n; i++)
        cout << max(a[i], Min) << ' ';
}

/*
5 100 1000 1 10
99 98 97 1 2

*/