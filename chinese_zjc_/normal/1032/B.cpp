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
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <list>
// #include<windows.h>
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
char ans[10][50];
string s;
bool check(int n, int m)
{
    if (n * m - s.length() >= n)
    {
        return false;
    }
    if (n * m < s.length())
    {
        return false;
    }
    int k = 0, no = n * m - s.length();
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            ans[i][j] = s[k++];
        }
        if (no)
        {
            --no;
            ans[i][m] = '*';
        }
        else
        {
            ans[i][m] = s[k++];
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 1; i <= 5; ++i)
    {
        for (int j = 1; j <= 20; ++j)
        {
            if (check(i, j))
            {
                cout << i << " " << j << endl;
                for (int k = 1; k <= i; ++k)
                {
                    for (int l = 1; l <= j; ++l)
                    {
                        cout << ans[k][l];
                    }
                    cout << endl;
                }
                return 0;
            }
        }
    }
    return 0;
}