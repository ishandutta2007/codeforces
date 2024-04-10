#include <bits/stdc++.h>

using namespace std;

#define double long double
using Point = complex<double>;
#define X() real()
#define Y() imag()
struct Circle { Point c; double r; };

const double kEps = 1e-12;

Point perp(Point p) { return {p.Y(), -p.X()}; }
void Intersect(Circle& A, Circle& B, vector<Point>& V) {
    Point a = A.c, b = B.c;
    double r1 = A.r, r2 = B.r;
    Point delta = b - a;
	if (abs(delta) < kEps) return;
    double r = r1 + r2, d2 = norm(delta);
	double p = (d2 + r1*r1 - r2*r2) / (2.0 * d2);
	double h2 = r1*r1 - p*p*d2;
	if (d2 > r*r + kEps || h2 < -kEps) return;
	Point mid = a + delta*p, per = perp(delta) * sqrt(abs(h2) / d2);
    V.push_back(mid - per);
    V.push_back(mid + per);
}

int main() {
//    ifstream cin("cerc.in");
//    ofstream cout("cerc.out");

    int n; cin >> n;
    vector<Circle> circles(n);
    for (int i = 0; i < n; ++i) {
        double a, b; cin >> a >> b;
        circles[i].c = Point{a, b};
        cin >> circles[i].r;
    }

    vector<Point> special;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            Intersect(circles[i], circles[j], special);
        }
    }

    sort(special.begin(), special.end(), [&](Point a, Point b) {
        if (abs(a.X() - b.X()) < kEps)
            return a.Y() < b.Y();
        return a.X() < b.X();
    });
    
    special.erase(unique(special.begin(), special.end(), 
        [&](Point a, Point b) { return norm(a - b) < kEps; }), special.end());
    
    int vertices = special.size();
    int edges = 0;

    vector<int> link(n);
    for (int i = 0; i < n; ++i)
        link[i] = i;

    for (int i = 0; i < vertices; ++i) {
        vector<int> circs;
        for (int j = 0; j < n; ++j) {
            Point delta = special[i] - circles[j].c;
            if (abs(abs(delta) - circles[j].r) < kEps) {
                circs.push_back(j);
                ++edges;
            }
        }
        int root = circs.back();
        for (auto& oth : circs) {
            if (link[oth] != link[root]) {
                int look = link[oth];
                for (int i = 0; i < n; ++i) {
                    if (link[i] == look)
                        link[i] = link[root];
                }
            }
        }
    }


    // v - e + f = 2
    // f = 2 + e - v
    int faces = 2 + edges - vertices;
    
    for (int i = 0; i < n; ++i)
        if (i == link[i])
            faces += 1;
    cout << faces - 1 << endl;

    return 0;
}