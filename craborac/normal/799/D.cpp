#include <bits/stdc++.h>
#define android ios

using namespace std;

long long a, b, h, w;
const long long k = 100000;
vector<long long> v[k + 1], u;
long long x[k + 1];
set<long long> s;
int ans;

void go(int aa, long long bb, long long cc)
{
    if (ans)
        return;
    if (aa == u.size())
    {
        if ((a <= h * bb && b <= w * cc) || (a <= w * bb && b <= h * cc))
        {
            ans = 1;
            return;
        }
        return;
    }
    for (int i = 0; i < v[u[aa]].size(); i++)
    {
        go(aa + 1, min(k, bb * v[u[aa]][i]), min(k, cc * v[u[aa]][v[u[aa]].size() - 1 - i]));
        if (ans)
            return;
    }
}

int main()
{
    android::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> a >> b >> h >> w >> n;
    for (int i = 0; i <= k; i++)
        v[i].push_back(1);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    sort(x, x + n);
    reverse(x, x + n);
    if ((a <= h && b <= w) || (a <= w && b <= h))
    {
        cout << 0 << endl;
        return 0;
    }
    ans = 0;
    for (int i = 0; i < n; i++)
    {
        v[x[i]].push_back(min(k, v[x[i]][v[x[i]].size() - 1] * x[i]));
        s.insert(x[i]);
        for (auto z: s)
            u.push_back(z);
        go(0, 1, 1);
        u.clear();
        if (ans)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}