#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<int> mas;
int dp[(int)1e6 + 10], last[(int)1e6 + 10];

int main()
{
    int q = 10;
    int n;
    cin >> n;
    mas.push_back(1);
    for (int i = 1; i <= 10 * n; i++)
    {
        int j = i;
        int w = 0;
        int e = 1;
        while (j > 0)
        {
            w += (j % 2) * e;
            j /= 2;
            e *= 10;
        }
        if (w <= n)
        {
            mas.push_back(w);
        }
        else
        {
            break;
        }
    }
    dp[0] = 0;
    last[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = n + 300;
        last[i] = n + 300;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < mas.size(); j++)
        {
            if (i + mas[j] <= n && dp[i + mas[j]] > dp[i] + 1)
            {
                dp[i + mas[j]] = dp[i] + 1;
                last[i + mas[j]] = i;
            }
        }
    }
    cout << dp[n] << endl;
    q = n;
    while (q > 0)
    {
        cout << q - last[q] << " ";
        q = last[q];
    }
    return 0;
}