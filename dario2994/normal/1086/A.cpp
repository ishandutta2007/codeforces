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

const int MAXN = -1;

int path(int x, int y, int a, int b) {
    return abs(x-a) + abs(y-b)-1;
}

void paint_path(int a, int b, int c, int d) {
    // cout << a << " " << b << " " << c << " " << d << endl;
    // if (a > c) swap(a, c), swap(b, d);
    if (a == c) {
        for (int i = min(b, d)+1; i < max(b, d); i++) cout << a << " " << i << "\n";
        return;
    }
    if (b == d) {
        for (int i = min(a, c)+1; i < max(a, c); i++) cout << i << " " << b << "\n";
        return;
    }
    if (a > c) swap(a, c), swap(b, d);
    for (int i = min(a, c)+1; i <= max(a, c); i++) cout << i << " " << b << "\n";
    for (int i = min(b, d)+1; i < max(b, d); i++) cout << c << " " << i << "\n";
    // cout <<
    // a++;
    // while (a < c) {
    //     cout << a << " " << b << "\n";
    //     a++;
    // }
    // if (b > d) swap(b, d);
    // while (b < d) {
    //     cout << a << " " << b << "\n";
    //     b++;
    // }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int xa, xb, xc;
    int ya, yb, yc;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    int best_x, best_y;
    int K = 1e6;
    for (int x = 0; x <= 1000; x++) {
        for (int y = 0; y <= 1000; y++) {
            int cost = path(x, y, xa, ya) + path(x, y, xb, yb) + path(x, y, xc, yc) + 4;
            // if (x == xa and y == ya) cost--;
            // if (x == xb and y == yb) cost--;
            // if (x == xc and y == yc) cost--;
            if (K > cost) {
                K = cost;
                best_x = x, best_y = y;
            }
        }
    }
    cout << K << "\n";
    // cout << best_x << " " << best_y << endl;
    // return 0;
    paint_path(best_x, best_y, xa, ya);
    paint_path(best_x, best_y, xb, yb);
    paint_path(best_x, best_y, xc, yc);
    cout << xa << " " << ya << "\n";
    cout << xb << " " << yb << "\n";
    cout << xc << " " << yc << "\n";
    if (!(best_x == xa and best_y == ya) and !(best_x == xb and best_y == yb) and !(best_x == xc and best_y == yc)) cout << best_x << " " << best_y << "\n";
}