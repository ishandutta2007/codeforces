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
// #define debug
#define int long long
#define double long double
const double PI = acos(-1);
const double eps = 0.0000000001;
const int INF = 0x3fffffffffffffff;
int n, a[200005], b[200005], ans;
std::priority_queue<int, std::vector<int>, std::less<int>> queL;
std::priority_queue<int, std::vector<int>, std::greater<int>> queR;
struct BIT
{
    int sum[200005];
    void add(int pos, int val)
    {
        while (pos <= n)
        {
            sum[pos] += val;
            pos += pos & -pos;
        }
    }
    int query(int pos)
    {
        int res = 0;
        while (pos)
        {
            res += sum[pos];
            pos -= pos & -pos;
        }
        return res;
    }
} zero, one;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i], b[a[i]] = i, zero.add(i, 1);
    std::cout << ans;
    zero.add(b[1], -1);
    one.add(b[1], 1);
    queL.push(b[1]);
    for (int i = 2; i <= n; ++i)
    {
        int old = queL.top();
        if (b[i] < old)
            ans -= one.query(b[i]);
        else
            ans -= one.query(n) - one.query(b[i]);
        ans += one.query(n) - one.query(b[i]);
        zero.add(b[i], -1);
        one.add(b[i], 1);
        ans += llabs(zero.query(old) - zero.query(b[i]));
        queR.push(b[i]);
        while (!queL.empty() && !queR.empty() && queL.top() > queR.top())
            if (queR.size() > queL.size())
                queL.push(queR.top()), queR.pop();
            else
                queR.push(queL.top()), queL.pop();
        while (queR.size() > queL.size())
            queL.push(queR.top()), queR.pop();
        ans -= llabs((zero.query(queL.top()) - zero.query(old)) *
                     ((one.query(n) - one.query(std::min(queL.top(), old))) - (one.query(std::min(queL.top(), old)))));
        // std::cout << queL.top() << std::endl;
        std::cout << ' ' << ans;
    }
    std::cout << std::endl;
    return 0;
}