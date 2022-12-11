#include <cstdio>
#include <algorithm>
#include <set>
#include <utility>
static const int MAXN = 10005;

int n;
int p[MAXN];
std::pair<int, int> diameter;
std::set< std::pair<int, int> > s;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) { scanf("%d", &p[i]); --p[i]; }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int u = p[i], v = p[u];
        diameter = std::make_pair(std::min(u, v), std::max(u, v));
        if (s.find(diameter) == s.end()) {
            ++ans;
            s.insert(diameter);
        }
    }

    printf("%d\n", ans);
    return 0;
}