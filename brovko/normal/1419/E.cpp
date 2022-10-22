#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, cnt[200005], k;
vector <int> p, ans[200005];
map <int, int> q;

void rec(int x, int i, int lp)
{
    if(i == k && q[x] == 0)
    {
        ans[lp].pb(x);

    }

//    cout << x << ' ' << i << ' ' << lp << ' ' << k << ' ' << q[x] << endl;

    if(i == k)
        return;

    rec(x, i + 1, lp);

    for(int j = 1; j <= cnt[i]; j++)
    {
        x *= p[i];

        rec(x, i + 1, min(lp, i));
    }
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        p.clear();

        int m = n;

        for(int i = 2; i * i <= m; i++)
        {
            if(m % i == 0)
            {
                p.pb(i);

                cnt[p.size() - 1] = 0;

                while(m % i == 0)
                {
                    m /= i;
                    cnt[p.size() - 1]++;
                }
            }
        }

        if(m > 1)
        {
            p.pb(m);
            cnt[p.size() - 1] = 1;
        }

        k = p.size();

        q.clear();
        q[1] = 1;

        for(int i = 0; i < k; i++)
            ans[i].clear();

        if(p.size() != 2)
        {
            for(int i = 0; i < k; i++)
            {
                q[p[i]] = 1;

                if(k != 1)
                    q[p[i] * p[(i + 1) % k]] = 1;
            }

            m = n;

            rec(1, 0, 1e9);

//            for(int i = 0; i < k; i++)
//            {
//                cout << p[i] << ' ';
//
//                for(auto to:ans[i])
//                    cout << to << ' ';
//
//                cout << endl;
//            }

            for(int i = 0; i < k; i++)
            {
                cout << p[i] << ' ';

                for(auto to:ans[i])
                    cout << to << ' ';

                if(k != 1)
                    cout << p[i] * p[(i + 1) % k] << ' ';
            }

            cout << "\n0\n";
        }
        else
        {
            q[p[0] * p[1]] = 1;
            q[p[0]] = 1;
            q[p[1]] = 1;

            rec(1, 0, 1e9);

            cout << p[0] << ' ' << p[0] * p[1] << ' ' << p[1] << ' ';

            for(auto to:ans[1])
                cout << to << ' ';

            for(int i = ans[0].size() - 1; i >= 0; i--)
                cout << ans[0][i] << ' ';

            cout << "\n";

            if(cnt[0] + cnt[1] == 2)
                cout << 1;
            else cout << 0;

            cout << "\n";
        }
    }
}