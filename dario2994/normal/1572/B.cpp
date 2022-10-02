#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

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

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

vector<int> first_is_0(vector<int> A) {
    int n = A.size();
    assert(n >= 3);
    assert(A[0] == 0);
    int sum = 0;
    for (int x: A) sum += x;
    assert(sum % 2 == 0);
    vector<int> res;
    for (int i = 0; i < n-1; i++) {
        // dbg(i, A);
        if (A[i+1] == 0) continue;
        if (A[i+2] == 1) {
            res.push_back(i);
            A[i+1] = 0, A[i+2] = 0;
        } else { //010
            res.push_back(i+1);
            if (A[i+3] == 1) {
                A[i+1] = 0, A[i+3] = 0;
            } else {
                A[i+2] = 1, A[i+3] = 1;
                res.push_back(i);
                A[i+1] = 0, A[i+2] = 0;
            }
        }
    }
    return res;
}

vector<int> last_is_0(vector<int> A) {
    int n = A.size();
    reverse(A.begin(), A.end());
    vector<int> res = first_is_0(A);
    for (int& x: res) x = n - 3 - x;
    return res;
}

vector<int> first_is_0(vector<int> A, int from, int to) {
    vector<int> B(A.begin()+from, A.begin()+to+1);
    vector<int> res = first_is_0(B);
    for (int& x: res) x += from;
    return res;
}

vector<int> last_is_0(vector<int> A, int from, int to) {
    vector<int> B(A.begin()+from, A.begin()+to+1);
    vector<int> res = last_is_0(B);
    for (int& x: res) x += from;
    return res;
}



void append(vector<int>& a, vector<int> b) {
    for (int x: b) a.push_back(x);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    // Count ones.
    int sum = 0;
    for (int i = 0; i < n; i++) sum += A[i];
    if (sum % 2 == 1 or sum == n) {
        cout << "NO\n";
        return;
    }

    // First and last block
    int a = -1;
    while (A[a+1] == 1) a++;
    int b = n;
    while (A[b-1] == 1) b--;
    
    vector<int> res;
    if (A[0] == 0) res = first_is_0(A);
    else if (A[n-1] == 0) res = last_is_0(A);
    else if (a % 2 == 1) {
        for (int i = a-1; i >= 0; i -= 2) {
            res.push_back(i);
            A[i] = 0, A[i+1] = 0;
        }
        append(res, first_is_0(A));
    } else if ((n-b) % 2 == 0) {
        for (int i = b-1; i <= n-3; i += 2) {
            res.push_back(i);
            A[i+1] = 0, A[i+2] = 0;
        }
        append(res, last_is_0(A));
    } else {
        int cnt = 0;
        for (int pos = 0; pos < n; pos++) {
            cnt++;
            if (pos == n-1 or A[pos] != A[pos+1]) {
                if (cnt % 2 == 0 or cnt == pos+1 or pos == n-1) {
                    cnt = 0;
                    continue;
                }
                if (A[pos] == 1) {
                    append(res, last_is_0(A, 0, pos+1));
                    append(res, first_is_0(A, pos+1, n-1));
                } else {
                    // dbg(pos, cnt);
                    int z = pos-cnt+1;
                    for (int i = pos-1; i >= z+1; i -= 2) {
                        res.push_back(i);
                        A[i] = 1, A[i+1] = 1;
                    }
                    res.push_back(z-1);
                    A[z-1] = 0, A[z+1] = 0;
                    // dbg(A);
                    append(res, last_is_0(A, 0, z+1));
                    append(res, first_is_0(A, z-1, n-1));
                }
                break;
            }
        }
        if (res.empty()) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    cout << res.size() << "\n";
    for (int x: res) cout << x+1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}