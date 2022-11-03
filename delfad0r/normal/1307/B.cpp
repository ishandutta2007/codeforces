#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> A(N);
    for(int& a : A) {
        cin >> a;
    }
    for(int a : A) {
        if(a == X) {
            cout << 1 << "\n";
            return;
        }
    }
    int m = *max_element(A.begin(), A.end());
    cout << max(2, (X - 1) / m + 1) << "\n";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    
    return 0;
}