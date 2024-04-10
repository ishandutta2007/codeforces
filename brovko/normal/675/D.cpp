#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 eohfweoifhew
#define y0 wepfjwewpjfef

using namespace std;

int n, a[100005], b[100005], t[100005], c[100005];
map <int, int> m;

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i <= n; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        b[i] = a[i];

    sort(b, b + n);

    for(int i = 0; i < n; i++)
        m[b[i]] = i + 1;

    for(int i = 0; i < n; i++)
        c[m[a[i]]] = i;

    inc(m[a[0]], 1);

    for(int i = 1; i < n; i++)
    {
        int x = m[a[i]];

        int L = 1;
        int R = x;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(sum(x) - sum(M - 1) > 0)
                L = M;
            else R = M;
        }

        int l = L;

        L = x;
        R = n;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(sum(M) - sum(x) > 0)
                R = M;
            else L = M;
        }

        int r = R;

        if(sum(x) == sum(l - 1))
            cout << b[r - 1];

        else if(sum(x) == sum(r))
            cout << b[l - 1];

        else
        {
            if(c[r] > c[l])
                cout << b[r - 1];
            else cout << b[l - 1];
        }

        cout << ' ';

        inc(m[a[i]], 1);
    }
}