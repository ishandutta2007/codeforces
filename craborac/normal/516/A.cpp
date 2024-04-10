#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>

using namespace std;

long long col[4][10];

int main()
{
    for (int j = 0; j < 4; j++)
        col[0][j] = 0;
    long long mul = 1;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            col[i][j] = col[i - 1][j];
        }
        mul *= i;
        long long a = mul;
        while (a % 2 == 0)
        {
            a /= 2;
            col[0][i]++;
        }
        while (a % 3 == 0)
        {
            a /= 3;
            col[1][i]++;
        }
        while (a % 5 == 0)
        {
            a /= 5;
            col[2][i]++;
        }
        while (a % 7 == 0)
        {
            a /= 7;
            col[3][i]++;
        }
    }
    int n;
    cin >> n;
    int col2 = 0;
    int col3 = 0;
    int col5 = 0;
    int col7 = 0;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        col2 += col[0][c - '0'];
        col3 += col[1][c - '0'];
        col5 += col[2][c - '0'];
        col7 += col[3][c - '0'];
    }
    while (col7 > 0)
    {
        cout << "7";
        col7--;
        col5--;
        col3 -= 2;
        col2 -= 4;
    }
    while (col5 > 0)
    {
        cout << "5";
        col5--;
        col3--;
        col2 -= 3;
    }
    while (col3 > 0)
    {
        cout << "3";
        col3--;
        col2--;
    }
    while (col2 > 0)
    {
        col2--;
        cout << "2";
    }
    return 0;
}