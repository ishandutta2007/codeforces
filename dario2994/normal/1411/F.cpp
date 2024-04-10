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

// n % 3 = 1 -> (2, 2) or 4
// n % 3 = 2 -> 2
//
// Step 1: Reduce to 1, 2, 3, 4 by subtracting 3 (cost = 1).
// Step 2:
//  Case n % 3 = 2:
//    - Remove a 2 (cost = 0).
//    - 4 -> 2 (cost = 1)
//    - Remove two 1s (cost = 2).
//  Case n % 3 = 1:
//    - Remove a 4 (cost = 0).
//    - Remove two 2s (cost = 1).
//    - Remove 1 and 3 (cost = 1).
//    - Remove two 1s and a 2 (cost = 2).
//    - Remove four 1s (cost = 3).
// Step 3: Reduce 3 (cost = 0).
// Step 4: Reduce 4 - > 1 (cost = 1).
// Step 5: Match 1s and 2s (cost = 1).
// Step 6: Remove three 1s (cost = 2).
// Step 7: Remove three 2s (cost = 3).


void solve() {
    int n;
    cin >> n;
    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<int> a;
    vector<bool> visited(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        int j = i;
        int cnt = 0;
        while (!visited[j]) {
            visited[j] = true;
            j = p[j];
            cnt++;
        }
        a.push_back(cnt);
    }

    int cost1 = 0;

    // Step 1: Reduce to 1, 2, 3, 4 by subtracting 3 (cost = 1).
    vector<int> vec(5);
    for (int x: a) {
        if (x % 3 == 0) vec[3]++, cost1 += x/3 - 1;
        if (x % 3 == 1) {
            if (x == 1) vec[1]++;
            else vec[4]++, cost1 += x/3 - 1;
        }
        if (x % 3 == 2) vec[2]++, cost1 += x/3;
    }
    // Step 3: Reduce 3 (cost = 0).
    // Step 4: Reduce 4 - > 1 (cost = 1).
    // Step 5: Match 1s and 2s (cost = 1).
    // Step 6: Remove three 1s (cost = 2).
    // Step 7: Remove three 2s (cost = 3).
    int cost2 = 1e8;
    auto final_steps = [&](int c) {
        for (int i = 0; i <= 4; i++) if (vec[i] < 0) c = 1e8;
        vec[3] = 0;
        c += vec[4];
        vec[1] += vec[4];
        vec[4] = 0;
        int m = min(vec[1], vec[2]);
        c += m;
        vec[1] -= m, vec[2] -= m;
        c += 2*vec[1]/3 + vec[2];
        cost2 = min(cost2, c);
    };

    // Step 2:
    vector<int> vec2 = vec;
    //  Case n % 3 = 0:
    if (n % 3 == 0) final_steps(0);
    //  Case n % 3 = 2:
    //    - Remove a 2 (cost = 0).
    //    - 4 -> 2 (cost = 1)
    //    - Remove two 1s (cost = 1).
    if (n % 3 == 2) {
        vec[2]--;
        final_steps(0);
        vec = vec2;
        
        vec[4]--, vec[2]++;
        final_steps(1);
        vec = vec2;

        vec[1]--;
        final_steps(1);
        vec = vec2;
    }

    //  Case n % 3 = 1:
    //    - Remove a 4 (cost = 0).
    //    - Remove two 2s (cost = 0).
    //    - Remove 1 and 3 (cost = 1).
    //    - Remove two 1s and a 2 (cost = 1).
    //    - Remove four 1s (cost = 2).
    if (n % 3 == 1) {
        // dbg(cost1, vec);
        vec[4]--;
        final_steps(0);
        vec = vec2;
        
        vec[2] -= 2;
        final_steps(0);
        vec = vec2;

        vec[1]--, vec[3]--;
        final_steps(1);
        vec = vec2;

        vec[1] -= 2, vec[2]--;
        final_steps(1);
        vec = vec2;

        vec[1] -= 4;
        final_steps(2);
        vec = vec2;
    }
    int cost = cost1 + cost2;
    
    const LL mod = 1e9 + 7;
    LL res = 1;
    while (n > 4) n -= 3, res = 3*res % mod;
    res = n * res % mod;
    cout << res << " " << cost << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) solve();
}