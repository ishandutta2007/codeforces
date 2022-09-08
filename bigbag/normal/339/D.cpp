#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 222222, inf = 111111111;

int k, x, x1, n, n1, ind, aa, bb, ans, a[max_n], p[31], step[33];
char m[18][max_n][30];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> n1;
    x = 1;
    step[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        x *= 2;
        step[i] = x;
    }
    x = 1;
    for (int i = 1; i <= n; i++)
        x *= 2;
    //printf("0\n");
    for (int i = 1; i <= x; i++)
    {
        cin >> a[i];
        k = a[i];
        ind = 0;
        while (k != 0)
        {
            ind++;
            p[ind] = k % 2;
            k /= 2;
        }
        for (int j = 0; j < 30 - ind; j++)
            m[0][i - 1][j] = 0;
        for (int j = 30 - ind; j < 30; j++)
            m[0][i - 1][j] = p[30 - j];
        /*for (int j = 0; j < 30; j++)
            printf("%d", m[0][i - 1][j]);
        printf("\n");*/
    }
    x1 = x;
    for (int i = 1; i <= n; i++)
    {
        //printf("%d\n", i);
        if (i % 2 == 1)
        {
            for (int j = 0; j < x1 - 1; j += 2)
            {
                for (int j1 = 0; j1 < 30; j1++)
                {
                    m[i][j / 2][j1] = 1;
                    if (m[i - 1][j][j1] == 0 && m[i - 1][j + 1][j1] == 0) m[i][j / 2][j1] = 0;
                }
            }
        }
        else
        {
            for (int j = 0; j < x1 - 1; j += 2)
            {
                for (int j1 = 0; j1 < 30; j1++)
                    m[i][j / 2][j1] = (m[i - 1][j][j1] + m[i - 1][j + 1][j1]) % 2;
            }
        }
        x1 /= 2;
        /*for (int j = 0; j <= x1 - 1; j++)
        {
            for (int j1 = 0; j1 < 30; j1++)
                printf("%d", m[i][j][j1]);
            printf("\n");
        }
        printf("\n");*/
    }
    for (int i = 1; i <= n1; i++)
    {
        cin >> aa >> bb;
        k = bb;
        ind = 0;
        while (k != 0)
        {
            ind++;
            p[ind] = k % 2;
            k /= 2;
        }
        for (int j = 0; j < 30 - ind; j++)
            m[0][aa - 1][j] = 0;
        for (int j = 30 - ind; j < 30; j++)
            m[0][aa - 1][j] = p[30 - j];
        int num = aa - 1;
        x1 = x;
        /*for (int j1 = 0; j1 <= x1 - 1; j1++)
            {
                for (int j2 = 0; j2 < 30; j2++)
                    printf("%d", m[0][j1][j2]);
                printf("\n");
            }
            printf("\n");*/
        for (int j = 1; j <= n; j++)
        {
            if (j % 2 == 1)
            {
                for (int j1 = 0; j1 < 30; j1++)
                {
                    m[j][num / 2][j1] = 1;
                    if (m[j - 1][num - num % 2][j1] == 0 && m[j - 1][num - num % 2 + 1][j1] == 0) m[j][num / 2][j1] = 0;
                }
            }
            else
            {
                for (int j1 = 0; j1 < 30; j1++)
                    m[j][num / 2][j1] = (m[j - 1][num - num % 2][j1] + m[j - 1][num - num % 2 + 1][j1]) % 2;
            }
            num /= 2;
            x1 /= 2;
            /*for (int j1 = 0; j1 <= x1 - 1; j1++)
            {
                for (int j2 = 0; j2 < 30; j2++)
                    printf("%d", m[j][j1][j2]);
                printf("\n");
            }
            printf("\n");*/
        }
        ans = 0;
        for (int j = 0; j < 30; j++)
            ans += step[30 - j - 1] * (m[n][0][j]);
        printf("%d\n", ans);
    }
    return 0;
}