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

const int MAXN = 200100;
LL A[4*MAXN], B[4*MAXN];
int before[4*MAXN], after[4*MAXN];
int N;
LL L;

bool works(LL w) {
    after[4*N] = 4*N-1;
    for (int i = 4*N-1; i >= 0; i--) {
        after[i] = after[i+1];
        while (after[i] >= 0 and B[after[i]] > A[i]+w) after[i]--;
    }
    before[0] = 0;
    for (int i = 0; i < 4*N; i++) {
        if (i > 0) before[i] = before[i-1];
        while (before[i] < 4*N and B[before[i]] < A[i]-w) before[i]++;
    }
    int mm = 1e9;
    for (int i = 3*N-1; i >= N; i--) {
        mm = min(mm, after[i]-i);
        if (mm < before[i]-i) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    
    cin >> N >> L;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];
    sort(A, A+N);
    sort(B, B+N);
    for (int i = 0; i < N; i++) {
        A[N+i] = L + A[i], A[2*N+i] = 2*L+A[i], A[3*N+i] = 3*L+A[i];
        B[N+i] = L + B[i], B[2*N+i] = 2*L+B[i], B[3*N+i] = 3*L+B[i];
    }
    LL l = 0;
    LL r = L;
    while (l < r) {
        LL m = (l+r)/2;
        if (works(m)) r = m;
        else l = m+1;
    }
    cout << l << "\n";
}