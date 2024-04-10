#include <bits/stdc++.h>

using namespace std;

struct kek
{
    long long a, b, c, d;
    kek(long long a_ = 0, long long b_ = 0, long long c_ = 0, long long d_ = 0): a(a_), b(b_), c(c_), d(d_) {};
    bool operator < (const kek k)const
    {
        if (a != k.a)
            return a < k.a;
        return c < k.c;
    }
};

vector<kek> mas;
long long d[(int)1e5 + 10], f[(int)1e5 + 10], t[(int)1e5 + 10], c[(int)1e5 + 10];
long long ans1[(int)1e5 + 10], cur[(int)1e5 + 10];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> d[i] >> f[i] >> t[i] >> c[i];
        if (f[i] == 0)
            mas.push_back(kek(d[i] - k - 1, t[i] - 1, 1, c[i]));
        else
            mas.push_back(kek(d[i], f[i] - 1, 0, c[i]));
    }
    long long mx = (long long)1e12;
    fill(cur, cur + n, mx);
    long long sum = n * mx;
    sort(mas.begin(), mas.end());
    for (int i = 0; i < m; i++)
    {
        if (mas[i].c == 0)
        {
            sum -= cur[mas[i].b];
            cur[mas[i].b] = min(cur[mas[i].b], mas[i].d);
            sum += cur[mas[i].b];
        }
        ans1[i] = sum;
    }
    long long ans = mx;
    fill(cur, cur + n, mx);
    sum = n * mx;
    for (int i = m - 1; i >= 0; i--)
    {
        if (mas[i].c == 1)
        {
            sum -= cur[mas[i].b];
            cur[mas[i].b] = min(cur[mas[i].b], mas[i].d);
            sum += cur[mas[i].b];
        }
        ans = min(ans, ans1[i] + sum);
    }
    if (ans > (long long)4e11)
        ans = -1;
    cout << ans << endl;
    return 0;
}