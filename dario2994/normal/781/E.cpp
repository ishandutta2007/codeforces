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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) cout << #x  << ": " << x << endl;
    #define dbg_vec(x) cout << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) cout << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif  

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 100100;
const LL mod = 1e9 + 7;

int H, W, N;
int U[MAXN], L[MAXN], R[MAXN], S[MAXN];
vector<int> aa[MAXN];
LL din[MAXN];

constexpr int pot2 = 1<<17;
priority_queue<pair<int, int>> tt[pot2 * 2];

int query(int pos, int h) {
    int it = pot2 + pos;
    int chosen = MAXN-1;
    while (it != 0) {
        while (!tt[it].empty() and S[tt[it].top().second] < h) tt[it].pop();
        if (!tt[it].empty()) {
            if (chosen == MAXN-1 or U[chosen] < U[tt[it].top().second]) {
                chosen = tt[it].top().second;
            }
        }
        it >>= 1;
    }
    return chosen;
}

void add_interval(int l, int r, int a, int b, int v, int it) {
    if (r < a or b < l) return;
    if (l <= a and b <= r) {
        // cout << "add_interval(" << l << ", " << r << ", " << a << ", " << b << ", " << v << ")" << endl;
        tt[v].push({U[it], it});
        return;
    }
    int m = (a + b) / 2;
    add_interval(l, r, a, m, 2*v, it);
    add_interval(l, r, m+1, b, 2*v + 1, it);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> H >> W >> N;

    for (int i = 0; i < N; i++) {
        cin >> U[i] >> L[i] >> R[i] >> S[i];
        S[i] += U[i];
    }

    vector<int> ord(N);
    for (int i = 0; i < N; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), [](int a, int b) { return U[a] < U[b]; });

    for (int it : ord) {
        bool double_ball = (L[it] == 1) or (R[it] == W);
        if (L[it] != 1) {
            int next_el = query(L[it] - 1, U[it]);
            aa[it].push_back(next_el);
            if (double_ball) aa[it].push_back(next_el);
        }
        if (R[it] != W) {
            int next_el = query(R[it] + 1, U[it]);
            aa[it].push_back(next_el);
            if (double_ball) aa[it].push_back(next_el);
        }
        add_interval(L[it], R[it], 0, pot2 - 1, 1, it);
    }
    din[MAXN-1] = 1;
    for (int it : ord) {
        if (aa[it].empty()) din[it] = 2;
        else {
            din[it] = (din[aa[it][0]] + din[aa[it][1]]) % mod;
        }
    }
    LL res = 0;
    for (int pos = 1; pos <= W; pos++) {
        int next_el = query(pos, H+1);
        if (next_el == -1) res++;
        else res = (res + din[next_el]) % mod;
    }
    cout << res;
}