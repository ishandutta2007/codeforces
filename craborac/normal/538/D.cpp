#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

vector<pair<int, int> > mas1, mas2;

int mas[300][300];
char arr[300][300];
int n;

bool check(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c;
            if (c == 'o')
            {
                mas1.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mas[i][j] = 0;
        }
    }
    for (int dx = -n + 1; dx < n; dx++)
    {
        for (int dy = -n + 1; dy < n; dy++)
        {
            int col = 0;
            for (int i = 0; i < mas1.size(); i++)
            {
                int x = mas1[i].first;
                int y = mas1[i].second;
                if (!check(x + dx, y + dy) || arr[x + dx][y + dy] == 'x' || arr[x + dx][y + dy] == 'o')
                {
                    col++;
                }
            }
            if (col == mas1.size())
            {
                for (int i = 0; i < mas1.size(); i++)
                {
                    int x = mas1[i].first;
                    int y = mas1[i].second;
                    if (check(x + dx, y + dy))
                    {
                        mas[x + dx][y + dy] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 'x' && mas[i][j] == 0)
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    for (int dx = -n + 1; dx < n; dx++)
    {
        for (int dy = -n + 1; dy < n; dy++)
        {
            if (dx != 0 || dy != 0)
            {
                int col = 0;
                for (int i = 0; i < mas1.size(); i++)
                {
                    int x = mas1[i].first;
                    int y = mas1[i].second;
                    if (!check(x + dx, y + dy) || arr[x + dx][y + dy] == 'x' || arr[x + dx][y + dy] == 'o')
                    {
                        col++;
                    }
                }
                if (col == mas1.size())
                {
                    cout << "x";
                }
                else
                {
                    cout << ".";
                }
            }
            else
            {
                cout << "o";
            }
        }
        cout << endl;
    }
    return 0;
}