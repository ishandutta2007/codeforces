#include <iostream>

using namespace std;

const int MN = 5015;

const long long mod = 1e9 + 7;

pair<int, int> gr[MN][MN];
int ps[MN][MN];
int d[MN][MN];

int main()
{
    int n, i, j;
    string s;
    cin >> n >> s;
    for (i = 0; i < n + 10; i++)
        for (j = 0; j < n + 10; j++)
        {
            ps[i][j] = 0;
            d[i][j] = 0;
            gr[i][j] = {0, 0};
        }
    for (i = n - 1; i >= 0; i--)
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 || j == n - 1)
            {
                if (s[i] > s[j])
                    gr[i][j] = {1, 1};
                if (s[i] < s[j])
                    gr[i][j] = {-1, 1};
                if (s[i] == s[j])
                    gr[i][j] = {0, 1};
            }
            else
            {
                if (s[i] > s[j])
                    gr[i][j] = {1, 1};
                if (s[i] < s[j])
                    gr[i][j] = {-1, 1};
                if (s[i] == s[j])
                    gr[i][j] = {gr[i + 1][j + 1].first, gr[i + 1][j + 1].second + 1};
            }
        }
    }
    for (i = 0; i <= n; i++)
    {
//        d[i][i] = 1;
        d[i][0] = 0;
    }
//    d[n][0] = 1;
    for (i = n - 1; i >= 0; i--)
    {
        for (j = 1; j <= n - i; j++)
        {
            int sum = 0;
            if (i + j > n)
                continue;
            if (s[i] == '0')
                continue;
            if (i + j == n)
            {
                d[i][j] = 1;
                continue;
            }
            if (j + 1 <= n)
                sum += ps[i + j][j + 1];
            if (gr[i][i + j].first < 0 && gr[i][i + j].second <= j)
                sum += d[i + j][j];
            d[i][j] = sum % mod;
        }
        ps[i][n] = d[i][n];
        for (j = n - 1; j >= 1; j--)
            ps[i][j] = (ps[i][j + 1] + d[i][j]) % mod;
//        for (int i = 0; i < n; i++)
//        {
//            for (int j = 1; j <= n; j++)
//                cout << d[i][j] << ' ';
//            cout << endl;
//        }
//        cout << endl;
    }
    int sum = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 1; j <= n; j++)
//            cout << d[i][j] << ' ';
//        cout << endl;
//    }
    for (i = 1; i <= n; i++)
        sum = (sum + d[0][i]) % mod;
    cout << sum << endl;
    return 0;
}