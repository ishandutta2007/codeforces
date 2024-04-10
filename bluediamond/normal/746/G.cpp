#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
int t;
int k;
int cnt[N];
int mn[N];
int mx[N];
vector<int> nodes[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t >> k;
    for (int i = 1; i <= t; i++)
    {
        cin >> cnt[i];
    }
    cnt[0] = 1;
    mn[t] = mx[t] = cnt[t];
    for (int i = t - 1; i >= 0; i--)
    {
        mn[i] = cnt[i] - min(cnt[i], cnt[i + 1]);
        mx[i] = cnt[i] - 1;
        mn[i] += mn[i + 1];
        mx[i] += mx[i + 1];
    }
    if (!(mn[0] <= k && k <= mx[0]))
    {
        cout << "-1\n";
        return 0;
    }
    int y = 0;
    for (int i = 0; i <= t; i++)
    {
        for (int j = 1; j <= cnt[i]; j++)
        {
            nodes[i].push_back(++y);
        }
    }
    cout << n << "\n";
    int cur = 0;
    for (int i = 0; i <= t; i++)
    {
        int l = mn[i] - mn[i + 1];
        int r = mx[i] - mx[i + 1];
        for (int leafs = l; leafs <= r; leafs++)
        {
            if (!(cur + leafs + mn[i + 1] <= k && k <= cur + leafs + mx[i + 1]))
            {
                continue;
            }
            int lol = cnt[i] - leafs;
            int it = 0;
            for (int j = 0; j < lol; j++)
            {
                cout << nodes[i][j] << " " << nodes[i + 1][it++] << "\n";
            }
            while (it < (int) nodes[i + 1].size())
            {
                cout << nodes[i][0] << " " << nodes[i + 1][it++] << "\n";
            }
            cur += leafs;
            break;
        }
    }
}