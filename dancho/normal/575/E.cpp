#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int NMAX = 1 << 20;
const double eps = 1e-7;

struct pt {
	double x, y;
};

bool cmp (pt a, pt b) {
	return ((a.x + eps < b.x) || (a.x == b.x && a.y + eps < b.y));
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 &&
  !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 &&
!ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a.clear();
	for (size_t i=0; i<up.size(); ++i)
		a.push_back (up[i]);
	for (size_t i=down.size()-2; i>0; --i)
		a.push_back (down[i]);
}

typedef pt point;

struct circle {
    point c;
    double r;
    point o1, o2, o3;
};

point P[NMAX];
circle D[NMAX];

double dist2(point p,point q) {
    return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}
double dist(point p,point q) {
    return sqrt(dist2(p,q));
}
bool in_circle(point p,circle c){
    return (dist2(p,c.c) <= c.r*c.r);
}
point middle(point p,point q) {
    return (point) { (p.x + q.x)/2.0, (p.y + q.y)/2.0 };
}
point make_point(double x,double y) { return (point) { x, y }; }

circle make_circle(point p) { return (circle) { p, 0.0 }; }
circle make_circle (point p,point q) { return (circle) { middle(p, q), dist(p, q)/2.0, p, q, {-1, -1} }; }

bool perpendicular(point a,point b,point c){
    double yDelta_a = b.y - a.y, xDelta_a = b.x - a.x,
   		yDelta_b = c.y - b.y, xDelta_b = c.x - b.x;
    if (fabs(xDelta_a) <= eps && fabs(yDelta_b) <= eps) return false;
    if (fabs(yDelta_a) <= eps) return true; if (fabs(yDelta_b) <= eps) return true;
    if (fabs(xDelta_a) <= eps) return true; if (fabs(xDelta_b) <= eps) return true;
    return false;
}

circle calc_circle(point a,point b,point c) {
    double yDelta_a = b.y - a.y, xDelta_a = b.x - a.x,
   		yDelta_b = c.y - b.y, xDelta_b = c.x - b.x;
    circle resp;
    resp.o1 = a;
    resp.o2 = b;
    resp.o3 = c;
    if (fabs(xDelta_a) <= eps && fabs(yDelta_b) <= eps) {
   	 resp.c.x = 0.5*(b.x + c.x);
   	 resp.c.y = 0.5*(a.y + b.y);
   	 resp.r = dist(resp.c , a);
   	 return resp;
    }
    double aSlope = yDelta_a/xDelta_a;
    double bSlope = yDelta_b/xDelta_b;
    if (fabs(aSlope-bSlope) <= eps) {
   	 return make_circle(a,b);
    }
    resp.c.x = (aSlope*bSlope*(a.y - c.y) + bSlope*(a.x + b.x) - aSlope*(b.x + c.x))/
   	 (2.0 * (bSlope-aSlope));
    resp.c.y = -1.0*(resp.c.x - (a.x + b.x)/2.0)/aSlope + (a.y + b.y)/2.0;
    resp.r = dist(resp.c , a);
    return resp;
}

circle make_circle(point a, point b, point c){
    if (!perpendicular(a,b,c)) return calc_circle(a,b,c);
    if (!perpendicular(a,c,b)) return calc_circle(a,c,b);
    if (!perpendicular(b,a,c)) return calc_circle(b,a,c);
    if (!perpendicular(b,c,a)) return calc_circle(b,c,a);
    if (!perpendicular(c,b,a)) return calc_circle(c,b,a);
    if (!perpendicular(c,a,b)) return calc_circle(c,a,b);
    return make_circle(a,b);
}
circle MiniDiscWith2Points(int N,point p,point q){
    circle at = make_circle(p, q);
    for (int i = 0; i < N; i++) {
   	 if (i == 0 && in_circle(P[i],at)) D[i] = at;
   	 else if (i != 0 && in_circle(P[i],D[i-1])) D[i] = D[i-1];
   	 else D[i] = make_circle(p,q,P[i]);
    }
    return D[N-1];
}
circle MiniDiscWithPoint(int N, point q){
    D[0] = make_circle(P[0],q);
    for(int i = 1; i < N; i++){
   	 if (in_circle(P[i],D[i-1])) D[i] = D[i-1];
   	 else D[i] = MiniDiscWith2Points(i,P[i],q);
    }
    return D[N-1];
}
circle MiniDisc(int N){
    if(N <= 1) return make_circle(P[0]);
    random_shuffle(P, P+N);
    D[1] = make_circle(P[0],P[1]);
    for (int i = 2; i < N; i++){
   	 if (in_circle(P[i],D[i-1])) D[i] = D[i-1];
   	 else D[i] = MiniDiscWithPoint(i,P[i]);
    }
    return D[N-1];
}


