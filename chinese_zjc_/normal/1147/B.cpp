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
int n, k;
struct line
{
    int x, y;
    bool operator<(const line &__Val) const
    {
        return y == __Val.y ? x < __Val.x : y < __Val.y;
    }
    bool operator==(const line &__Val) const
    {
        return (x == __Val.x && y == __Val.y) || (x == __Val.y && y == __Val.x);
    }
};
vector<line> a, b;
void print(const vector<line> &__Val)
{
    for (auto i : __Val)
    {
        cout << '(' << i.x << " " << i.y << ')';
    }
    cout << endl;
}
int dist(int A, int B)
{
    return A < B ? B - A : B - A + n;
}
template <typename T>
void work(T __first, T __last)
{
    for (T i = __first; i != __last; ++i)
    {
        if (i->x > i->y)
        {
            swap(i->x, i->y);
        }
    }
}
bool check(int now)
{
    for (int i = 2; i * i <= now; ++i)
    {
        if (now % i == 0)
        {
            return false;
        }
    }
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.assign(k, {0, 0});
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i].x >> a[i].y;
        a[i].x %= n;
        a[i].y %= n;
    }
    work(a.begin(), a.end());
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i)
    {
        if (n % i)
        {
            continue;
        }
        if (!check(n / i))
        {
            continue;
        }
        b.assign(k, {0, 0});
        for (int j = 0; j < k; ++j)
        {
            b[j] = {(a[j].x + i) % n, (a[j].y + i) % n};
        }
        work(b.begin(), b.end());
        sort(b.begin(), b.end());
        if (a == b)
        {
            cout << "yes" << endl;
            return 0;
        }
    }
    cout << "no" << endl;
    return 0;
}