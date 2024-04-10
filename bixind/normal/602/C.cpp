#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m, i, j, a, b;
    cin >> n >> m;
    int t[n][n], tp;
    int y[n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        t[i][j] = 0;
        y[i] = -1;
    }
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        t[a][b] = 1;
        t[b][a] = 1;
    }
    y[0] = 0;
    tp = t[0][n - 1];
    tp = 1 - tp;
    queue<int> och;
    och.push(0);
    while (!och.empty())
    {
        a = och.front();
        och.pop();
        for (i = 0; i< n; i++)
        {
            if (t[a][i] == tp &&  y[i] < 0)
            {
                y[i] = y[a] + 1;
                och.push(i);
            }
        }
    }
    cout << y[n - 1];
    return 0;
}