#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

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

vector<LL> slow_simul(vector<LL> vec) {
    bool done = true;
    int N = vec.size();
    while (done) {
        done = false;
        vector<bool> sliding(N-1);
        for (int i = 0; i < N-1; i++) sliding[i] = vec[i] + 2 <= vec[i+1];
        for (int i = 0; i < N-1; i++) {
            if (sliding[i]) done = true, vec[i]++, vec[i+1]--;
        }
    }
    return vec;
}

vector<LL> fast_simul(const vector<LL>& vec) {
    int N = vec.size();
    // vector<LL> A(N, 0);
    // A[0] = vec[0];
    vector<int> flat_after;
    flat_after.push_back(0);
    LL last_val = vec[0];
    for (LL n = 1; n < N; n++) {
        // dbg(n, last_val, flat_after);
        LL x = vec[n];
        while (flat_after.size() >= 2) {
            int pos = flat_after.back();
            if (last_val+1 <= x-(n-pos)) {
                last_val++;
                flat_after.pop_back();
                x -= n-pos;
            } else {
                break;
            }
        }
        // dbg("MIDDLE", last_val, flat_after, x);
        if (flat_after.size() == 1) {
            LL k = (x-last_val) / (n+1);
            x -= n*k;
            last_val += k;
        }
        // dbg("AFTER", last_val, flat_after, x);
        if (x > last_val) {
            int pos = flat_after.back();
            if (pos != 0) flat_after.pop_back();
            if (pos != 0 or x != last_val+1) flat_after.push_back(pos + (x-last_val-1));
            last_val++;
        } else flat_after.push_back(n);
    }
    // dbg(flat_after);
    vector<bool> jumping(N, true);
    vector<LL> res(N, 0);
    for (int x: flat_after) jumping[x] = false;
    res[N-1] = last_val;
    for (int i = N-2; i >= 0; i--) {
        res[i] = res[i+1];
        if (jumping[i+1]) res[i]--;
    }
    // assert(res == slow_simul(vec));
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    // srand(time(NULL));
    // int N = 5;
    // vector<LL> vec(N);
    // vec[0] = rand() % 50;
    // for (int i = 1; i < N; i++) vec[i] = vec[i-1] + (rand() % 1);
    // for (LL x: vec) cout << x << " ";
    // cout << endl;
    
    int N;
    cin >> N;
    vector<LL> vec(N);
    for (int i = 0; i < N; i++) cin >> vec[i];
    vector<LL> res = fast_simul(vec);
    
    for (LL x: res) cout << x << " ";
    cout << "\n";
}