int main() {
    int m = 0;
    int n;
    scanf("%d", &n);
    vector<int> x(n), y(n), v(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d", &x[i], &y[i], &v[i]);

        if (x[i] - v[i] >= 0) {
            P[m++] = make_point(x[i] - v[i], y[i]);
        } else {
            // intersect with x = 0. (0, z) where 0 + z = x[i] - v[i] + y[i]
            int z = x[i] - v[i] + y[i];
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(0, z);
            } else if (z < 0) {
                P[m++] = make_point(0, 0);
            } else if (z > 100000) {
                P[m++] = make_point(0, 100000);
            }

            z = y[i] - x[i] + v[i];
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(0, z);
            } else if (z < 0) {
                P[m++] = make_point(0, 0);
            } else if (z > 100000) {
                P[m++] = make_point(0, 100000);
            }
        }

        if (x[i] + v[i] <= 100000) {
            P[m++] = make_point(x[i] + v[i], y[i]);
        } else {
            // (100000, z) ; z 
            int z = x[i] + v[i] + y[i] - 100000;
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(100000, z);
            } else if (z < 0) {
                P[m++] = make_point(100000, 0);
            } else if (z > 100000) {
                P[m++] = make_point(100000, 100000);
            }

            z = y[i] - x[i] - v[i] + 100000;
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(100000, z);
            } else if (z < 0) {
                P[m++] = make_point(100000, 0);
            } else if (z > 100000) {
                P[m++] = make_point(100000, 100000);
            }
        }

        if (y[i] - v[i] >= 0) {
            P[m++] = make_point(x[i], y[i] - v[i]);
        } else {
            // (z, 0)
            int z = x[i] + y[i] - v[i];
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(z, 0);
            } else if (z < 0) {
                P[m++] = make_point(0, 0);
            } else {
                P[m++] = make_point(100000, 0);
            }

            z = x[i] - y[i] + v[i];
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(z, 0);
            } else if (z < 0) {
                P[m++] = make_point(0, 0);
            } else {
                P[m++] = make_point(100000, 0);
            }
        }

        if (y[i] + v[i] <= 100000) {
            P[m++] = make_point(x[i], y[i] + v[i]);
        } else {
            // (z, 100000)
            int z = x[i] + y[i] + v[i] - 100000;
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(z, 100000);
            } else if (z < 0) {
                P[m++] = make_point(0, 100000);
            } else {
                P[m++] = make_point(100000, 100000);
            }

            z = x[i] - y[i] - v[i] + 100000;
            if (z >= 0 && z <= 100000) {
                P[m++] = make_point(z, 100000);
            } else if (z < 0) {
                P[m++] = make_point(0, 100000);
            } else {
                P[m++] = make_point(100000, 100000);
            }
        }
    }
    vector<pt> ch;
    for (int i = 0; i < m; ++i) {
        ch.push_back(P[i]);
    }
    convex_hull(ch);
    circle ou = make_circle(ch[0], ch[1], ch[2]);
    for (int i = 1; i < (int) ch.size(); ++i) {
        circle o = make_circle(ch[i], ch[(i + 1) % ch.size()], ch[(i + 2) % ch.size()]);
        if (o.r > ou.r) {
            ou = o;
        }
    }
    // printf("REALLY? %lf %lf %lf\n", ou.c.x, ou.c.y, ou.r);
    printf("%.0lf %.0lf\n", ou.o1.x, ou.o1.y);
    printf("%.0lf %.0lf\n", ou.o2.x, ou.o2.y);
    printf("%.0lf %.0lf\n", ou.o3.x, ou.o3.y);

    return 0;
}