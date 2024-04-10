#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9;

int n, q;
vector <int> v;
vector <int> urm[26]; /// urm de caracter
int dp[255][255][255];
int len[3];

bool valid(int i, int j, int k)
{
    return (min(min(i, j), k) >= 0);
}

void upd(int i, int j, int k, int val)
{
    dp[i][j][k] = min(dp[i][j][k], val);
}

int get(int x, int i)
{
    i++;
    if (i >= n)
    {
        return INF;
    }
    else
    {
        return urm[x][i];
    }
}

vector <int> cur[3];

void upd_dp(int i, int j, int k)
{
        dp[i][j][k] = INF;
        ///   cout << i << " , " << j << " , " << k << " : " << dp[i][j][k] << "\n";
        if (valid(i - 1, j, k)) upd(i, j, k, get(cur[0][i - 1], dp[i - 1][j][k]));
        if (valid(i, j - 1, k)) upd(i, j, k, get(cur[1][j - 1], dp[i][j - 1][k]));
        if (valid(i, j, k - 1)) upd(i, j, k, get(cur[2][k - 1], dp[i][j][k - 1]));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    string s;
    cin >> s;

    for (auto &ch : s)
    {
        v.push_back(ch - 'a');
    }

    for (int j = 0; j < 26; j++)
    {
        urm[j].resize(n + 1);
        urm[j][n] = INF;
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] == j)
            {
                urm[j][i] = i;
            }
            else
            {
                urm[j][i] = urm[j][i + 1];
            }
        }
    }

    dp[0][0][0] = -1;

    for (int it = 0; it < q; it++)
    {
        string type;
        cin >> type;
        int i2;
        cin >> i2;
        i2--;
        if (type == "+")
        {
            string ccciq;
            cin >> ccciq;
            int x = ccciq[0] - 'a';
            len[i2]++;
            cur[i2].push_back(x);
            int i = len[i2];
            if (i2 == 0)
            {
                for (int j = 0; j <= len[1]; j++)
                {
                    for (int k = 0; k <= len[2]; k++)
                    {
                        upd_dp(i, j, k);
                    }
                }
            }
            if (i2 == 1)
            {
                for (int j = 0; j <= len[0]; j++)
                {
                    for (int k = 0; k <= len[2]; k++)
                    {
                        upd_dp(j, i, k);
                    }
                }
            }
            if (i2 == 2)
            {
                for (int j = 0; j <= len[0]; j++)
                {
                    for (int k = 0; k <= len[1]; k++)
                    {
                        upd_dp(j, k, i);
                    }
                }
            }
        }
        else
        {
            len[i2]--;
            cur[i2].pop_back();
        }
        int kol = dp[len[0]][len[1]][len[2]] + 1;
        if (kol <= n)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

}