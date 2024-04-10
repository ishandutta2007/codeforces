#include <bits/stdc++.h>

using namespace std;

int mas[501][501];
int a[501], used[501];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i <= k; i++)
        for (int j = 0; j <= k; j++)
            mas[i][j] = 0;
    mas[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = k - a[i]; j >= 0; j--)
        {
            for (int q = j; q >= 0; q--)
            {
                if (mas[j][q])
                {
                    mas[j + a[i]][q] = 1;
                    mas[j + a[i]][q + a[i]] = 1;
                }
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i <= k; i++)
        if (mas[k][i])
            ans.push_back(i);
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}