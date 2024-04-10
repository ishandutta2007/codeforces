#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string a, b;
int pref[200005], suf[200005];

int getp(int x)
{
    if(x < 0)
        return -100;

    return pref[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> a >> b;

    int x = -1, n = a.size(), m = b.size();

    for(int i = 0; i < m; i++)
    {
        x++;

        while(x < n && b[i] != a[x])
            x++;

        if(x == n)
            x = 1e9;

        pref[i] = x;
    }

    suf[m] = n;
    suf[m + 1] = n;

    x = n;

    for(int i = m - 1; i >= 0; i--)
    {
        x--;

        while(x >= 0 && b[i] != a[x])
            x--;

        if(x == -1)
            x = -1e9;

        suf[i] = x;
    }

    int ans = 1e9;
    string s = "";

//    for(int i = 0; i <= m; i++)
//        cout << pref[i] << ' ' << suf[i] << endl;

    for(int l = 0; l < m; l++)
    {
        int L = l - 2, R = m;

        while(R - L > 1)
        {
            int M = (L + R) / 2;

            if(getp(l - 1) < suf[M + 1])
                R = M;
            else L = M;
        }

        if(getp(l - 1) < suf[R + 1] && R - l + 1 < ans)
        {
            ans = R - l + 1;

            s = b.substr(0, l) + b.substr(R + 1, m - R - 1);

//            if(s == "accepte")
//                cout << l << ' ' << R << endl;
        }
    }

    if(s == "")
        cout << '-';
    else cout << s;
}