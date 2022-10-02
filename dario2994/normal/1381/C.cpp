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

typedef pair<int,int> pii;

void solve() {
    int N, x, y;
    cin >> N >> x >> y;
    vector<int> cnt(N+2);
    vector<int> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        cnt[B[i]]++;
    }
    int missing = 0;
    for (int i = 1; i <= N+1; i++) {
        if (cnt[i] == 0) {
            missing = i;
            break;
        }
    }

    priority_queue<pii> q;
    for (int i = 1; i <= N+1; i++) if (cnt[i] > 0) q.push({cnt[i], i});
    
    vector<vector<int>> ans(N+2);

    for (int i = 1; i <= x; i++) {
        int z = q.top().second;
        q.pop();
        ans[z].push_back(z);
        cnt[z]--;
        // cout << "CORRECT " << z << endl;
        if (cnt[z] > 0) q.push({cnt[z], z});
    }

    vector<int> cnt2 = cnt;
    
    for (int i = N; i > y; i--) {
        int z = q.top().second;
        q.pop();
        ans[z].push_back(missing);
        cnt[z]--;
        // cout << "MISSING: " << z << " " << missing << endl;
        if (cnt[z] > 0) q.push({cnt[z], z});
    }

    int len = y-x;
    for (int i = 1; i <= N+1; i++) cnt2[i] = min(cnt2[i], len-cnt[i]);
    int real_len = 0;
    for (int i = 1; i <= N+1; i++) {
        if (real_len + cnt2[i] > len) {
            cnt2[i] = len - real_len;
        }
        real_len += cnt2[i];
        // cout << "cnt2 " << i << " " << cnt2[i] << endl;
    }
    if (len > real_len) {
        cout << "NO\n";
        return;
    }

    priority_queue<pii> q1;
    priority_queue<pii> q2;
    for (int i = 1; i <= N+1; i++) {
        if (cnt[i] > 0) q1.push({cnt[i], i});
        if (cnt2[i] > 0) q2.push({cnt2[i], i});
    }


    for (int i = len; i >= 1; i--) {
        int u = q1.top().second;
        q1.pop();
        int v = q2.top().second;
        q2.pop();
        if (u == v) {
            int u2 = q1.top().second;
            q1.pop();
            q1.push({cnt[u], u});
            u = u2;
        }
        // dbg(q1.size(), q2.size());
        if (q1.size() == 1 and q2.size() == 1) {
            // cout << "CRITICAL" << endl;
            int w1 = q1.top().second, w2 = q2.top().second;
            if (w1 == w2 and cnt[w1] + cnt2[w2] == i) {
                q1.pop();
                q1.push({cnt[u], u});
                u = w1;
            }
        }
        // cout << u << " " << v << endl;
        // cout << u << " " << v << endl;
        ans[u].push_back(v);
        cnt[u]--;
        cnt2[v]--;
        if (cnt[u] > 0) q1.push({cnt[u], u});
        if (cnt2[v] > 0) q2.push({cnt2[v], v});
    }

    cout << "YES\n";
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        int z = B[i];
        cout << ans[z].back() << " ";
        A[i] = ans[z].back();
        ans[z].pop_back();
    }
    cout << "\n";

    // vector<int> final_cnt(N+2, 0);
    // for (int i = 0; i < N; i++) final_cnt[A[i]]++;
    // for (int i = 0; i < N; i++) {
        // if (final_cnt[B[i]]) {
            // y--;
            // final_cnt[B[i]]--;
        // }
    // }   
    // for (int i = 0; i < N; i++) x -= A[i] == B[i];
    // assert(x == 0 and y == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        // cout << t << endl;
        solve();
    }
}