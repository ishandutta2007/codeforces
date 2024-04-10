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

struct Rect {
    int x1, x2, y1, y2;
    Rect() {}
    Rect(int x1, int x2, int y1, int y2) : x1(x1), x2(x2), y1(y1), y2(y2) {}
    bool is_inside(int x, int y) {
        return x1 <= x and x <= x2 and y1 <= y and y <= y2;
    }
};

int cntinside(int x, int y, const vector<Rect>& rect) {
    int cnt = 0;
    for (auto r : rect) cnt += r.is_inside(x, y);
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    vector<Rect> rect(N);
    vector<pair<int,int>> xx, yy;
    for (int i = 0; i < N; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        rect[i] = Rect(x1, x2, y1, y2);
        xx.push_back({x1, -1});
        xx.push_back({x2, 1});
        yy.push_back({y1, -1});
        yy.push_back({y2, 1});
    }
    sort(xx.begin(), xx.end());
    sort(yy.begin(), yy.end());
    int curr = 0;
    set<int> possX, possY;
    for (auto pp : xx) {
        curr += -pp.second;
        if (curr >= N-1) possX.insert(pp.first);
    }
    curr = 0;
    for (auto pp : yy) {
        curr += -pp.second;
        if (curr >= N-1) possY.insert(pp.first);
    }
    for (int x : possX) for (int y : possY) {
        if (cntinside(x, y, rect) >= N-1) {
            cout << x << " " << y << "\n";
            return 0;
        }
    }
}