//This Code was made by Chinese_zjc_.
#include <iostream>
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
#include <time.h>
// #include<windows.h>
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
using namespace std;
int n, k, T;
signed main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        int len = n / sqrt(2.0) / k + eps;
        int pos = len * k;
        if (pos * pos + (pos + k) * (pos + k) <= n * n)
        {
            cout << "Ashish" << endl;
        }
        else
        {
            cout << "Utkarsh" << endl;
        }
    }
    return 0;
}