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




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int& a : A) {
        cin >> a;
    }
    unordered_map<int, int> last_occ;
    unordered_map<int, int> num_occ;
    for(int n = 0; n < N; ++n) {
        last_occ[A[n]] = n;
        ++num_occ[A[n]];
    }
    int ans = N;
    for(int l = 0; l < N; ) {
        int r = last_occ[A[l]];
        int largest = num_occ[A[l]];
        for(int j = l + 1; j <= r; ++j) {
            largest = max(largest, num_occ[A[j]]);
            r = max(r, last_occ[A[j]]);
        }
        ans -= largest;
        l = r + 1;
    }
    
    cout << ans << "\n";
    
    return 0;
}