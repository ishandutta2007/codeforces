// Everybody come hold my hand
#include <cstdio>
#include <set>
static const int MAXN = 1e4 + 3;

int n, m;

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        std::set<int> s;
        bool doom = true;
        int sz, val;
        scanf("%d", &sz);
        while (sz--) {
            scanf("%d", &val);
            if (s.count(-val)) doom = false;
            s.insert(val);
        }
        if (doom) { puts("YES"); return 0; }
    }

    puts("NO"); return 0;
}