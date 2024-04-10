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

const int MAXN = 5010;
const int MAXM = 2600;
int din1[MAXN][MAXM], din2[MAXN][MAXM];
int a[MAXN];

int diff(int x, int y) {
    return max(0, a[x]-a[y]+1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int N;
    cin >> N;
    int M = (N+1)/2;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int k = 2; k <= M; k++) din1[N-1][k] = 1e9;
    for (int k = 1; k <= M; k++) din2[N-1][k] = 1e9;
    for (int i = N-2; i >= 0; i--) {
        for (int k = 1; k <= M; k++) {
            din2[i][k] = min(din2[i+1][k], din1[i+1][k] + diff(i, i+1));
            if (i != N-2) {
                din1[i][k] = min(din2[i+2][k-1] + diff(i+1, i),
                    din1[i+2][k-1] + max(diff(i+1, i), diff(i+1, i+2)));
            } else if (k > 1) din1[i][k] = 1e9;
            else {
                din1[i][k] = diff(i+1, i);
            }
        }
    }
    for (int k = 1; k <= M; k++) cout << min(din1[0][k], din2[0][k]) << " ";
}