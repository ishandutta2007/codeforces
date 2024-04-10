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

const int MAXN = -1;

int AskQuestion(int i, int j) {
    // int N = 4;
    // int P[N] = {3, 1, 2, 0};
    // int B[N];
    // for (int x = 0; x < N; x++) B[P[x]] = x;
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int ans;
    cin >> ans;
    return ans;
    // return P[i]^B[j];
}

int main() {
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> p0xorb(N);
    for (int i = 0; i < N; i++) {
        p0xorb[i] = AskQuestion(0, i);
    }
    vector<int> pxorb0(N);
    for (int i = 0; i < N; i++) {
        pxorb0[i] = AskQuestion(i, 0);
    }
    int cnt = 0;
    vector<int> res(N, -1);
    vector<int> P(N);
    vector<int> B(N);
    for (int v = 0; v < N; v++) {
        P[0] = v;
        for (int i = 0; i < N; i++) B[i] = p0xorb[i]^v;
        for (int i = 0; i < N; i++) P[i] = pxorb0[i]^B[0];
        bool funge = true;
        for (int i = 0; i < N; i++) {
            if (P[B[i]] != i) {
                funge = false;
                break;
            }
        }
        if (funge) {
            // dbg_var(P);
            // dbg_var(B);
            cnt++;
            if (res[0] == -1) {
                for (int i = 0; i < N; i++) res[i] = P[i];
            }
        }
    }
    cout << "!\n";
    cout << cnt << "\n";
    for (int i = 0; i < N; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    cout.flush();
}