#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

vector<int> mas[(int)2e5 + 10];
long long c[(int)2e5 + 10], dp[(int)2e5 + 10][2];

void dfs(int v)
{
    dp[v][0] = 0;
    dp[v][1] = (long long)-1e12;
    for (int i = 0; i < mas[v].size(); i++)
    {
        dfs(mas[v][i]);
        long long a = dp[v][0];
        long long b = dp[v][1];
        dp[v][0] = max(dp[v][0], a + dp[mas[v][i]][0]);
        dp[v][0] = max(dp[v][0], b + dp[mas[v][i]][1]);
        dp[v][1] = max(dp[v][1], a + dp[mas[v][i]][1]);
        dp[v][1] = max(dp[v][1], b + dp[mas[v][i]][0]);
    }
    dp[v][1] = max(dp[v][1], dp[v][0] + c[v]);
}

int main()
{
    int p = -1;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a >> c[i];
        if (a == -1)
        {
            p = i;
        }
        else
        {
            mas[a - 1].push_back(i);
        }
    }
    dfs(p);
    cout << max(dp[p][0], dp[p][1]) << endl;
    return 0;
}