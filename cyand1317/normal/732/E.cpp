#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
static const int MAXN = 200006;

int n, m;
int pi;
std::multimap<int, int> p;
std::pair<int, int> s[MAXN];
std::pair<int, int> ans[MAXN];
int adapters[MAXN];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) { scanf("%d", &pi); p.insert(std::make_pair(pi, i)); }
    for (int i = 0; i < m; ++i) { scanf("%d", &s[i].first); s[i].second = i; }
    std::sort(s, s + m);

    for (int i = 0; i < n; ++i) ans[i] = std::make_pair(-1, -1);
    int max_computers = 0, min_cost = 0;
    std::multimap<int, int>::iterator it;
    for (int i = 0; i < m; ++i) {
        int cost = 0;
        do {
            if ((it = p.find(s[i].first)) != p.end()) {
                ans[it->second] = std::make_pair(s[i].second, cost);
                max_computers += 1; min_cost += cost;
                p.erase(it);
                break;
            }
            if (s[i].first == 1) break;
            s[i].first = (s[i].first + 1) / 2; ++cost;
        } while (true);
    }

    for (int i = 0; i < n; ++i)
        if (ans[i].first != -1) adapters[ans[i].first] = ans[i].second;
    printf("%d %d\n", max_computers, min_cost);
    for (int i = 0; i < m; ++i) printf("%d%c", adapters[i], i == m - 1 ? '\n' : ' ');
    for (int i = 0; i < n; ++i) printf("%d%c", ans[i].first + 1, i == n - 1 ? '\n' : ' ');

    return 0;
}