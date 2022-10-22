#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, k, l[300005], r[300005], a[300005], t[300005], r2[300005];
vector <pair <int, int> > v;
map <int, int> q;

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i < n; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        r2[i] = r[i];

        v.push_back({l[i], r[i]});
    }

    sort(v.begin(), v.end());
    sort(r, r + n);

    int x = 0;

    for(int i = n - 1; i >= 0; i--)
    {
        if(i < n - 1 && r[i] < r[i + 1])
            x++;

        q[r[i]] = x;
        a[x] = r[i];
    }

    int Max = -2e9;
    int ind = 0;
    int lx = 0;

    for(int i = 0; i < n; i++)
    {
        lx = v[i].first;

        inc(q[v[i].second], 1);

        int L = -1;
        int R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(sum(M) >= k)
                R = M;
            else L = M;
        }

        int rx = a[R];

        if(rx - lx + 1 >= Max && R < n)
        {
            Max = rx - lx + 1;
            ind = lx;
        }
    }

    cout << max(0, Max) << "\n";

    for(int i = 0; i < n; i++)
    {
        if(l[i] <= ind && r2[i] - ind + 1 >= Max && k > 0)
        {
            k--;
            cout << i + 1 << ' ';
        }
    }
}