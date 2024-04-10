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

void solve() {
    int K;
    cin >> K;
    string S, A, B;
    cin >> S >> A >> B;
    int N = S.size();
    vector<int> p(K, -1);
    vector<int> occ(K, false);
    vector<int> choices;

    int pos = -1;
    for (int i = 0; i < N; i++) {
        // dbg_var(i);
        int c = S[i]-'a';
        if (p[c] == -1 and occ[A[i]-'a'] == false) {
            p[c] = A[i]-'a';
            occ[A[i]-'a'] = true;
            choices.push_back(i);
            pos = i;
        }
        if (p[c] > A[i]-'a') break;
        else if (p[c] < A[i]-'a') {
            if (p[c] == -1) choices.push_back(i);
            bool working = false;
            while (!choices.empty() && !working) {
                int it = choices.back();
                choices.pop_back();
                if (p[S[it]-'a'] != -1) {
                    occ[A[it]-'a'] = false;
                    p[S[it]-'a'] = -1;
                }
                for (int j = A[it]-'a' + 1; j < K; j++) {
                    if (!occ[j]) {
                        p[S[it]-'a'] = j;
                        occ[j] = true;
                        working = true;
                        pos = it;
                        break;
                    }
                }
                pos = it;
            }
            if (!working) {
                cout << "NO\n";
                return;
            }
            break;
        }
    }
    // dbg_var(pos);
    // cout << pos << endl;

    for (int i = pos+1; i < N; i++) {
        if (p[S[i]-'a'] == -1) {
            for (int j = 0; j < K; j++) {
                if (!occ[j]) {
                    p[S[i]-'a'] = j;
                    occ[j] = true;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (p[S[i]-'a'] > B[i]-'a') {
            cout << "NO\n";
            return;
        }
        if (p[S[i]-'a'] < B[i]-'a') break;
    }
    int it = 0;
    for (int i = 0; i < K; i++) {
        if (p[i] == -1) {
            while (occ[it]) it++;
            occ[it] = true;
            p[i] = it;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < K; i++) {
        cout << char('a' + p[i]);
    }
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    int testcases;
    cin >> testcases;
    for (int t = 0; t < testcases; t++) solve();
}