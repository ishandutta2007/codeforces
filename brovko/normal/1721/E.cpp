#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

const li MOD = 1111111111111111111;
const li p = 1e6 + 3;
const int INF = 1e9 + 7;

li add(li x, li y)
{
    x += y;

    return (x >= MOD ? x - MOD : x);
}

li mul(li x, li y)
{
    li q = (ld) x * y / MOD;
    li r = x * y - q * MOD;

    while(r < 0)
        r += MOD;

    while(r >= MOD)
        r -= MOD;

    return r;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    vector <int> z(n);

    int l = 0, r = 0;

    for(int i = 1; i < n; i++)
    {
        if(i < r)
            z[i] = min(r - i, z[i - l]);

        while(i + z[i] < n && s[i + z[i]] == s[z[i]])
        {
            l = i;
            r++;
            z[i]++;
        }
    }

    map <li, int> mp;

    for(int i = 0; i < n; i++)
        if(i + z[i] == n)
        {
            string suf = "";
//             = s.substr(z[i], min(n - z[i], 10));

            int x = z[i];

            while(suf.size() < 10)
            {
                suf += s[x];
                x++;

                if(x == n)
                    x = z[i];
            }

            li H = 0;

            for(int j = 0; j < suf.size(); j++)
            {
                H = add(mul(H, p), suf[j]);
                mp[H] = min(mp[H], -INF + i);
            }
        }

    int q;
    cin >> q;

    while(q--)
    {
        string t;
        cin >> t;

        int m = t.size();

        vector <int> ans(m);

        li H = 0;

        for(int i = 0; i < m; i++)
        {
            H = add(mul(H, p), t[i]);
            ans[i] = n - (mp[H] + INF) + i + 1;
        }

//        for(int i = 0; i < m; i++)
//            cout << max(0, ans[i]) << ' ';
//
//        cout << "\n";

        for(int i = 0; i < m; i++)
        {
            int x = 0;
            int y = i;

            while(y < m && (x < n ? s[x] : t[x - n]) == t[y])
            {
                ans[y] = max(ans[y], x + 1);
                x++;
                y++;
            }
        }

        for(int i = 0; i < m; i++)
            cout << max(0, ans[i]) << ' ';

        cout << "\n";
    }
}

/*
aba
1
bababa

*/