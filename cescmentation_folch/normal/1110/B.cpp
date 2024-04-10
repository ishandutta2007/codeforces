#include<bits/stdc++.h>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    priority_queue<int> Q;
    vector<int> V(n);

    for (int i = 0; i < n; ++i) cin >> V[i];
    for (int i = 1; i < n; ++i) {
        Q.push(V[i]-V[i-1]-1);
    }

    int res = V.back() - V[0] + 1;
    while (--k) {
        res -= Q.top();
        Q.pop();
    }

    cout << res << '\n';
}