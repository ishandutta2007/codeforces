#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int DP[5000000], Pow[5000000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, a, b;
    cin>>n;

    int maxx = 0;
    for(int i=1; i<=n; i++) {
        cin>>a>>b;
        a++;
        maxx = max(maxx, a);
        Pow[a] = b;
    }

    int best = 0;

    for(int i=1; i<=maxx; i++) {
        if(!Pow[i]) DP[i] = DP[i-1];
        else DP[i] = 1 + DP[max(0, i - Pow[i] - 1)];

        best = max(best, DP[i]);
    }

    cout << n - best;

    return 0;
}