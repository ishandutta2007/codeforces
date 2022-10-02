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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    LL last_green = -1;
    LL last_red = -1;
    LL last_blue = -1;
    LL red_hole = 0;
    LL blue_hole = 0;
    LL res = 0;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        LL p;
        char t;
        cin >> p >> t;
        if (t == 'G') {
            if (last_red != -1) {
                res += p-last_red;
                red_hole = max(red_hole, p-last_red);
            }
            if (last_blue != -1) {
                res += p-last_blue;
                blue_hole = max(blue_hole, p-last_blue);
            }
            if (last_green != -1) {
                if (p-last_green < red_hole + blue_hole) {
                    res += p-last_green;
                    res -= red_hole;
                    res -= blue_hole;
                }
            }
            last_green = p;
            last_red = p;
            last_blue = p;
            red_hole = 0;
            blue_hole = 0;
        } else if (t == 'R') {
            if (last_red != -1) {
                res += p-last_red;
                red_hole = max(red_hole, p-last_red);
            }
            last_red = p;
        } else if (t == 'B') {
            if (last_blue != -1) {
                res += p-last_blue;
                blue_hole = max(blue_hole, p-last_blue);
            }
            last_blue = p;
        }
    }
    cout << res << "\n";
}