#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
static const int MAXN = 200007;

int n, q;
int value[MAXN];
std::vector<int> moments[MAXN];

struct presence_cmp {
    inline bool operator () (const int lhs, const int rhs) {
        return moments[lhs].back() < moments[rhs].back();
    }
};

std::set<int, presence_cmp> present;
int query[MAXN];

int main()
{
    scanf("%d", &n);
    int k_i;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &k_i, &value[i]);
        moments[k_i].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        if (!moments[i].empty()) present.insert(i);
    }

    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        scanf("%d", &k_i);
        for (int j = 0; j < k_i; ++j) {
            scanf("%d", &query[j]);
            if (!moments[query[j]].empty()) present.erase(query[j]);
        }
        if (present.size() == 0) {
            puts("0 0");
        } else {
            std::set<int, presence_cmp>::reverse_iterator p = present.rbegin(), q = p++;
            int winner = *q, runner_up = (p == present.rend() ? -1 : *p), bid;
            if (runner_up == -1) bid = moments[winner][0];
            else bid = *std::lower_bound(moments[winner].begin(), moments[winner].end(), moments[runner_up].back());
            printf("%d %d\n", winner, value[bid]);
        }
        for (int j = 0; j < k_i; ++j) {
            if (!moments[query[j]].empty()) present.insert(query[j]);
        }
    }

    return 0;
}