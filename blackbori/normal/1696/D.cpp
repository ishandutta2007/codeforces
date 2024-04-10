#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

ll A[303030], B[303030], C[303030];

void tc() {
    ll n, i, j, a, b, c;
    vector<ll> X, Y;
    cin >> n;
    fill(B, B + n + 1, n + 1);
    fill(C, C + n + 1, n + 1);
    for (i = 1; i <= n; i++) {
        cin >> A[i];
        for (; !X.empty() && A[X.back()] < A[i]; X.pop_back()) {
            B[X.back()] = i;
        }
        X.push_back(i);
        for (; !Y.empty() && A[Y.back()] > A[i]; Y.pop_back()) {
            C[Y.back()] = i;
        }
        Y.push_back(i);
    }
    a = 0;
    for (i = 1; i < n; a++) {
        b = B[i]; c = C[i];
        if (b < c) {
            for (j = i; j < c; j = B[j]) {
                i = j;
            }
        }
        else {
            for (j = i; j < b; j = C[j]) {
                i = j;
            }
        }
    }
    cout << a << "\n";
    return;
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    
    cin >> t;
    
    for (; t--; ) {
        tc();
    }
    
    return 0;
}