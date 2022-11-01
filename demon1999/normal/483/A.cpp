#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;
long long i, j, n, m, k, k1, k2;
int main()
{
    cin >> i >> j;
    if(j - i < 2)
    {
        cout << -1;
        return 0;
    }
    if(j - i == 2 && i % 2 == 1)
    {
        cout << -1;
        return 0;
    }
    n = i + i % 2;
    cout << n << " " << n + 1 << " " << n + 2;
    return 0;
}