#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
//#define mp make_pair
#define pb push_back

using namespace std;

int t, n, q, a[100005], ps[100005];

map <int, int> mp;

void split(int l, int r)
{
    if(l > r)
        return;

    if(a[l] == a[r])
    {
        mp[ps[r + 1] - ps[l]] = 1;
        return;
    }

    int m = (a[l] + a[r]) / 2;

    int L = l - 1, R = r + 1;

    while(R - L > 1)
    {
        int M = (L + R) / 2;

        if(a[M] > m)
            R = M;
        else L = M;
    }

    mp[ps[r + 1] - ps[l]] = 1;

    split(l, L);
    split(R, r);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> q;

        for(int i = 0; i < n; i++)
            cin >> a[i];

        sort(a, a + n);

        ps[0] = 0;

        for(int i = 0; i < n; i++)
            ps[i + 1] = ps[i] + a[i];

        mp.clear();

        split(0, n - 1);

        for(int i = 0; i < q; i++)
        {
            int x;
            cin >> x;

            if(mp[x])
                cout << "Yes\n";
            else cout << "No\n";
        }
    }
}