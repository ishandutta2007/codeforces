#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = (int) 3e5 + 7;
int t;
int n;
int a[N];
int mn[N];
vector<int> p[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            p[i].clear();
            p[i].push_back(0);
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            p[a[i]].push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            p[i].push_back(n + 1);
            mn[i] = (int) 1e9;
        }
        for (int i = 1; i <= n; i++)
        {
            int mx = 0;
            for (int j = 0; j + 1 < (int) p[i].size(); j++)
            {
                mx = max(mx, p[i][j + 1] - p[i][j]);
            }
            mn[mx] = min(mn[mx], i);
        }
        for (int i = 2; i <= n; i++)
        {
            mn[i] = min(mn[i], mn[i - 1]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (mn[i] == (int) 1e9)
            {
                cout << "-1 ";
            }
            else
            {
                cout << mn[i] << " ";
            }
        }
        cout << "\n";
    }
}