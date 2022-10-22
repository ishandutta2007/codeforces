//This Code was made by Chinese_zjc_.
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <ctime>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int T, n, m, block[105][2][2];
bool flag;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < 2; ++j)
            {
                for (int k = 0; k < 2; ++k)
                {
                    cin >> block[i][j][k];
                }
            }
        }
        if (m & 1)
        {
            cout << "NO" << endl;
            continue;
        }
        flag = true;
        for (int i = 1; i <= n; ++i)
        {
            if (block[i][0][1] == block[i][1][0])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
            continue;
        }
        flag = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i; j <= n; ++j)
            {
                bool Flag = true;
                for (int k = 0; k < 2; ++k)
                {
                    for (int l = 0; l < 2; ++l)
                    {
                        if (block[i][k][l] != block[j][l][k])
                        {
                            Flag = false;
                        }
                    }
                }
                if (Flag)
                {
                    flag = false;
                }
            }
        }
        if (flag)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}