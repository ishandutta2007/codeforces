// This Code was made by Chinese_zjc_.
#include <bits/stdc++.h>
struct node
{
    int x, y;
    friend bool operator==(const node &A, const node &B) { return A.x == B.x && A.y == B.y; }
} a[4];
int T, n;
bool sp()
{
    for (int i = 0; i != 3; ++i)
        if (a[i].x != 0 && a[i].x != n - 1 && a[i].y != 0 && a[i].y != n - 1)
            return false;
    return true;
}
bool check()
{
    if (a[0].x + 1 == a[1].x && a[0].y == a[1].y)
    {
        switch (std::abs(a[2].y - a[0].y))
        {
        case 0:
            return a[3].y == a[0].y;
        case 1:
            if (sp())
                return a[3].x == a[2].x || a[3].y == a[0].y;
            for (int i = 0; i != 3; ++i)
                if (a[i].x % 2 == a[3].x % 2 && a[i].y % 2 == a[3].y % 2)
                    return true;
            return false;
        default:
            return a[3].y == a[0].y || a[2] == a[3];
        }
    }
    if (a[0].x + 1 == a[1].x && a[0].y + 1 == a[1].y)
    {
        switch (std::abs((a[0].x - a[0].y) - (a[2].x - a[2].y)))
        {
        case 0:
            return a[0].x - a[0].y == a[3].x - a[3].y;
        case 1:
            if (sp())
                return a[3].x == (a[0].x == 0 ? 0 : n - 1) || a[3].y == (a[0].y == 0 ? 0 : n - 1);
            for (int i = 0; i != 3; ++i)
                if (a[i].x % 2 == a[3].x % 2 && a[i].y % 2 == a[3].y % 2)
                    return true;
            return false;
        case 2:
            return a[0].x - a[0].y == a[3].x - a[3].y || a[2].x + a[2].y == a[3].x + a[3].y;
        default:
            return a[0].x - a[0].y == a[3].x - a[3].y || a[2] == a[3];
        }
    }
    return a[0] == a[3] || a[1] == a[3] || a[2] == a[3];
}
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin >> T;
    while (T--)
    {
        std::cin >> n;
        for (int i = 0; i != 4; ++i)
            std::cin >> a[i].x >> a[i].y, --a[i].x, --a[i].y;
        bool ans = false;
        for (int i = 0; i != 2; ++i)
        {
            for (int i = 0; i != 2; ++i)
            {
                for (int i = 0; i != 3; ++i)
                {
                    for (int i = 0; i != 2; ++i)
                    {
                        ans |= check();
                        std::swap(a[0], a[1]);
                    }
                    std::rotate(a, a + 1, a + 3);
                }
                for (int j = 0; j != 4; ++j)
                    std::swap(a[j].x, a[j].y);
            }
            for (int j = 0; j != 4; ++j)
                a[j].x = n - a[j].x - 1;
        }
        std::cout << (ans ? "YES" : "NO") << std::endl;
    }
    return 0;
}