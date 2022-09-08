#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 1111, inf = 111111111;

int n, a, m[11];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m[a]++;
    }
    if (m[0] != 0)
    {
        m[5] -= m[5] % 9;
        for (int i = 1; i <= m[5]; i++)
            cout << '5';
        if (m[5] == 0)
        {
            cout << '0';
            return 0;
        }
        for (int i = 1; i <= m[0]; i++)
            cout << '0';
    }
    else cout << "-1";
    return 0;
}