#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define y1 eohfweoifhew

using namespace std;

int q, t[200005], a[200005], x[200005], y;
char c[200005];
map <int, int> m;
vector <int> v;

int sum(int r)
{
    int ans = 0;

    for(; r >= 0; r = (r & r + 1) - 1)
        ans += t[r];

    return ans;
}

void inc(int i, int d)
{
    for(; i < y; i = (i | i + 1))
        t[i] += d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> q;

    for(int i = 0; i < q; i++)
    {
        cin >> c[i] >> x[i];

        if(c[i] == '+')
            v.push_back(x[i]);
    }

    v.push_back(0);
    sort(v.begin(), v.end());

    y = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if(i == 0 || v[i] != v[i - 1])
        {
            m[v[i]] = y;
            a[y] = v[i];
            y++;
        }
    }

    inc(0, 1);

    for(int i = 0; i < q; i++)
    {
        if(c[i] == '+')
            inc(m[x[i]], 1);

        if(c[i] == '-')
            inc(m[x[i]], -1);

        if(c[i] == '?')
        {
            int l = 0;
            int r = y - 1;
            int s = 0;

            for(int j = 30; j >= 0; j--)
            {
                int L = l - 1;
                int R = r + 1;

                while(R - L > 1)
                {
                    int M = (L + R) / 2;

                    if(a[M] >= s + (1 << j))
                        R = M;
                    else L = M;
                }

                if(((1 << j) & x[i]) > 0)
                {
                    if(sum(R - 1) - sum(l - 1) == 0)
                    {
                        s += (1ll << j);
                    }
                    else
                    {
                        r = R - 1;
                    }
                }
                else
                {
                    if(sum(r) - sum(R - 1) == 0);
                    else
                    {
                        l = R;
                        s += (1ll << j);
                    }
                }
            }

            cout << (s ^ x[i]) << "\n";
        }
    }
}