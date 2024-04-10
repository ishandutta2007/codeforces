#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, q, a[200005];
set <int> s, d;
map <int, int> kd, l, r;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);

    for(int i = 0; i < n; i++)
        s.insert(a[i]);

    for(int i = 0; i < n - 1; i++)
    {
        r[a[i]] = a[i + 1];
        l[a[i + 1]] = a[i];

        d.insert(a[i + 1] - a[i]);
        kd[a[i + 1] - a[i]]++;
    }

    r[a[n - 1]] = 1e18;
    l[a[0]] = -1e18;

    if(s.size() == 0)
        cout << "0\n";
    else
    {
        int dr = 0;

        if(d.size() > 0)
            dr = *(d.rbegin());

        cout << *(s.rbegin()) - *(s.begin()) - dr << "\n";
    }

    while(q--)
    {
        int t, x;
        cin >> t >> x;

        if(t == 1)
        {
            if(s.size() == 0)
            {
                s.insert(x);
                l[x] = -1e18;
                r[x] = 1e18;
            }
            else {
            if(x > *(s.rbegin()))
            {
                r[*(s.rbegin())] = x;
                l[x] = *(s.rbegin());
                r[x] = 1e18;
            }
            else
            {
                int y = *(s.upper_bound(x));

                r[x] = y;
                l[x] = l[y];
                l[y] = x;
                r[l[x]] = x;
            }
            }

            s.insert(x);

            int R = r[x], L = l[x];

            if(R != 1e18 && L != -1e18)
            {
                kd[R - L]--;

                if(kd[R - L] == 0)
                    d.erase(R - L);
            }

            if(R != 1e18)
            {
                d.insert(R - x);
                kd[R - x]++;
            }

            if(L != -1e18)
            {
                d.insert(x - L);
                kd[x - L]++;
            }
        }
        else
        {
            s.erase(x);

            int L = l[x], R = r[x];

            r[L] = R;
            l[R] = L;

            if(L != -1e18)
            {
                kd[x - L]--;

                if(kd[x - L] == 0)
                    d.erase(x - L);
            }

            if(R != 1e18)
            {
                kd[R - x]--;

                if(kd[R - x] == 0)
                    d.erase(R - x);
            }

            if(L != -1e18 && R != 1e18)
            {
                kd[R - L]++;
                d.insert(R - L);
            }
        }

//        cout << 1 << endl;

        if(s.size() == 0)
            cout << "0\n";
        else
        {
            int dr = 0;

            if(d.size() > 0)
                dr = *(d.rbegin());

            cout << *(s.rbegin()) - *(s.begin()) - dr << "\n";
        }
    }
}