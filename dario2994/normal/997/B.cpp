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

const int MAXN = 1010;

bool poss[MAXN][50*MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    poss[0][0] = 1;
    for (int i = 1; i < MAXN; i++) {
        for (int j = i-1; j <= 50*(i-1); j++) {
            if (poss[i-1][j]) {
                poss[i][j+1] = 1;
                poss[i][j+5] = 1;
                poss[i][j+10] = 1;
                poss[i][j+50] = 1;
            }
        }
    }
    const LL K = 1000;
    LL N;
    cin >> N;
    if (N <= K) {
        LL res = 0;
        for (int i = N; i <= 50*N; i++) res += poss[N][i];
        cout << res << "\n";
    } else {
        LL rix1 = 0;
        LL rix2 = 1ll + 49ll*N -44ll*K;
        LL rix3 = 0;
        for (int i = K; i <= 5*K-1; i++) rix1 += poss[K][i];
        for (int i = 10*K+1; i <= 50*K; i++) rix3 += poss[K][i];
        // cout << rix1 << " " << rix2 << " " << rix3 << "\n";
        cout << rix1 + rix2 + rix3 << "\n";
        // if (N < MAXN) {
        //     LL ris1 = 0, ris2 = 0, ris3 = 0;
        //     for (int i = N; i < N+4*K; i++) ris1 += poss[N][i];
        //     for (int i = N+4*K; i <= 50*N-40*K; i++) ris2 += poss[N][i];
        //     for (int i = 50*N-40*K+1; i <= 50*N; i++) ris3 += poss[N][i];
        //     cout << ris1 << " " << ris2 << " " << ris3 << " " << ris1+ris2+ris3 << endl;
        // }
    }
    // int c = 10;
    // int res = 0;
    // for (int i = c; i <= 50*c; i++) {
    //     cout << poss[c][i];
    //     res += poss[c][i];
    // }
    // cout << endl << res << endl;
}