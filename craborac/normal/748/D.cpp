#include <bits/stdc++.h>

using namespace std;

struct kek
{
    long long p1, p2;
    int a, b;
    kek(long long p1_ = 0, long long p2_ = 0, int a_ = 0, int b_ = 0): p1(p1_), p2(p2_), a(a_), b(b_) {}
    bool operator <(const kek c)const
    {
        if (p1 != c.p1)
            return p1 < c.p1;
        if (p2 != c.p2)
            return p2 < c.p2;
        if (a != c.a)
            return a > c.a;
        return b < c.b;
    }
};

const long long p = 239;
const long long mod = (long long)1e9 + 7;
string s[(int)1e5 + 10];
long long p1[(int)1e5 + 10], p2[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    set<kek> se;
    vector<kek> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> s[i] >> a;
        p1[i] = 0, p2[i] = 0;
        for (int j = 0; j < m; j++)
            p1[i] = (p1[i] * p + s[i][j]) % mod;
        for (int j = m - 1; j >= 0; j--)
            p2[i] = (p2[i] * p + s[i][j]) % mod;
        if (p1[i] == p2[i])
            v.push_back(kek(p1[i], p2[i], a, i));
        else
            se.insert(kek(p1[i], p2[i], a, i));
        //cout << p1[i] << " " << p2[i] << endl;
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (p1[i] != p2[i])
        {
            auto q = se.lower_bound({p1[i], p2[i], 20000, 0});
            auto w = se.lower_bound({p2[i], p1[i], 20000, 0});
            if (q != se.end() && w != se.end())
            {
                kek x = (*q);
                kek y = (*w);
                //cout << p1[i] << " " << p2[i] << " " << x.p1 << " " << x.p2 << " " << y.p1 << " " << y.p2;
                if (x.p1 == p1[i] && x.p2 == p2[i] && y.p1 == p2[i] && y.p2 == p1[i] && x.a + y.a > 0)
                {
                    ans += x.a + y.a;
                    se.erase(x);
                    se.erase(y);
                }
            }
        }
    }
    //cout << ans << endl;
    long long mx = 0;
    for (int i = 0; i < v.size();)
    {
        //cout << v[i].p1 << " " << ans << endl;
        int r = i;
        while (r < v.size() && v[i].p1 == v[r].p1 && v[i].p2 == v[r].p2)
            r++;
        int t = i;
        while (i + 2 <= r && v[i].a + v[i + 1].a > 0)
        {
            ans += v[i].a + v[i + 1].a;
            i += 2;
        }
        if (i > t)
            mx = max(mx, -(long long)v[i - 1].a);
        if (i < r)
            mx = max(mx, (long long)v[i].a);
        i = r;
    }
    ans += mx;
    cout << ans << endl;
    return 0;
}