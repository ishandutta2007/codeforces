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
    
    int N;
    cin >> N;
    vector<int> A(N);
    unordered_map<int, int> M0;
    for(int& a : A) {
        cin >> a;
        ++M0[a];
    }
    for(auto& p : M0) {
        p.second--;
    }
    for(int a : A) {
        if(M0[a] == 0) {
            M0.erase(a);
        }
    }
    if(not M0.size()) {
        cout << "0\n";
        return 0;
    }
    int ans = N;
    for(int i = 0; i < N; ++i) {
        auto M = M0;
        for(int j = i; j < N; ++j) {
            if(M.find(A[j]) != M.end() and --M[A[j]] == 0) {
                M.erase(A[j]);
                if(M.empty()) {
                    ans = min(ans, j + 1 - i);
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    
    
    return 0;
}