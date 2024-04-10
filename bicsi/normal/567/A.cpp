#include <bits/stdc++.h>

using namespace std;
typedef int64_t var;
typedef pair<var, var> Pair;

var X[500000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    var n;
    cin>>n;
    for(var i=1; i<=n; i++) {
        cin>>X[i];
    }
    X[0] = -5e9;
    X[n+1] = 5e9;

    for(var i=1; i<=n; i++) {
        cout<<min(X[i] - X[i-1], X[i+1] - X[i])<<" "<<max(X[i] - X[1], X[n] - X[i])<<'\n';
    }

    return 0;
}