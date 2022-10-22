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
int n, m, k;
template <class Tp>
class priority_queue_plus
{
private:
    std::priority_queue<Tp> a, b;
    void work()
    {
        while (!a.empty() && !b.empty() && a.top() == b.top())
        {
            a.pop();
            b.pop();
        }
    }

public:
    void push(const Tp &val) { a.push(val); }
    void erase(const Tp &val) { b.push(val); }
    void pop(const Tp &val)
    {
        work();
        a.pop();
    }
    Tp top()
    {
        work();
        return a.top();
    }
    size_t size() const { return a.size() - b.size(); }
    bool empty() const { return size() == 0; }
};
priority_queue_plus<int> line, column;
std::set<int> l, c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> m >> n >> k;
    l.insert(0);
    l.insert(n);
    line.push(n);
    c.insert(0);
    c.insert(m);
    column.push(m);
    for (int i = 1; i <= k; ++i)
    {
        static char a;
        static int b;
        std::cin >> a >> b;
        switch (a)
        {
        case 'H':
            line.erase(*l.upper_bound(b) - *--l.upper_bound(b));
            l.insert(b);
            line.push(*++l.find(b) - b);
            line.push(b - *--l.find(b));
            break;
        case 'V':
            column.erase(*c.upper_bound(b) - *--c.upper_bound(b));
            c.insert(b);
            column.push(*++c.find(b) - b);
            column.push(b - *--c.find(b));
            break;
        }
        std::cout << line.top() * column.top() << std::endl;
    }
    return 0;
}