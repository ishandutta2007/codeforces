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
    N /= 4;
    for(int r = 0; r < N; ++r) {
        for(int i = 0; i < 4; ++i) {
            for(int c = 0; c < N; ++c) {
                for(int j = 0; j < 4; ++j) {
                    cout << (j + 4 * i + 16 * c + 16 * N * r) << " ";
                }
            }
            cout << "\n";
        }
    }
    
    
    return 0;
}