#include <cstdio>
#include <vector>
static const int MAXN = 102;
static const int MAXQ = 1e5 + 4;

int n, q;
int t[MAXQ], k[MAXQ], d[MAXQ];
int next_free[MAXN] = { 0 };
std::vector<int> arranged;

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < q; ++i) scanf("%d%d%d", &t[i], &k[i], &d[i]);

    arranged.reserve(n * 2);
    for (int i = 0; i < q; ++i) {
        arranged.clear();
        for (int j = 0; j < n && (int)arranged.size() < k[i]; ++j)
            if (next_free[j] <= t[i]) arranged.push_back(j);
        if ((int)arranged.size() < k[i]) { puts("-1"); continue; }
        int sum = 0;
        for (std::vector<int>::iterator j = arranged.begin(); j != arranged.end(); ++j) {
            next_free[*j] = t[i] + d[i];
            sum += (*j + 1);
        }
        printf("%d\n", sum);
    }

    return 0;
}