#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

bitset<2001> arr[2000];
int ans[2000], used[2000];
vector<int> mas[2000];

void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        mas[i].clear();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mas[a].push_back(b);
        mas[b].push_back(a);
    }
    bool d = 1;
    for (int i = 0; i < n; i++)
        if ((int)mas[i].size() & 1)
        {
            d = 0;
            break;
        }
    if (d)
    {
        cout << 1 << "\n";
        for (int i = 0; i < n; i++)
            cout << 1 << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if ((int)mas[i].size() & 1)
        {
            arr[i][i] = 1;
            arr[i][n] = 1;
        }
        for (int j: mas[i])
            arr[i][j] = 1;
    }
    fill(used, used + n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (used[j] && arr[j][i])
            {
                used[j] = 0;
                for (int q = 0; q < n; q++)
                    if (q != j && arr[q][i])
                        arr[q] = (arr[q] ^ arr[j]);
                break;
            }
        }
    }
    cout << 2 << "\n";
    fill(ans, ans + n, 0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i][n])
        {
            bool d = 1;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j])
                {
                    ans[j] = 1;
                    d = 0;
                    break;
                }
            }
            if (d)
                exit(1);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << "\n";
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}