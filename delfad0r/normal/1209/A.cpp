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
    vector<int> V(N);
    for(int n = 0; n < N; ++n) {
        cin >> V[n];
    }
    int ans = 0;
    while(V.size()) {
        int a = *min_element(V.begin(), V.end());
        vector<int> U;
        for(int v : V) {
            if(v % a) {
                U.push_back(v);
            }
        }
        ++ans;
        V = U;
    }
    cout << ans << "\n";
    
    return 0;
}