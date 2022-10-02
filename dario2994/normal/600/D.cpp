#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

template <typename Container>
int SZ(const Container& S) { return S.size(); }

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

double f(long double theta) {
    return theta - cos(theta)*sin(theta);
    if (theta > 1e-4) return theta - cos(theta)*sin(theta);
    return pow(theta, 3.0)*(2.0/3.0);
}

int main() {
    cout.precision(15);
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    ULL x1, y1, r1;
    ULL x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if (x1 < x2) swap(x1, x2);
    if (y1 < y2) swap(x1, x2);
    if (r1 < r2) swap(r1, r2);
    ULL dd = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    long double R1 = r1;
    long double R2 = r2;
    long double D = sqrt((long double)dd);
    if (dd >= (r1+r2)*(r1+r2)) {
        cout << 0 << "\n";
        return 0;
    }
    if ((r1-r2)*(r1-r2) >= dd) {
        cout << fixed << M_PI*r2*r2 << "\n";
        return 0;
    }
    
    long double d1 = (pow(R1, 2.0) - pow(R2, 2.0) + pow(D, 2.0)) / (2.0*D);
    long double d2 = (pow(R2, 2.0) - pow(R1, 2.0) + pow(D, 2.0)) / (2.0*D);
    
    long double theta1 = acos(d1/R1);
    long double theta2 = acos(d2/R2);
    long double area1 = f(theta1) * pow(R1, 2.0);
    long double area2 = f(theta2) * pow(R2, 2.0);
    cout << fixed << area1 + area2 << "\n";
    return 0;
}