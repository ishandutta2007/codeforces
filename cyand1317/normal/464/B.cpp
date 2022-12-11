// You have submitted exactly the same code before
// and got JF one time, CE two times, TLE one time and WA one time.
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <vector>
typedef long long int64;
typedef std::tuple<int, int, int> coord;
template <typename T> inline T sqr(const T x) { return x * x; }

coord a[8];
std::vector<coord> perm[8];

inline int64 dist_sqr(const coord &a, const coord &b)
{
    return
        sqr<int64>(std::get<0>(a) - std::get<0>(b)) +
        sqr<int64>(std::get<1>(a) - std::get<1>(b)) +
        sqr<int64>(std::get<2>(a) - std::get<2>(b));
}
inline bool check_cube(const coord a[8])
{
    int64 min_d = (1LL << 61);
    for (int i = 0; i < 7; ++i)
        for (int j = i + 1; j < 8; ++j) {
            int64 d = dist_sqr(a[i], a[j]);
            if (min_d > d) min_d = d;
        }
    if (min_d == 0) return false;
    int ct1 = 0, ct2 = 0, ct3 = 0;
    for (int i = 0; i < 7; ++i)
        for (int j = i + 1; j < 8; ++j) {
            int64 d = dist_sqr(a[i], a[j]);
            if (d % min_d != 0 || d >= min_d * 4) return false;
            if (d == min_d) ++ct1; else if (d == min_d * 2) ++ct2; else ++ct3;
        }
    return (ct1 == 12 && ct2 == 12 && ct3 == 4);
}
inline void print_coord(const coord &p)
{
    printf("%d %d %d\n", std::get<0>(p), std::get<1>(p), std::get<2>(p));
}

int main()
{
    for (int i = 0; i < 8; ++i) {
        int x[3]; scanf("%d%d%d", &x[0], &x[1], &x[2]);
        a[i] = std::make_tuple(x[0], x[1], x[2]);
        std::sort(x, x + 3);
        do perm[i].push_back(std::make_tuple(x[0], x[1], x[2])); while (std::next_permutation(x, x + 3));
    }

    coord x[8];
    for (auto a : perm[0])
    for (auto b : perm[1])
    for (auto c : perm[2])
    for (auto d : perm[3])
    for (auto e : perm[4])
    for (auto f : perm[5])
    for (auto g : perm[6])
    for (auto h : perm[7]) {
        x[0] = a, x[1] = b, x[2] = c, x[3] = d, x[4] = e, x[5] = f, x[6] = g, x[7] = h;
        if (check_cube(x)) {
            puts("YES");
            //print_coord(a); print_coord(b); print_coord(c); print_coord(d);
            //print_coord(e); print_coord(f); print_coord(g); print_coord(h);
            for (int i = 0; i < 8; ++i) print_coord(x[i]);
            goto _Exit;
        }
    }

    puts("NO");
_Exit:
    return 0;
}