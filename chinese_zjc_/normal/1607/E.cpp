// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int xx[] = {0, 1, 0, -1};
const int yy[] = {1, 0, -1, 0};
const char cc[] = {'R', 'D', 'L', 'U'};
void cmin(int &A, int B) { A = std::min(A, B); }
void cmax(int &A, int B) { A = std::max(A, B); }
struct node
{
    int x, y, xmin, xmax, ymin, ymax;
    friend node operator+(const node &A, const int &B)
    {
        node res = A;
        res.x += xx[B];
        res.y += yy[B];
        cmin(res.xmin, res.x);
        cmax(res.xmax, res.x);
        cmin(res.ymin, res.y);
        cmax(res.ymax, res.y);
        return res;
    }
} pre[1000005];
int T, n, m;
std::string c;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n >> m >> c;
        for (int i = 1; i <= int(c.size()); ++i)
            pre[i] = pre[i - 1] + (std::find(cc, cc + 4, c[i - 1]) - cc);
        for (int i = c.size(); i >= 0; --i)
            if (pre[i].xmax - pre[i].xmin + 1 <= n && pre[i].ymax - pre[i].ymin + 1 <= m)
            {
                std::cout << n - pre[i].xmax << ' ' << m - pre[i].ymax << std::endl;
                break;
            }
    }
    return 0;
}