#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>

using namespace std;

vector<int> mas;
vector<int> ans[300];
int d[300][300];
int a[300], b[300];

int main()
{
    int m, k;
    cin >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i];
        bool d = 1, e = 1;
        for (int j = 0; j < mas.size(); j++)
        {
            if (mas[j] == a[i])
            {
                d = 0;
            }
            if (mas[j] == b[i])
            {
                e = 0;
            }
        }
        if (d)
        {
            mas.push_back(a[i]);
        }
        if (e)
        {
            mas.push_back(b[i]);
        }
    }
    int n = mas.size();
    sort(mas.begin(), mas.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            d[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i] == mas[j])
            {
                a[i] = j;
            }
            if (b[i] == mas[j])
            {
                b[i] = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[j] == i)
            {
                d[i][b[j]] = 1;
                d[b[j]][i] = 1;
            }
            if (b[j] == i)
            {
                d[i][a[j]] = 1;
                d[a[j]][i] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (d[i][j] == 0 && i != j)
            {
                int col1 = 0;
                int col2 = 0;
                for (int q = 0; q < n; q++)
                {
                    if (d[i][q] == 1)
                    {
                        col1++;
                        if (d[j][q] == 1)
                        {
                            col2++;
                        }
                    }
                }
                if (col2 * 100 >= col1 * k)
                {
                    ans[i].push_back(j);
                }
            }
        }
        cout << mas[i] << ": " << ans[i].size() << " ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << mas[ans[i][j]] << " ";
        }
        cout << endl;
    }
    return 0;
}