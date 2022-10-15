#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 7;
int n;
int f[N];
int col[N];
bool take[N][N];
int last;
int cur;
vector<int> pos[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= last; j++)
        {
            f[j] = 0;
            pos[j].clear();
        }
        for (int j = 1; j <= n + 1; j++)
        {
            f[col[j]]++;
            pos[col[j]].push_back(j);
        }
        int x;
        cin >> x;
        while (cur < last && f[cur] <= 1)
        {
            cur++;
        }
        for (int j = 0; j <= last; j++)
        {
            if (j != cur)
            {
                for (auto &it : pos[j])
                {
                    if (x > 1)
                    {
                        x--;
                        take[i][it] = 1;
                    }
                }
            }
        }
        for (auto &it : pos[cur])
        {
            if (x > 0)
            {
                x--;
                take[i][it] = 1;
            }
        }
        int init_last = last;
        for (int c = 0; c <= init_last; c++)
        {
            bool is_0 = 0, is_1 = 0;
            for (auto &j : pos[c])
            {
                is_0 |= (take[i][j] == 0);
                is_1 |= (take[i][j] == 1);
            }
            if (is_0 && is_1)
            {
                last++;
                for (auto &j : pos[c])
                {
                    if (take[i][j] == 1)
                    {
                        col[j] = last;
                    }
                }
            }
        }
    }
    cout << n + 1 << "\n";
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << take[j][i];
        }
        cout << "\n";
    }
}