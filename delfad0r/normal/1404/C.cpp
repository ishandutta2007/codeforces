#include "bits/stdc++.h"

#define all_of(x) std::begin(x), std::end(x)
#ifdef _GLIBCXX_DEBUG
    #define debug(x) cerr << #x << ": " << x << endl
#else
    #define debug(x) 
#endif

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for(auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

struct fenwick_t {
    int N;
    vector<int> ft;
    fenwick_t(int N_) : N(N_ + 1), ft(N_ + 2, 0) { }
    int query(int w) {
        ++w;
        int ans = 0;
        for(; w; w -= w & (-w)) {
            ans += ft[w];
        }
        return ans;
    }
    void update(int w, int v) {
        ++w;
        for(; w <= N; w += w & (-w)) {
            ft[w] += v;
        }
    }
};

struct query_t {
    int id, l, r;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int n = 0; n < N; ++n) {
        int a;
        cin >> a;
        A[n] = n + 1 - a;
    }
    vector<query_t> E;
    for(int q = 0; q < Q; ++q) {
        int l, r;
        cin >> l >> r;
        E.push_back(query_t{q, l, r});
    }
    fenwick_t ft(N);
    vector<vector<int>> V(N);
    for(int n = 0; n < N; ++n) {
        if(A[n] == 0) {
            V[n].push_back(n);
            ft.update(n, 1);
        } else if(A[n] > 0) {
            if(ft.query(n) < A[n]) {
                continue;
            }
            int lo = 0, hi = n;
            while(hi - lo > 1) {
                int m = (lo + hi) / 2;
                if(ft.query(n) - ft.query(m - 1) >= A[n]) {
                    lo = m;
                } else {
                    hi = m;
                }
            }
            assert(A[lo] == 0);
            ft.update(lo, 1);
            V[lo].push_back(n);
        }
    }
    debug(V);
    sort(all_of(E), [&](auto& x, auto& y) { return x.l > y.l; });
    vector<int> ans(Q);
    ft = fenwick_t(N);
    int last_zero_added = N;
    for(auto e : E) {
        while(last_zero_added > e.l) {
            --last_zero_added;
            for(auto x : V[last_zero_added]) {
                ft.update(x, 1);
            }
        }
        ans[e.id] = ft.query(N - 1 - e.r);
    }
    
    for(auto x : ans) {
        cout << x << "\n";
    }
    
    return 0;
}