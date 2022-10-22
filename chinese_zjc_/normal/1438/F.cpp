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
#include <list>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <map>
#include <set>
#include <ctime>
#include <random>
#include <chrono>
// #include<windows.h>
// #define debug true
#define int long long
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
unsigned int seed = chrono::system_clock::now().time_since_epoch().count() / 1000000;
mt19937_64 Rand(seed);
int h, val[1 << 18 | 5], Max[2];
int mod(unsigned int v)
{
    return v % ((1 << h) - 1) + 1;
}
int query(int A, int B, int C)
{
    cout << '?' << ' ' << A << ' ' << B << ' ' << C << endl;
    int v;
    cin >> v;
    return v;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> h;
    for (int i = 1; i <= 422; ++i)
    {
        int A = mod(Rand()), B = mod(Rand()), C = mod(Rand());
        while (A == B || B == C || C == A)
        {
            A = mod(Rand()), B = mod(Rand()), C = mod(Rand());
        }
        ++val[query(A, B, C)];
    }
    for (int i = 1; i <= 1 << h; ++i)
    {
        if (val[Max[0]] < val[i])
        {
            swap(Max[0], Max[1]);
            Max[0] = i;
        }
        else if (val[Max[1]] < val[i])
        {
            Max[1] = i;
        }
    }
    for (int i = 1; i <= 1 << h; ++i)
    {
        if (Max[0] == i || Max[1] == i)
        {
            continue;
        }
        if (i == query(Max[0], Max[1], i))
        {
            cout << '!' << ' ' << i << endl;
            return 0;
        }
    }
    return 0;
}