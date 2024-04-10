#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
static const int MAXN = 2004;
static const int MAXM = 2007;
static const int IGNORABLE = MAXM - 1;

int n, m, ai, a[MAXN];
std::vector<int> occ[MAXM];
std::pair<int, int> occ_ct[MAXM];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai); --ai;
        a[i] = ai;
        if (ai >= m) ai = IGNORABLE;
        occ[ai].push_back(i);
    }

    int desired = n / m;
    for (int i = 0; i < m; ++i)
        occ_ct[i] = std::make_pair(occ[i].size(), i);
    std::sort(occ_ct, occ_ct + m);
    occ_ct[m] = std::make_pair(occ[IGNORABLE].size(), IGNORABLE);
    int p = m;
    for (int i = 0; i < m; ++i)
        if (occ_ct[i].first < desired) do {
            while (occ[occ_ct[p].second].size() <= (p == m ? 0 : desired)) --p;
            occ[occ_ct[i].second].push_back(occ[occ_ct[p].second].back());
            occ[occ_ct[p].second].pop_back();
        } while (occ[occ_ct[i].second].size() < desired);

    int change_ct = 0;
    for (int i = 0; i < m; ++i)
        for (std::vector<int>::iterator j = occ[i].begin(); j != occ[i].end(); ++j)
            if (a[*j] != i) { a[*j] = i; ++change_ct; }
    printf("%d %d\n", desired, change_ct);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i] + 1, i == n - 1 ? '\n' : ' ');

    return 0;
}