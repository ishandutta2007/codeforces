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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int N;
    cin >> N;
    vector<LL> b(N);
    for (int i = 0; i < N; i++) cin >> b[i];
    bool all_eq = true;
    for (int i = 0; i < N; i++) {
        all_eq &= (b[i] == b[0]);
    }
    if (all_eq and b[0] != 0) {
        cout << "NO\n";
        return 0;
    }
    if (all_eq and b[0] == 0) {
        cout << "YES\n";
        for (int i = 0; i < N; i++) cout << 1 << " ";
        cout << "\n";
        return 0;
    }
    vector<LL> a(N, -1);
    for (int i = 0; i < N; i++) {
        if (b[i] > b[(i+N-1)%N]) a[i] = b[i];
    }
    for (int i = 2*N; i >= 0; i--) {
        int x = i%N;
        int y = (i+1)%N;
        if (a[x] == -1 and a[y] != -1) {
            assert(a[y] > b[x]);
            a[x] = a[y] + b[x];
            if (a[x] < 1e6) a[x] = 1000000ll*a[y]+b[x];
        }
    }
    // dbg_var(a);
    for (int i = 0; i < N; i++) assert(a[i]%a[(i+1)%N] == b[i]);
    cout << "YES\n";
    for (int i = 0; i < N; i++) cout << a[i] << " ";
    cout << "\n";
}