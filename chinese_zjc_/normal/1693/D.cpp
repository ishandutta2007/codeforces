// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
// #define debug
int n, a[200005], B[200005], S[200005], mid[2][2], uptot, downtot;
long long ans;
std::map<int, int, std::greater<int>> up;
std::map<int, int, std::less<int>> down;
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];
    for (int i = 1; i <= n; ++i)
    {
        for (int &j = B[i] = i - 1; j && a[j] < a[i]; j = B[j])
            ;
        for (int &j = S[i] = i - 1; j && a[j] > a[i]; j = S[j])
            ;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (a[i - 1] > a[i])
        {
            int &tot = down[a[i - 1]];
            while (!up.empty() && up.begin()->first > a[i])
                tot += up.begin()->second, up.erase(up.begin());
            up.clear();
            uptot = 0;
            downtot += tot;
        }
        if (a[i - 1] < a[i])
        {
            int &tot = up[a[i - 1]];
            while (!down.empty() && down.begin()->first < a[i])
                tot += down.begin()->second, down.erase(down.begin());
            down.clear();
            downtot = 0;
            uptot += tot;
        }
        for (int x = 2; x--;)
            for (int y = 2; y--;)
            {
                int L = std::max(x ?: B[i - 1] + 1, y ?: S[i - 1] + 1), cur = mid[x][y];
                mid[x][y] = 0;
                if (a[i - 1] > a[i] && L <= S[i - 1] && a[S[i - 1]] > a[i])
                    down[a[S[i - 1]]] += cur, downtot += cur;
                else if (a[i - 1] < a[i] && L <= B[i - 1] && a[B[i - 1]] < a[i])
                    up[a[B[i - 1]]] += cur, uptot += cur;
                else
                    mid[L <= B[i]][L <= S[i]] += cur;
            }
        ++mid[0][0];
        ans += mid[0][0] + mid[0][1] + mid[1][0] + mid[1][1] + uptot + downtot;
        // std::cout << mid[0][0] << ' ' << mid[0][1] << ' ' << mid[1][0] << ' ' << mid[1][1] << ' ' << uptot << ' ' << downtot << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}