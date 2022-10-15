#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 1e5 + 7;
int n, m;
vector <int> a[N]; /// mare -> mic
int d[N];

ll sum = 0;

ll get(int i)
{
    return (ll) a[i].size() * (d[i] - a[i].size());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        d[x]++;
        d[y]++;
        if (x < y)
            a[x].push_back(y);
        else
            a[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        sum += get(i);
    cout << sum << "\n";
    int q;
    cin >> q;

    while (q--)
    {
        int i;
        cin >> i;
        sum -= get(i);
        for (auto &j : a[i])
        {
            sum -= get(j);
            a[j].push_back(i);
            sum += get(j);
        }
        cout << sum << "\n";
        a[i].clear();
    }


    return 0;
}