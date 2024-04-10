#include <cstdio>
#include <cmath>
#include <utility>
typedef long long int64;
static const int MAXN = 100007;
template <typename T> inline T sqr(const T a) { return a * a; }
template <typename T> inline T min(const T a, const T b) { return a < b ? a : b; }
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

struct point {
    int64 x, y;

    inline void scan() { scanf("%I64d%I64d", &this->x, &this->y); }
    inline double dist(const point rhs) {
        return sqrt(sqr(this->x - rhs.x) + sqr(this->y - rhs.y));
    }
};

template <typename T> void two_largest(int n, T *a,
    std::pair<T, int> &r1, std::pair<T, int> &r2)
{
    r1 = r2 = std::make_pair(-1e18 - 4, -1);
    for (int i = 0; i < n; ++i) {
        std::pair<T, int> cur = std::make_pair(a[i], i);
        if (r1 < cur) { r2 = r1; r1 = cur; }
        else if (r2 < cur) r2 = cur;
    }
}

int n;
point adil, bera, bin;
point p[MAXN];
double d[MAXN];
std::pair<double, int> a_sav1, a_sav2, b_sav1, b_sav2;

int main()
{
    adil.scan();
    bera.scan();
    bin.scan();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) p[i].scan();

    double ans;
    if (n == 1) {
        ans = min(adil.dist(p[0]), bera.dist(p[0])) + p[0].dist(bin);
    } else {
        for (int i = 0; i < n; ++i) d[i] = bin.dist(p[i]) - adil.dist(p[i]);
        two_largest(n, d, a_sav1, a_sav2);
        for (int i = 0; i < n; ++i) d[i] = bin.dist(p[i]) - bera.dist(p[i]);
        two_largest(n, d, b_sav1, b_sav2);
        double initial = 0;
        for (int i = 0; i < n; ++i) initial += bin.dist(p[i]) * 2;
        if (a_sav1.second == b_sav1.second) {
            ans = initial - max(a_sav2.first + b_sav1.first, a_sav1.first + b_sav2.first);
        } else {
            ans = initial - (a_sav1.first + b_sav1.first);
        }
        ans = min(ans, initial - a_sav1.first);
        ans = min(ans, initial - b_sav1.first);
    }

    printf("%.12lf\n", ans);
    return 0;
}