#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

char mas[5][300];
int used[5][300];
int n;

bool check(int x, int y)
{
    return x >= 0 && x < 3 && y >= 0 && y < n && (y + 2 * y - 2 >= n || mas[x][y + 2 * y - 2] == '.' || mas[x][y + 2 * y - 2] == 's') && (y + 2 * y >= n || mas[x][y + 2 * y] == '.');
}

bool check2(int x, int y)
{
    return x >= 0 && x < 3 && y >= 0 && y < n && (y + 2 * y - 2 >= n || mas[x][y + 2 * y - 2] == '.' || mas[x][y + 2 * y - 2] == 's');
}

int main()
{
    int t;
    cin >> t;
    for (int qwe = 0; qwe < t; qwe++)
    {
        int k;
        cin >> n >> k;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                used[i][j] = 0;
                cin >> mas[i][j];
                if (mas[i][j] == 's')
                {
                    used[i][j] = 1;
                }
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < 3; i++)
            {
                if (used[i][j] && check2(i, j + 1))
                {
                    for (int dx = -1; dx < 2; dx++)
                    {
                        if (check(i + dx, j + 1))
                        {
                            used[i + dx][j + 1] = 1;
                        }
                    }
                }
            }
        }
        if (used[0][n - 1] == 1 || used[1][n - 1] == 1 || used[2][n - 1] == 1)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
    return 0;
}