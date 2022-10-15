#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

const int N = (1 << 18) + 7;
const int INF = (int) 1e18;
int n;
int a[N];
int p;
int w[N];
vector<int> vals[100];

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] == -1)
        {
            p = i;
        }
    }
    for (int i = 1; i <= p; i++)
    {
        a[i] = 0;
    }
    w[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        w[i] = 1 + w[i / 2];
    }
    for (int i = 1; i <= n; i++)
    {
        vals[w[i]].push_back(a[i]);
    }
    multiset<int> all;
    int ans = 0;
    for (int i = w[n]; i >= 1; i--)
    {
        for (auto &x : vals[i])
        {
            all.insert(x);
        }
        ans += *all.begin();
        all.erase(all.begin());
    }
    cout << ans << "\n";
}