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
// #include<windows.h>
// #define debug true
#define double long double
using namespace std;
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffff;
struct shit
{
    int x, y;
    bool good() const
    {
        return 1ll * x * x + 1ll * y * y <= 2250000000000;
    }
    const shit operator+(const shit &__Val) const
    {
        return {x + __Val.x, y + __Val.y};
    }
    const shit operator-(const shit &__Val) const
    {
        return {x - __Val.x, y - __Val.y};
    }
    bool operator==(const shit &__Val) const
    {
        return x == __Val.x && y == __Val.y;
    }
} a[100005];
int n, ans[100005], to[100005];
vector<shit> RAND[100005];
void solve(int now, shit nmsl)
{
    // cout << now << " " << nmsl.x << ' ' << nmsl.y << endl;
    if (now == 0)
    {
        return;
    }
    for (auto i : RAND[now - 1])
    {
        if (nmsl - a[now] == i)
        {
            solve(now - 1, i);
            ans[to[now]] = 1;
            return;
        }
        if (nmsl + a[now] == i)
        {
            solve(now - 1, i);
            ans[to[now]] = -1;
            return;
        }
    }
}
signed main()
{
    srand(114514);
    ios::sync_with_stdio(false);
    cin >> n;
    RAND[0].push_back({0, 0});
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i].x >> a[i].y;
        to[i] = i;
    }
    for (int i = 1; i <= 100000; ++i)
    {
        int A = (rand() << 16 | rand()) % n + 1, B = (rand() << 16 | rand()) % n + 1;
        swap(to[A], to[B]);
        swap(a[A], a[B]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (auto j : RAND[i - 1])
        {
            shit A = j + a[i];
            if (A.good())
            {
                RAND[i].push_back(A);
            }
            shit B = j - a[i];
            if (B.good())
            {
                RAND[i].push_back(B);
            }
        }
        random_shuffle(RAND[i].begin(), RAND[i].end());
        RAND[i].resize(min(100u, RAND[i].size()));
    }
    if (RAND[n].empty())
    {
        cout << "OK You win..." << endl;
        return 0;
    }
    solve(n, RAND[n].front());
    for (int i = 1; i <= n; ++i)
    {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}