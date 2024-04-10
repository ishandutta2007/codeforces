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

    string S;
    cin >> S;
    int N = S.size();
    vector<string> din(N), dinrev(N);
    vector<int> how(N, 0), howrev(N, 0);
    din[0] = S[0], dinrev[0] = S[0];
    for (int k = 1; k < N; k++) {
        string s1 = din[k-1] + S[k], s2 = S[k] + dinrev[k-1];
        if (s1 < s2) {
            how[k] = 0, din[k] = s1;
        } else {
            how[k] = 1, din[k] = s2;
        }
        s1 = S[k] + dinrev[k-1], s2 = din[k-1] + S[k];
        if (s1 < s2) {
            howrev[k] = 0, dinrev[k] = s1;
        } else {
            howrev[k] = 1, dinrev[k] = s2;
        }
    }
    int it = N-1;
    bool rev = false;
    vector<int> ans;
    while (it >= 0) {
        if (!rev) {
            ans.push_back(how[it]);
            rev ^= how[it];
        } else {
            ans.push_back(howrev[it]);
            rev ^= howrev[it];
        }
        it--;
    }
    reverse(ans.begin(), ans.end());
    for (int x : ans) cout << x << " ";
}