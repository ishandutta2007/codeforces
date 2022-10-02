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

const int MAXD = 510;
const int MAXS = 5010;

int dist[MAXD][MAXS];
vector<int> aa[MAXD][MAXS];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int D, S;
    cin >> D >> S;
    for (int d = 0; d < D; d++) {
        for (int s = 0; s <= S; s++) {
            for (int c = 0; c <= 9; c++) {
                if (s+c > S) continue;
                aa[(10*d+c)%D][s+c].push_back(d + 600*s);
            }

            dist[d][s] = -1;
        }
    }
    queue<pair<int,int>> q;
    q.push({0, S});
    dist[0][S] = 0;
    while (!q.empty()) {
        auto pp = q.front();
        q.pop();
        for (int x : aa[pp.first][pp.second]) {
            int d = x % 600;
            int s = x / 600;
            if (dist[d][s] == -1) {
                dist[d][s] = 1 + dist[pp.first][pp.second];
                q.push({d, s});
            }
        }
    }
    if (dist[0][0] == -1) {
        cout << -1 << "\n";
        return 0;
    }
    int d = 0;
    int s = 0;
    while (d != 0 or s != S) {
        for (int c = 0; c <= 10; c++) {
            if (c + s > S) continue;
            if (dist[d][s] == 1 + dist[(10*d+c)%D][s+c]) {
                cout << c;
                d = (10*d+c)%D;
                s = s+c;
                break;
            }
        }
    }
    // cout << "\n";
}