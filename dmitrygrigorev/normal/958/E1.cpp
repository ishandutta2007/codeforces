#include <bits/stdc++.h>
#define int long long
#define pp pair
using namespace std;
 struct Point {
	double x, y;
	Point(double _x, double _y) : x(_x), y(_y) {}
	Point() : x(0), y(0) {}
};

ostream& operator<<(ostream& os, const Point& p1) {
	os << p1.x << " " << p1.y;
	return os;
}

istream& operator>>(istream& os, Point& p1) {
	os >> p1.x >> p1.y;
	return os;
}

bool operator!=(Point p1, Point p2) {
	return p1.x != p2.x || p1.y != p2.y;
}

Point operator-(Point p1, Point p2) {
	return Point(p1.x - p2.x, p1.y - p2.y);
}

Point operator-(Point p1) {
	return Point(-p1.x, -p1.y);
}

Point operator+(Point p1, Point p2) {
	return Point(p1.x + p2.x, p1.y + p2.y);
}

double operator*(Point p1, Point p2) {
	return p1.x * p2.x + p1.y * p2.y;
}

Point operator*(Point p1, double x) {
	return Point(p1.x * x, p1.y * x);
}

Point operator/(Point p1, double x) {
	return Point(p1.x / x, p1.y / x);
}

double operator%(Point p1, Point p2) {
	return p1.x * p2.y - p2.x * p1.y;
}

double siz(Point p1) {
	return sqrt(p1.x * p1.x + p1.y * p1.y);
}

Point norm(Point p1) {
	return Point(-p1.y, p1.x);
}

int sign(double x) {
	if (x < 0) return -1;
	if (x == 0)	return 0;
	if (x > 0) return 1;
}

bool kek1(Point vt, Point p1) {
    return vt % p1 == 0 && vt * p1 >= 0;
}

bool get_segment(Point A, Point B, Point C, Point D) {
	int sig1 = sign((B - A) % (C - A)) * sign((B - A) % (D - A));
    int sig2 = sign((C - D) % (A - D)) * sign((C - D) % (B - D));
    if (sig1 < 0 && sig2 < 0) {
        return true;
    }
    if (sig1 > 0 || sig2 > 0) {
    	return false;
    }
    if (sig1 == 0 && sig2 == 0) {
        int l = C.x;
        int r = D.x;
        if (l > r) swap(l, r);

        int l1 = A.x;
        int r1 = B.x;
        if (l1 > r1) swap(l1, r1);

        int l3 = C.y;
        int r3 = D.y;
        if (l3 > r3) swap(l3, r3);

        int l4 = A.y;
        int r4 = B.y;
        if (l4 > r4) swap(l4, r4);
        if (max(l, l1) > min(r, r1) || max(l3, l4) > min(r3, r4)) {
        	return false;
        }
    	return true;
    }
    Point vt1 = B - A, vt2 = C - D;
    if (kek1(vt1, C - A) && kek1(-vt1, C - B)) {
    	return true;
    }
    if (kek1(vt1, D - A) && kek1(-vt1, D - B)) {
    	return true;
    }
    if (kek1(vt2, A - D) && kek1(-vt2, A - C)) {
    	return true;
    }
    if (kek1(vt2, B - D) && kek1(-vt2, B - C)) {
    	return true;
    }
	return false;
}

bool onLine(Point A, Point B, Point C) {
	return (A - B) % (C - B) == 0;
}

bool point_on_vt(Point A, Point B, Point C)  {
	return onLine(A, B, C) && (A - B) * (C - B) >= 0 && (B - A) * (C - A) >= 0;
}
pp<int, Point> get_intersection(Point A, Point B, Point C, Point D) {
	Point O;
    Point v = B - A;
    double s1 = (C - A) % (D - A);
    double s2 = (D - B) % (C - B);
    double s = s1 + s2;
    if(s == 0) {
        if((D - C) % (B - A) == 0 && !onLine(C, D, A) && !onLine(A, B, C)) {
            return {0, Point(-1e10, -1e10)};
        }
        return {2, A};
    }
    v = v / s;
    v = v * s1;
    O = A + v;
    return {1, O};
}
vector<Point> x, y;
int a, b;
bool dp[10][10][10][10];
void get_rec(vector<int> &c){
    if (c.size() == a){
        cout << "Yes" << endl;
        exit(0);
    }
    vector<bool> used(a);
    fill(used.begin(), used.end(), false);
    for (int i=0; i < c.size(); i++) used[c[i]] = true;
    for (int i=0; i < a; i++){
        if (used[i]) continue;
        bool able = true;
        for (int j=0; j < c.size(); j++){
            if (!dp[0][c[j]][c.size()][i]) able = false;
        }
        if (able){
            c.push_back(i);
            get_rec(c);
            c.pop_back();
        }
    }
}
signed main() {
    cin >> a >> b;
    if (a!=b){
        cout << "No" << endl;
        return 0;
    }
    if (a==1){
        cout << "Yes" << endl;
        return 0;
    }
    for (int i=0; i<a; i++){
        int c, d;
        cin >> c >> d;
        x.push_back({c, d});
    }
    for (int i=0; i<b; i++){
        int c, d;
        cin >> c >> d;
        y.push_back({c, d});
    }
    for (int i=0; i < a; i++){
        for (int j=0; j < b; j++){
            for (int k=0; k < a; k++){
                for (int l=0; l < b; l++){
                    if (i==k || j==l) continue;
                    bool nm = get_segment(x[i], y[j], x[k], y[l]);
                    if (!nm){
                         dp[i][j][k][l] = true;
                    }
                    else dp[i][j][k][l] = false;
                }
            }
        }
    }
    vector<int> p;
    get_rec(p);
    cout << "No";
    return 0;
}