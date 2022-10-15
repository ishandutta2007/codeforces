#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a[10][10];
int b[10][10];

string s = {"154873296386592714729641835863725149975314628412968357631457982598236471247189563"};
string t = {"154873396336592714729645835863725145979314628412958357631457992998236471247789563"};

struct T
{
    int r1;
    int c1;
    int r2;
    int c2;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int p = 0;

    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            a[i][j] = s[p++] - '0';
        }
    }
    p = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            b[i][j] = t[p++] - '0';
        }
    }
    vector<T> ch;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (a[i][j] != b[i][j])
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (b[i][j] == a[i][k])
                    {
                        ch.push_back({i, j, i, k});
                    }
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 1; i <= 9; i++)
        {
            string uga;
            cin >> uga;
            for (int j = 1; j <= 9; j++)
            {
                a[i][j] = uga[j - 1] - '0';
            }
        }
        for (auto &it : ch)
        {
            a[it.r1][it.c1] = a[it.r2][it.c2];
        }
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                cout << a[i][j];
            }
            cout << "\n";
        }
    }
}