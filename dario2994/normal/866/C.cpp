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

const int MAXN = 51;
const int MAXT = 5010;
double et[MAXN][MAXT];
int N;
int R;
double P[MAXN];
int F[MAXN];
int S[MAXN];

double ComputeRealT(double T) {
    for (int t = 0; t < MAXT; t++) et[N][t] = (t <= R) ? t : t+T;
    for (int k = N-1; k > 0; k--) {
        for (int t = 0; t < MAXT; t++) {
            double a = F[k] + T;
            if (t + F[k] < MAXT) a = et[k+1][t+F[k]];
            double b = S[k] + T;
            if (t + S[k] < MAXT) b = et[k+1][t+S[k]];
            et[k][t] = min(t+T, P[k] * a + (1.0-P[k]) * b);
        }
    }
    return P[0] * et[1][F[0]] + (1.0-P[0]) * et[1][S[0]];
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    cin >> N >> R;
    for (int i = 0; i < N; i++) {
        cin >> F[i] >> S[i] >> P[i];
        P[i] /= 100.0;
    }
    // cout << ComputeRealT(31.4) << endl;
    // return 0;
    double l = 1.0;
    double r = 1e18;
    for (int it = 0; it < 100; it++) {
        double m = (l+r)/2.0;
        double real_m = ComputeRealT(m);
        if (real_m >= m) l = m;
        else r = m;
    }
    cout.precision(20);
    cout << fixed << l << "\n";
}