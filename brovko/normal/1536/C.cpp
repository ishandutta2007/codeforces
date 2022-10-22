#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n;
string s;

int gcd(int x, int y)
{
    if(x == 0)
        return y;

    return gcd(y % x, x);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        map <pair <int, int>, int> m;

        int kc = 0, kd = 0;

        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'K')
                kc++;
            else kd++;

            int g = gcd(kc, kd);
            pair <int, int> p = {kc / g, kd / g};

            m[p]++;
            cout << m[p] << ' ';
        }

        cout << "\n";
    }
}