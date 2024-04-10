#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int H[500000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, a;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>H[i];
    }

    for(int i=1; i<=n; i++) {
        H[i] = min(H[i], H[i-1] + 1);
    }

    for(int i=n; i>=1; i--) {
        H[i] = min(H[i], H[i+1] + 1);
    }

    int best = 0;
    for(int i=1; i<=n; i++) {
        best = max(best, H[i]);
    }

    cout << best;
    return 0;
}