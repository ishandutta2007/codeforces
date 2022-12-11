#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
typedef std::pair<int, int> face;
template <typename T> inline T max3(const T a, const T b, const T c) { return std::max(std::max(a, b), c); }
template <typename T> inline T min3(const T a, const T b, const T c) { return std::min(std::min(a, b), c); }
static const int MAXN = 1e5 + 6;
struct info {
    std::pair<int, int> primary;
    std::pair<int, int> secondary;
    info() : primary(std::make_pair(-1, -1)), secondary(std::make_pair(-1, -1)) { }
    info(const std::pair<int, int> p) : primary(p), secondary(std::make_pair(-1, -1)) { }
    inline void insert(const std::pair<int, int> rhs) {
        if (rhs > primary && rhs.second != primary.second) { secondary = primary; primary = rhs; }
        else if (rhs > secondary && rhs.second != secondary.second) { secondary = rhs; }
    }
    inline std::pair<int, int> select_exclude(const int idx) const {
        if (primary.second == idx)
            return (secondary.second == idx ? std::make_pair(-1, -1) : secondary);
        else return primary;
    }
};

int n;
int a[MAXN][3];
std::map<face, info> other;

inline void update(const face f, const std::pair<int, int> len) {
    static std::map<face, info>::iterator p;
    p = other.find(f);
    if (p == other.end()) other.insert(std::make_pair(f, info(len)));
    else p->second.insert(len);
}

inline std::pair<int, int> get(const face f, int idx) {
    static std::map<face, info>::iterator p;
    p = other.find(f);
    if (p == other.end()) return std::make_pair(-1, -1);
    else return p->second.select_exclude(idx);
}

int main()
{
    scanf("%d", &n);

    std::pair< int, std::pair<int, int> > ans
        = std::make_pair(0, std::make_pair(-1, -1));
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
        std::sort(a[i], a[i] + 3);
        update(face(a[i][0], a[i][1]), std::make_pair(a[i][2], i));
        update(face(a[i][0], a[i][2]), std::make_pair(a[i][1], i));
        update(face(a[i][1], a[i][2]), std::make_pair(a[i][0], i));
        ans = std::max(ans, std::make_pair(
            min3(a[i][0], a[i][1], a[i][2]),
            std::make_pair(i, -1)));
    }

    std::pair<int, int> t;
    for (int i = 0; i < n; ++i) {
        if ((t = get(face(a[i][0], a[i][1]), i)).first != -1)
            ans = std::max(ans, std::make_pair(min3(a[i][0], a[i][1], t.first + a[i][2]), std::make_pair(i, t.second)));
        if ((t = get(face(a[i][0], a[i][2]), i)).first != -1)
            ans = std::max(ans, std::make_pair(min3(a[i][0], a[i][2], t.first + a[i][1]), std::make_pair(i, t.second)));
        if ((t = get(face(a[i][1], a[i][2]), i)).first != -1)
            ans = std::max(ans, std::make_pair(min3(a[i][1], a[i][2], t.first + a[i][0]), std::make_pair(i, t.second)));
    }

    if (ans.second.second == -1)
        printf("1\n%d\n", ans.second.first + 1);
    else printf("2\n%d %d\n", ans.second.first + 1, ans.second.second + 1);

    return 0;
}