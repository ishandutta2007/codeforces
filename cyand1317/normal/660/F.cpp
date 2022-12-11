#include <cstdio>
#include <cmath>
typedef long long int64;
static const int MAXN = 200007;
static const double INF = 3e18;
template <typename T> inline T max(const T a, const T b) { return a > b ? a : b; }

int n;
int a[MAXN];
int64 s1[MAXN], s2[MAXN];
// s2[R+1] - s2[L] - L * (s1[R+1] - s1[L]) is being maximized
// s2[R+1] - L * s1[R+1] + (-s2[L] + L * s1[L])
// ^const    ^slope        ^intercept
int64 slope[MAXN], itcpt[MAXN];

inline double eval(int line_idx, double arg)
{
    return (arg * slope[line_idx] + itcpt[line_idx]);
}
inline double intersection(int idx1, int idx2)
{
    return (double)(itcpt[idx1] - itcpt[idx2]) / (slope[idx2] - slope[idx1]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    s1[0] = s2[0] = 0;
    for (int i = 0; i < n; ++i) {
        s1[i + 1] = s1[i] + a[i];
        s2[i + 1] = s2[i] + (int64)a[i] * (i + 1);
    }

    int64 ans = 0;
    static int cvx_ln[MAXN], cvx_top = 1;
    static double cvx_pt[MAXN];
    slope[MAXN - 1] = -1; itcpt[MAXN - 1] = -INF - 3;
    cvx_ln[0] = -1; cvx_ln[1] = MAXN - 1;
    cvx_pt[0] = -INF; cvx_pt[1] = +INF;
    for (int i = 0; i < n; ++i) {
        int64 const_term = s2[i + 1], arg = -s1[i + 1];
        slope[i] = i;
        itcpt[i] = (int64)i * s1[i] - s2[i];
        while (cvx_top > 0 &&
            eval(cvx_ln[cvx_top], cvx_pt[cvx_top - 1]) < eval(i, cvx_pt[cvx_top - 1]))
        {
            --cvx_top;
        }
        ++cvx_top;
        cvx_ln[cvx_top] = i;
        cvx_pt[cvx_top - 1] = intersection(cvx_ln[cvx_top - 1], i);
        cvx_pt[cvx_top] = +INF;

        int lo = 1, hi = cvx_top, mid;
        while (lo < hi - 1) {
            mid = (lo + hi) >> 1;
            if (eval(cvx_ln[mid - 1], arg) < eval(cvx_ln[mid], arg)) lo = mid;
            else hi = mid;
        }
        ans = max(ans, (int64)(0.5 + eval(cvx_ln[lo], arg)) + const_term);
        ans = max(ans, (int64)(0.5 + eval(cvx_ln[cvx_top], arg)) + const_term);
    }
    printf("%I64d\n", ans);
    return 0;
}