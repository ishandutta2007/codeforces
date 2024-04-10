#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, a[1000005], t[1000005];

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

    cin >> n >> m;

    for(int i = 0; i < m; i++)
        cin >> a[i];

    vector <int> v;

    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if(x == -1)
        {
            vector <int> u;

            for(int j = 0; (j < m && v.size() - sum(n - 1) >= a[j]); j++)
            {
                int L = -1, R = v.size();

                while(R - L > 1)
                {
                    int M = (L + R) / 2;

                    if(M + 1 - sum(M) >= a[j])
                        R = M;
                    else L = M;
                }

                v[R] = -1;
                u.pb(R);
            }

            for(auto z:u)
                inc(z, 1);
        }
        else
        {
            v.pb(x);
        }
    }

    for(auto x:v)
        if(x != -1)
            cout << x;

    if(sum(n - 1) == v.size())
        cout << "Poor stack!";
}