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
struct node
{
    int x, y, z, val, p;
    node() {}
    node(const int x_, const int y_, const int z_, const int val_, const int p_ = 0)
        : x(x_), y(y_), z(z_), val(val_), p(p_) {}
};
std::vector<node> a;
int n, m, v[100005], sum[100005], ans[100005];
std::set<int> s[100005];
void add(int pos, int val)
{
    ++pos;
    while (pos <= n + 1)
    {
        sum[pos] += val;
        pos += pos & -pos;
    }
}
int query(int pos)
{
    ++pos;
    int res = 0;
    while (pos)
    {
        res += sum[pos];
        pos -= pos & -pos;
    }
    return res;
}
bool cmpx(const node &A, const node &B) { return A.x == B.x ? A.y == B.y ? A.z < B.z : A.y < B.y : A.x > B.x; }
bool cmpy(const node &A, const node &B) { return A.y == B.y ? A.z < B.z : A.y < B.y; }
void solve(std::vector<node>::iterator L, std::vector<node>::iterator R)
{
    if (R - L == 1)
        return;
    std::vector<node>::iterator mid = L + (R - L) / 2;
    solve(L, mid);
    solve(mid, R);
    std::vector<node>::iterator i = L, j = mid;
    while (j != R)
    {
        if (j->p)
        {
            while (i != mid && i->y <= j->y)
                add(i->z, i->val), ++i;
            ans[j->p] += query(j->z);
        }
        ++j;
    }
    j = L;
    while (j != i)
        add(j->z, -j->val), ++j;
    node tmp[R - L];
    std::merge(L, mid, mid, R, tmp, cmpy);
    std::copy(tmp, tmp + (R - L), L);
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        s[i].insert(0);
    for (int i = 1; i <= n; ++i)
    {
        std::cin >> v[i];
        a.push_back(node(*s[v[i]].rbegin(), i, 0, i - *s[v[i]].rbegin()));
        s[v[i]].insert(i);
    }
    for (int i = 1; i <= m; ++i)
    {
        static int tmp, A, B;
        std::cin >> tmp >> A >> B;
        if (tmp == 2)
        {
            a.push_back(node(A, B, i, 0, i));
            continue;
        }
        ans[i] = -1;
        if (v[A] == B)
            continue;
        std::set<int>::iterator iter = s[v[A]].find(A);
        s[v[A]].erase(iter--);
        a.push_back(node(tmp = *iter, A, i, *iter - A));
        if (++iter != s[v[A]].end())
        {
            a.push_back(node(A, *iter, i, A - *iter));
            a.push_back(node(tmp, *iter, i, *iter - tmp));
        }
        --(iter = s[v[A] = B].insert(A).first);
        a.push_back(node(tmp = *iter, A, i, A - *iter));
        ++iter;
        if (++iter != s[v[A]].end())
        {
            a.push_back(node(tmp, *iter, i, tmp - *iter));
            a.push_back(node(A, *iter, i, *iter - A));
        }
    }
    std::sort(a.begin(), a.end(), cmpx);
    // for (auto i : a)
    //     std::cout << i.x << ' ' << i.y << ' ' << i.z << ' ' << i.p << ' ' << i.val << std::endl;
    solve(a.begin(), a.end());
    for (int i = 1; i <= m; ++i)
        if (~ans[i])
            std::cout << ans[i] << std::endl;
    return 0;
}