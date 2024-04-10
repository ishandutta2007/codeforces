#include <bits/stdc++.h>

using namespace std;

string s[101][101];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> s[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int q = 0; q < k; q++)
            {
                if (s[i][j][q] == '1')
                {
                    if (i > 0 && i + 1 < n && s[i - 1][j][q] == '1' && s[i + 1][j][q] == '1')
                        ans++;
                    else if (j > 0 && j + 1 < m && s[i][j - 1][q] == '1' && s[i][j + 1][q] == '1')
                        ans++;
                    else if (q > 0 && q + 1 < k && s[i][j][q - 1] == '1' && s[i][j][q + 1] == '1')
                        ans++;
                    else if (i > 0 && j + 1 < m && s[i - 1][j][q] == '1' && s[i][j + 1][q] == '1' && s[i - 1][j + 1][q] == '0')
                        ans++;
                    else if (i > 0 && q + 1 < k && s[i - 1][j][q] == '1' && s[i][j][q + 1] == '1' && s[i - 1][j][q + 1] == '0')
                        ans++;
                    else if (j > 0 && i + 1 < n && s[i][j - 1][q] == '1' && s[i + 1][j][q] == '1' && s[i + 1][j - 1][q] == '0')
                        ans++;
                    else if (j > 0 && q + 1 < k && s[i][j - 1][q] == '1' && s[i][j][q + 1] == '1' && s[i][j - 1][q + 1] == '0')
                        ans++;
                    else if (q > 0 && i + 1 < n && s[i][j][q - 1] == '1' && s[i + 1][j][q] == '1' && s[i + 1][j][q - 1] == '0')
                        ans++;
                    else if (q > 0 && j + 1 < m && s[i][j][q - 1] == '1' && s[i][j + 1][q] == '1' && s[i][j + 1][q - 1] == '0')
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}