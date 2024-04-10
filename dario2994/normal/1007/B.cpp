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

const int MAXN = 100100;

int dd[MAXN];

int ii[500], jj[500], kk[500];
int cc = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    for (int d = 1; d < MAXN; d++) {
        for (int j = d; j < MAXN; j+=d) dd[j]++;
    }

    int cc = 0;
    vector<int> bb = {1, 2, 4, 3, 6, 5, 7};
    vector<int> arr = {1, 2, 4};
    for (int i = 0; i < 7; i++) for (int j = i; j < 7; j++) for (int k = j; k < 7; k++) {
        bool works = false;
        do {
            works |= (bb[i] & arr[0]) && (bb[j] & arr[1]) && (bb[k] & arr[2]);
        } while (next_permutation(arr.begin(), arr.end())) ;

        if (works) {
            ii[cc] = i, jj[cc] = j; kk[cc] = k;
            cc++;
        }
    }

    int K;
    cin >> K;
    for (int it = 0; it < K; it++) {
        int A, B, C;
        cin >> A >> B >> C;
        int ab = __gcd(A, B), bc = __gcd(B, C), ca = __gcd(C, A);
        int abc = __gcd(A, bc);
        vector<int> val = {dd[A]-dd[ab]-dd[ca]+dd[abc], dd[B]-dd[ab]-dd[bc]+dd[abc], dd[C]-dd[ca]-dd[bc]+dd[abc], dd[ab]-dd[abc], dd[bc]-dd[abc], dd[ca]-dd[abc], dd[abc]};
        int res = 0;
        for (int it = 0; it < cc; it++) {
            int i = ii[it], j = jj[it], k = kk[it];
            if (i == k) res += val[i]*(val[i]-1)*(val[i]-2) / 6 + val[i]*val[i];
            else if (i == j) res += val[i]*(val[i]+1) * val[k] / 2 ;
            else if (j == k) res += val[j]*(val[j]+1)*val[i] / 2;
            else res += val[i]*val[j]*val[k];
        }
        cout << res << "\n";
    }
}