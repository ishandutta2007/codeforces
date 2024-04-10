#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define fuck(x) cout<<"["<<x<<"]"
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)
using namespace std;
typedef long long LL;

const int MX = 1e5 + 10;
const int INF = 1e6;
const double eps = 1e-9;

struct Point {
    double x, y;
    bool operator<(const Point&b) const {
        if(x == b.x) return y < b.y;
        return x < b.x;
    }
    Point() {}
    Point(double _x, double _y) {
        x = _x; y = _y;
    }
} P[MX], R[MX];

double cross(Point a, Point b, Point c) {
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

int convex(int n) {
    int m = 0, k;
    sort(P, P + n);
    for(int i = 0; i < n; i++) {
        while(m > 1 && cross(R[m - 1], P[i], R[m - 2]) <= eps) m--;
        R[m++] = P[i];
    }

    k = m;
    for(int i = n - 2; i >= 0; i--) {
        while(m > k && cross(R[m - 1], P[i], R[m - 2]) <= eps) m--;
        R[m++] = P[i];
    }
    if(n > 1) m--;
    return m;
}

int n, rear;
Point p;

double solve() {
    double ret = INF;
    for(int i = 0; i < n + 3; i++) {
        if(fabs(P[i].x) > eps && fabs(P[i].y) > eps){
            ret = min(ret, max(p.x / P[i].x, p.y / P[i].y));
        }
    }
    for(int i = 1; i < rear - 1; i++) {
        double a = R[i].x, b = R[i].y, c = R[i + 1].x, d = R[i + 1].y;
        double x = (a * p.y - b * p.x) / (a * d - b * c), y = (c * p.y - d * p.x) / (c * b - a * d);
        if(x < -eps || y < -eps) continue;
        ret = min(ret, x + y);
    }
    return ret;
}

int main() {
    //FIN;
    while(~scanf("%d%lf%lf", &n, &p.x, &p.y)) {
        double max1 = 0, max2 = 0;
        for(int i = 0; i < n; i++) {
            scanf("%lf%lf", &P[i].x, &P[i].y);
            max1 = max(max1, P[i].x);
            max2 = max(max2, P[i].y);
        }
        P[n] = Point(max1, 0);
        P[n + 1] = Point(0, max2);
        P[n + 2] = Point(0, 0);
        rear = convex(n + 3);
        printf("%.15f\n", (double)solve());
    }
    return 0;
}