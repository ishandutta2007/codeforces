#include <cstdio>
#include <algorithm>
//#include <vector>
#include <utility>
static const int MAXN = 3004;
static const int MAXLEN = 12;

int n;
//typedef std::pair<int, char *> qwq;
struct qwq {
    int first; char *second;
    int idx;
};
inline bool operator < (const qwq &lhs, const qwq &rhs) {
    return lhs.first < rhs.first;
}
qwq p[MAXN];
//std::vector<qwq> s;
qwq s[MAXN];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        p[i].second = new char[MAXLEN];
        scanf("%s%d", p[i].second, &p[i].first);
    }
    std::sort(p, p + n);
    for (int i = 0; i < n; ++i) p[i].idx = i;

    bool valid = true;
    if (p[0].first > 0) valid = false;
    else s[0] = p[0];
    if (valid) for (int i = 1; i < n; ++i) {
        if (p[i].first > i) { valid = false; break; }
        for (int j = i - 1; j >= p[i].first; --j) s[j + 1] = s[j];
        s[p[i].first] = p[i];
    }

    if (valid) {
        for (int i = 0; i < n; ++i)
            p[s[i].idx].first = 100000 - i;
        for (int i = 0; i < n; ++i) printf("%s %d\n", p[i].second, p[i].first);
    } else puts("-1");

    return 0;
}