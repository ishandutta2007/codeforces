#include <cstdio>
#include <algorithm>
static const int MAXN = 1e5 + 4;

int n;
std::pair<std::pair<int, int>, int> s[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &s[i].first.first, &s[i].first.second);
        s[i].first.second = -s[i].first.second;
        s[i].second = i + 1;
    }
    std::sort(s, s + n);
    for (int i = 1; i < n; ++i)
        if (s[i].first.second < s[0].first.second) { puts("-1"); return 0; }
    printf("%d\n", s[0].second);
    return 0;
}