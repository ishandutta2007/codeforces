#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 111111111;

long long ans, n, n1, m[max_n];

long long res(long long x, long long y)
{
    if (x >= y) return x - y;
    return (n - y + x);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> n1;
    for (int i = 1; i <= n1; i++)
        cin >> m[i];
    m[0] = 1;
    for (int i = 1; i <= n1; i++)
    {
        ans += res(m[i], m[i - 1]);
    }
    cout << ans;
    return 0;
}