#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

struct pt {
    double x, y;
    pt(): x(0), y(0) {}
    pt(double x, double y): x(x), y(y) {}
};
pt operator -(pt A, pt B) { return {A.x-B.x, A.y-B.y}; }
double operator *(pt A, pt B) { return A.x*B.x + A.y*B.y; }
double norm(pt A) { return sqrt(A*A); }
pt operator /(pt A, double lambda) { return {A.x/lambda, A.y/lambda}; }
ostream& operator<<(ostream& out, pt P) {
    out << "(" << P.x << ", " << P.y << ")";
    return out;
}

// P(s) = as + bs +c
// {l < s < r: P(s) < 0}
void neg_interval(double a, double b, double c, double l, double r,
                  vector<pair<double,double>>& ans) {
    assert(abs(a-1) < 1e-5 or a < 0);
    if (a > 0) {
        b /= a, c /= a, a = 1;
        if (b*b < 4*a*c) return;
        double delta = sqrt(b*b-4*a*c);
        double l0 = (-b - delta)/2;
        double r0 = (-b + delta)/2;
        l0 = max(l0, l);
        r0 = min(r0, r);
        if (l0 < r0) ans.emplace_back(l0, r0);
    }
    if (a < 0) {
        double s = sqrt(a*a + b*b + c*c);
        a /= s, b /= s, c /= s; // renormalization
        if (b*b < 4*a*c) {
            ans.emplace_back(l, r);
            return;
        }
        double delta = sqrt(b*b-4*a*c);
        double l0 = (-b + delta)/(2*a);
        double r0 = (-b - delta)/(2*a);
        // The following lines are necessary to handle appropriately a close to 0.
        if (-0.01 < a) {
            if (b > 0) l0 = (-2*c)/(b+delta);
            else r0 = (2*c)/(-b + delta);
        }
        
        if (l < l0) ans.emplace_back(l, min(l0, r));
        if (r0 < r) ans.emplace_back(max(l, r0), r);
    }
}

// Q(s, t) = s + t + ast + bs + ct + d
// {l0 < s < r0: \min_{l1 < t < r1} Q(s, t) < 0}
void neg_interval(double a, double b, double c, double d,
                  double l0, double r0, double l1, double r1,
                  vector<pair<double,double>>& ans) {
    assert(a >= 1.99);
    // argmin_t Q(s, t) = -(as+c)/2 in [l1, r1]
    double lmin = (-2 * r1 - c)/a;
    double rmin = (-2 * l1 - c)/a;
    lmin = max(lmin, l0);
    rmin = min(rmin, r0);
    // argmin in [l1,r1] <-> lmin < s < rmin
    if (lmin < rmin) neg_interval(1-a*a/4, b-a*c/2, d-c*c/4, lmin, rmin, ans);
    neg_interval(1, a*l1+b, l1*l1+c*l1+d, l0, r0, ans);
    neg_interval(1, a*r1+b, r1*r1+c*r1+d, l0, r0, ans);
}

void good_interval(pt A, pt B, pt C, pt D, double v, double l, vector<pair<double,double>>& ans) {
    double lA = 0;
    double rA = norm(B-A);
    pt dA = (B-A)/rA;
    double lC = 0;
    double rC = norm(D-C);
    pt dC = (D-C)/rC;
    // v*v*(A+s*dA - C - t*dC)^2 - (l + t - s)^2 < 0
    if (v >= sqrt(2/(1+dA*dC))) return; // if ==, then c2 = 2c1 (and a = 2).
    double c1 = v*v - 1; // s and t
    double c2 = 2*(1- (v*v)*(dA*dC)); // st
    double c3 = 2*v*v*((A-C)*dA) + 2*l; // s
    double c4 = -2*v*v*((A-C)*dC) - 2*l; // t
    double c5 = v*v * ((A-C)*(A-C)) - l*l; // const
    c2 /= c1, c3 /= c1, c4 /= c1, c5 /= c1;
    
    neg_interval(c2, c3, c4, c5, lA, rA, lC, rC, ans);
}

bool nonempty_intersection(pair<double,double> I1, pair<double,double> I2) {
    return max(I1.first, I2.first) < min(I1.second, I2.second);
}

const int MAXN = 51;
pt P[MAXN];
double len[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    for (int i = 0; i <= N; i++) cin >> P[i].x >> P[i].y;
    for (int i = 1; i < N; i++) len[i] = len[i-1] + norm(P[i]-P[i-1]);

    if (N <= 2) {
        cout << 1 << "\n";
        return 0;
    }

    double l = 1;
    double r = 20;
    for (int it = 0; it < 50; it++) {
        bool good = false;
        double v = (l+r)/2;
        for (int i = 1; i < N-1; i++) {
            vector<pair<double,double>> bef, aft;
            for (int j = 0; j < i; j++)
                good_interval(P[i], P[i+1], P[j], P[j+1], v, len[j]-len[i], bef);
            for (int j = i+1; j < N; j++)
                good_interval(P[i], P[i+1], P[j], P[j+1], v, len[j]-len[i], aft);
            for (auto& I: bef) for (auto& J: aft) good |= nonempty_intersection(I, J);
        }
        if (good) l = v;
        else r = v;
    }

    cout.precision(10);
    cout << l << "\n";
}