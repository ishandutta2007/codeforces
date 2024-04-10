#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, na, nb, nc;
vector<int> a, b, c;
vector<LL> sa, sb, sc;
int x;
LL ans = 0;
void sum(const vector<int> &a, vector<LL> &s, int n)
{
    s.resize(n);
    if (n == 0)
        return;
    s[0] = a[0];
    for (int i = 1; i < n; ++i)
        s[i] = s[i - 1] + a[i];
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int t, v;
        scanf("%d%d", &t, &v);
        switch (t) {
        case 0:
            c.push_back(v);
            break;
        case 1:
            b.push_back(v);
            break;
        case 10:
            a.push_back(v);
            break;
        case 11:
            ++x;
            ans += v;
            break;
        }
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    sort(c.begin(), c.end(), greater<int>());
    na = a.size();
    nb = b.size();
    nc = c.size();
    if (na < nb) {
        swap(na, nb);
        a.swap(b);
    }
    sum(a, sa, na);
    sum(b, sb, nb);
    sum(c, sc, nc);
    LL mx = 0;
    for (int y = 0; y <= x && y <= nc; ++y) {
        LL now = y == 0 ? 0 : sc[y - 1];
        int t = x - y;
        if (nb != 0)
            now += sb[nb - 1];
        if (na != 0 && nb + t != 0)
            now += sa[min(nb + t - 1, na - 1)];
        mx = max(now, mx);
    }
    ans += mx;
    cout << ans << endl;
    return 0;
}