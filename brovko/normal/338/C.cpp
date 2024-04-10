#include <bits/stdc++.h>
#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int n, sw, ans, k;
li a[8], w[8];
vector <int> v;

void rec(int d)
{
    if(sw >= ans)
        return;

    if(d == n)
    {
        vector <int> p(n);

        for(int i = 0; i < n; i++)
            p[i] = a[i];

        for(int i = 0; i < n; i++)
            if(v[i] != -1)
            {
                if(p[v[i]] % a[i])
                    return;

                p[v[i]] /= a[i];
            }

        ans = sw;

        return;
    }

    for(int i = -1; i < n; i++)
        if(i == -1 || a[i] > a[d])
        {
            v.pb(i);

            if(i == -1)
            {
                sw += w[d];
                k++;

                if(k == 2)
                    sw++;
            }

            rec(d + 1);

            if(i == -1)
            {
                sw -= w[d];
                k--;

                if(k == 1)
                    sw--;
            }

            v.pop_back();
        }
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
    {
        int x = a[i];

        for(int j = 2; j * j <= x; j++)
        {
            while(x % j == 0)
            {
                x /= j;
                w[i]++;
            }
        }

//        w[i]++;

        if(x > 1)
            w[i]++;

//        w[i] = 2 * w[i] + 1;
    }

//    for(int i = 0; i < n; i++)
//        cout << w[i] << ' ';
//
//    cout << endl;

    ans = 1e9;

    rec(0);

    int kp = 0;

    for(int i = 0; i < n; i++)
        if(w[i] == 1)
            kp++;

    cout << ans + n - kp;
}