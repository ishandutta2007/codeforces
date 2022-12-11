#include <cstdio>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
typedef long long int64;
static const int MAXN = 100008;
static const double EPS = 1e-7;
static const int64 INF = 2e9;
static const int64 INF_SQR = INF * INF;

int n;
int x_0, y_0, v, t;
double rg;
double x[MAXN], y[MAXN], r[MAXN];

typedef std::pair<double, bool> endpoint;
typedef std::vector<endpoint> eplist;
eplist endpoints;
inline void add_range(double start, double end) {
    if (start < -M_PI - EPS) {
        endpoints.push_back(endpoint(-M_PI, true));
        endpoints.push_back(endpoint(end, false));
        endpoints.push_back(endpoint(start + M_PI * 2, true));
        endpoints.push_back(endpoint(M_PI, false));
    } else if (end > M_PI + EPS) {
        endpoints.push_back(endpoint(start, true));
        endpoints.push_back(endpoint(M_PI, false));
        endpoints.push_back(endpoint(-M_PI, true));
        endpoints.push_back(endpoint(end - M_PI * 2, false));
    } else {
        endpoints.push_back(endpoint(start, true));
        endpoints.push_back(endpoint(end, false));
    }
}

int main()
{
    scanf("%d%d%d%d%d", &x_0, &y_0, &v, &t, &n);
    rg = std::min((double)INF, (double)v * t);
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf%lf", &x[i], &y[i], &r[i]);
        x[i] -= x_0;
        y[i] -= y_0;
    }
    for (int i = 0; i < n; ++i) {
        int64 dist_sqr = (int64)x[i] * (int64)x[i] + (int64)y[i] * (int64)y[i];
        double dist = sqrt(dist_sqr);
        double cent_ang = atan2(y[i], x[i]);
        if (dist_sqr <= (int64)r[i] * (int64)r[i]) {
            add_range(-M_PI, M_PI);
        } else if (rg == INF || dist_sqr <= (int64)rg * (int64)rg + (int64)r[i] * (int64)r[i]) {
            // Two tangent lines
            double rg_ang = asin(r[i] / dist);
            add_range(cent_ang - rg_ang, cent_ang + rg_ang);
        } else if (dist <= r[i] + rg + EPS) {
            // Law of cosines
            double rg_ang = acos(
                (rg * rg + x[i] * x[i] + y[i] * y[i] - r[i] * r[i])
                / (sqrt(x[i] * x[i] + y[i] * y[i]) * rg * 2));
            add_range(cent_ang - rg_ang, cent_ang + rg_ang);
        }
    }
    std::sort(endpoints.begin(), endpoints.end());
    int ref_cnt = 0;
    double last_start = -M_PI, tot = 0;
    for (eplist::iterator i = endpoints.begin(); i != endpoints.end(); ++i) {
        if (i->second) {    // Retain
            if (++ref_cnt == 1) last_start = i->first;
        } else {            // Release
            if (--ref_cnt == 0) tot += (i->first - last_start);
        }
    }
    printf("%.12lf\n", tot / (M_PI * 2));
    return 0;
}