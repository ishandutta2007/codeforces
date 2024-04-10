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

const int MAXN = 7;
int N;
double inp[1<<MAXN][1<<MAXN];

double P[1<<(MAXN+1)][1<<MAXN];
double B[1<<(MAXN+1)][1<<MAXN];
int l[1<<(MAXN+1)];
int r[1<<(MAXN+1)];
double val[1<<(MAXN+1)];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    cin >> N;
    for (int i = 0; i < (1<<N); i++) {
        for (int j = 0; j < (1<<N); j++) {
            cin >> inp[i][j];
            inp[i][j] /= 100.0;
        }
    }
    for (int v = 0; v < (1<<N); v++) {
        l[(1<<N) + v] = v;
        r[(1<<N) + v] = v;
        P[(1<<N) + v][v] = 1.0;
        B[(1<<N) + v][v] = 0.0;
        val[(1<<N) + v] = 0.5;
    }
    for (int v = (1<<N)-1; v >= 1; v--) {
        l[v] = l[2*v];
        r[v] = r[2*v+1];
        val[v] = val[2*v]*2.0;
    }

    for (int v = (1<<N)-1; v >= 1; v--) {
        for (int x = l[2*v]; x <= r[2*v]; x++) {
            for (int y = l[2*v+1]; y <= r[2*v+1]; y++) {
                P[v][x] += P[2*v][x]*P[2*v+1][y]*inp[x][y];
                P[v][y] += P[2*v][x]*P[2*v+1][y]*inp[y][x];
            }
        }
        for (int x = l[2*v]; x <= r[2*v]; x++) {
            for (int y = l[2*v+1]; y <= r[2*v+1]; y++) {
                B[v][x] = max(B[v][x], B[2*v][x] + B[2*v+1][y] + val[v] * P[v][x]);
                B[v][y] = max(B[v][y], B[2*v][x] + B[2*v+1][y] + val[v] * P[v][y]);
            }
        }
    }
    
    double res = 0.0;
    for (int i = 0; i < (1<<N); i++) res = max(res, B[1][i]);

    cout.precision(15);
    cout << fixed << res << "\n";
}