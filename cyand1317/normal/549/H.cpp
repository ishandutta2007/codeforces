// Hisashiburi (/- -)/
#include <stdio.h>
#define PREC 1e-19
typedef long double ldouble;

inline ldouble min2(ldouble a, ldouble b) { return a < b ? a : b; }
inline ldouble min(ldouble a, ldouble b, ldouble c, ldouble d)
{ return min2(min2(a, b), min2(c, d)); }
inline ldouble max2(ldouble a, ldouble b) { return a > b ? a : b; }
inline ldouble max(ldouble a, ldouble b, ldouble c, ldouble d)
{ return max2(max2(a, b), max2(c, d)); }

ldouble a1, a2, b1, b2, c1, c2, d1, d2, ad_min, ad_max, bc_min, bc_max;
inline bool check(ldouble &a, ldouble &b, ldouble &c, ldouble &d, ldouble &p)
{
    a1 = a - p, a2 = a + p, b1 = b - p, b2 = b + p,
        c1 = c - p, c2 = c + p, d1 = d - p, d2 = d + p;
    ad_min = min(a1 * d1, a1 * d2, a2 * d1, a2 * d2),
        ad_max = max(a1 * d1, a1 * d2, a2 * d1, a2 * d2),
        bc_min = min(b1 * c1, b1 * c2, b2 * c1, b2 * c2),
        bc_max = max(b1 * c1, b1 * c2, b2 * c1, b2 * c2);
    return (
        (ad_max >= bc_min - PREC && ad_min <= bc_max + PREC)
        || (bc_max >= ad_min - PREC && bc_min <= ad_max + PREC));
}

int main()
{
    double _a, _b, _c, _d;
    ldouble a, b, c, d;
    scanf("%lf%lf%lf%lf", &_a, &_b, &_c, &_d);
    a = _a; b = _b; c = _c; d = _d; // Does %Lf work properly everywhere??
    // Just use == for a, b, c, d are integers at this time.
    if (a * d == b * c) puts("0");
    else {
        ldouble hi = 1e10, lo = 0, mid;
        for (int i = 0; i < 150; ++i) {
            mid = (hi + lo) * 0.5;
            if (check(a, b, c, d, mid)) hi = mid;
            else lo = mid;
        }
        printf("%.12lf\n", (double)((hi + lo) * 0.5));
    }
    return 0;
}