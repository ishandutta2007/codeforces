#include <cstdio>
#include <algorithm>
#include <utility>
typedef long long int64;
static const int MAXM = 3e5 + 4;

// USB, PS/2, both
int a, b, c, m;
std::pair<int, bool> mouse[MAXM];
static const bool USB = false;
static const bool PS_2 = true;

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &mouse[i].first); getchar();
        static char type_str[32];
        gets(type_str);
        mouse[i].second = (type_str[0] == 'U' ? USB : PS_2);
    }
    std::sort(mouse, mouse + m);

    int equipped = 0;
    int64 cost = 0;
    for (int i = 0; i < m; ++i) {
        if (mouse[i].second == USB) {
            if (a > 0) --a, ++equipped, cost += mouse[i].first;
            else if (c > 0) --c, ++equipped, cost += mouse[i].first;
        } else {
            if (b > 0) --b, ++equipped, cost += mouse[i].first;
            else if (c > 0) --c, ++equipped, cost += mouse[i].first;
        }
    }

    printf("%d %I64d\n", equipped, cost);
    return 0;
}