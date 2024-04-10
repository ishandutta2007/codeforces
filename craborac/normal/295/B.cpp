#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
//#include<set>
//#include<utility>
//#include<vector>

using namespace std;

int q[510], d[510][510], used[510];
long long ans[510];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        used[i] = 0;
        ans[i] = (int)1e5 * 500 + 10;
        for (int j = 0; j < n; j++)
        {
            cin >> d[i][j];
        }
    }
    for (int k = n - 1; k >= 0; k--)
    {
        cin >> q[k];
        q[k]--;
    }
    for (int k = 0; k < n; k++)
    {
        ans[n - 1 - k] = 0;
        used[q[k]] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = min(d[i][j], d[i][q[k]] + d[q[k]][j]);
                if ((used[j] == 1)  && (used[i] == 1) && (d[i][j] != (int)1e5 * 500 + 10))
                    ans[n - 1 - k] += d[i][j];
            }
        }
    }
    for (int k = 0; k < n; k++)
        cout << ans[k] << " ";

    return 0;
}