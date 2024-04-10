#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int k, N, q, t[2000005];
string s;

void update(int pos, char val)
{
    s[pos] = val;

    while(pos > 0)
    {
        t[pos] = 0;

        if(s[pos] != '0')
            t[pos] += t[2 * pos + 1];

        if(s[pos] != '1')
            t[pos] += t[2 * pos + 2];

        pos = (pos - 1) / 2;
    }

    t[pos] = 0;

    if(s[pos] != '0')
        t[pos] += t[2 * pos + 1];

    if(s[pos] != '1')
        t[pos] += t[2 * pos + 2];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> s;

    int N = (1ll << k) - 1;

    reverse(s.begin(), s.end());

    for(int i = N; i <= 2 * N; i++)
        t[i] = 1;

    for(int i = 0; i < N; i++)
        update(i, s[i]);

    cin >> q;

    while(q--)
    {
        int x;
        char y;
        cin >> x >> y;

        update(N - x, y);
        cout << t[0] << "\n";
    }
}