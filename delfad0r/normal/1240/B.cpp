#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> II;


template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const T& x : v) {
        out << x << ", ";
    }
    return out << "]";
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}


void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for(auto& a : A) {
        cin >> a;
    }
    vector<int> fst(N + 1, -1), lst(N + 1, -1);
    set<int> V;
    for(int n = 0; n < N; ++n) {
        if(fst[A[n]] < 0) {
            fst[A[n]] = n;
        }
        lst[A[n]] = n;
        V.insert(A[n]);
    }
    vector<int> ans(N + 1, 0);
    int y = -1;
    for(int x : V) {
        if(y < 0) {
            y = x;
            ans[x] = 1;
        } else {
            if(fst[x] > lst[y]) {
                ans[x] = 1 + ans[y];
            } else {
                ans[x] = 1;
            }
            y = x;
        }
    }
    cout << (V.size() - *max_element(ans.begin(), ans.end())) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int Q;
    cin >> Q;
    while(Q--) {
        solve();
    }
    
    return 0;
}