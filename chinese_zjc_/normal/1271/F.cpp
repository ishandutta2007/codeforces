// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
const int X[7] = {7, 3, 5, 1, 6, 2, 4};
const int Y[3][4] = {{1, 3, 5, 7}, {2, 3, 6, 7}, {4, 5, 6, 7}};
unsigned long long seed = std::chrono::system_clock::now().time_since_epoch().count() / 1000000;
std::mt19937_64 Rand(seed);
int T, a[2][3], d[8], s[3], sum, BST;
std::array<int, 8> e, bst;
int sqr(int x) { return x * x; }
int check(const std::array<int, 8> &x)
{
    int res = 0;
    for (int i = 0; i != 3; ++i)
    {
        res += sqr(std::max(0, -a[0][i] + (x[Y[i][0]] + x[Y[i][1]] + x[Y[i][2]] + x[Y[i][3]])));
        res += sqr(std::max(0, -a[1][i] + (s[i] - x[Y[i][0]] - x[Y[i][1]] - x[Y[i][2]] - x[Y[i][3]])));
    }
    return res;
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        sum = 0;
        for (int i = 0; i != 2; ++i)
            for (int j = 0; j != 3; ++j)
                std::cin >> a[i][j];
        for (int i = 0; i != 7; ++i)
            std::cin >> d[X[i]], sum += d[X[i]];
        for (int i = 0; i != 3; ++i)
            s[i] = d[Y[i][0]] + d[Y[i][1]] + d[Y[i][2]] + d[Y[i][3]];
        int STA = clock();
        bst.fill(0);
        BST = check(bst);
        while (double(clock() - STA) / CLOCKS_PER_SEC <= (8 - double(STA) / CLOCKS_PER_SEC) / (T + 1) && BST)
        {
            e = bst;
            double del = 1e5;
            while (del > 1e-2)
            {
                int pos = Rand() % 7 + 1, val = int(Rand()) % (d[pos] / int(10000 / std::sqrt(BST)) + 5);
                e[pos] += val;
                if (e[pos] < 0 || e[pos] > d[pos])
                    e[pos] -= val;
                else
                {
                    int tmp = check(e);
                    if (exp((BST - tmp) / 10.0) * static_cast<unsigned short>(Rand()) > del)
                    {
                        if (BST > tmp)
                        {
                            BST = tmp;
                            bst = e;
                        }
                    }
                    else
                        e[pos] -= val;
                }
                del *= 0.95;
            }
        }
        if (BST)
            std::cout << -1 << std::endl;
        else
            for (int i = 0; i != 7; ++i)
                std::cout << bst[X[i]] << " \n"[i == 6];
    }
    return 0;
}