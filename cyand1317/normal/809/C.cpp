#include <cstdio>
#include <cstring>
#include <utility>
typedef long long int64;
static const int LOGX = 31;
static const int MODULUS = 1e9 + 7;
#define _  %  MODULUS
#define __ %= MODULUS

inline std::pair<int, int> operator + (const std::pair<int, int> lhs, const std::pair<int, int> rhs) {
    return std::make_pair((lhs.first + rhs.first)_, (lhs.second + rhs.second)_);
}
inline void operator += (std::pair<int, int> &lhs, const std::pair<int, int> rhs) {
    (lhs.first += rhs.first)__;
    (lhs.second += rhs.second)__;
}

inline int query(int x, int y, int k)
{
    if (x == 0 || y == 0 || k == 0) return 0;
    --x, --y, --k;
    static std::pair<int, int> f[LOGX + 1][2][2][2];
    memset(f, 0, sizeof f);
    f[LOGX][1][1][1] = std::make_pair(0, 1);
    for (int i = LOGX - 1; i >= 0; --i) {
        for (int fx = 0; fx <= 1; ++fx)
            for (int fy = 0; fy <= 1; ++fy)
                for (int fk = 0; fk <= 1; ++fk) {
                    // (1) x + 0, y + 0
                    f[i][fx & !((x >> i) & 1)][fy & !((y >> i) & 1)][fk & !((k >> i) & 1)] += f[i + 1][fx][fy][fk];
                    // (2) x + 1, y + 0
                    if ((!fx || ((x >> i) & 1)) && (!fk || ((k >> i) & 1)))
                        f[i][fx][fy & !((y >> i) & 1)][fk] += f[i + 1][fx][fy][fk] + std::make_pair(((int64)f[i + 1][fx][fy][fk].second << i)_, 0);
                    // (3) x + 0, y + 1
                    if ((!fy || ((y >> i) & 1)) && (!fk || ((k >> i) & 1)))
                        f[i][fx & !((x >> i) & 1)][fy][fk] += f[i + 1][fx][fy][fk] + std::make_pair(((int64)f[i + 1][fx][fy][fk].second << i)_, 0);
                    // (4) x + 1, y + 1
                    if ((!fx || ((x >> i) & 1)) && (!fy || ((y >> i) & 1)))
                        f[i][fx][fy][fk & !((k >> i) & 1)] += f[i + 1][fx][fy][fk];
                }
    }
    std::pair<int, int> ans(0, 0);
    for (int fx = 0; fx <= 1; ++fx) {
        for (int fy = 0; fy <= 1; ++fy)
            for (int fk = 0; fk <= 1; ++fk)
                ans += f[0][fx][fy][fk];
    }
    return (ans.first + ans.second)_;
}

int main()
{
    int q, x1, y1, x2, y2, k;
    scanf("%d", &q);
    do {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
        int ans = 0;
        (ans += query(x2, y2, k))__;
        (ans -= query(x1 - 1, y2, k))__;
        (ans -= query(x2, y1 - 1, k))__;
        (ans += query(x1 - 1, y1 - 1, k))__;
        printf("%d\n", (ans + MODULUS)_);
    } while (--q);

    return 0;
}