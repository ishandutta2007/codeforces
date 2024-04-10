#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1000 + 7;
int n, x[N], y[N];

struct Line
{
    int a;
    int b;
    int c;
};

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a % b);
}

Line get(int x1, int y1, int x2, int y2)
{
    int a = y2 - y1;
    int b = x1 - x2;
    int c = -(a * x1 + b * y1);

    int fa = abs(a);
    int fb = abs(b);
    int fc = abs(c);
    int g = gcd(fa, gcd(fb, fc));

    if (g > 0)
    {
        a /= g;
        b /= g;
        c /= g;
    }
    if (a < 0)
    {
        a *= -1;
        b *= -1;
        c *= -1;
    }
    return {a, b, c};
}

bool operator < (Line f, Line s)
{
    return f.a * (ll) s.b < f.b * (ll) s.a;
}

map <Line, int> ugar;

struct Line2
{
    int a;
    int b;
    int c;
};

bool operator < (Line2 f, Line2 s)
{
    if (f.a != s.a) return (f.a < s.a);
    if (f.b != s.b) return (f.b < s.b);
    return (f.c < s.c);
}

map <Line2, int> seen;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }

    ll kurd = 0LL;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            Line slav = get(x[i], y[i], x[j], y[j]);
            Line2 slav2 = {slav.a, slav.b, slav.c};
            if (seen[slav2] == 0)
            {
                kurd++;
                seen[slav2] = 1;
                ugar[slav]++;
            }
        }
    }

    ll turkish_pakistan_kolbar = 0LL;

    for (auto &it : ugar)
    {
        ll now = it.second;
        turkish_pakistan_kolbar += now * (now - 1) / 2;
    }

    ll total = kurd * (kurd - 1) / 2;

    ll good = total - turkish_pakistan_kolbar;

    cout << good << "\n";

    return 0;
}