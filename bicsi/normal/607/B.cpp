#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

int V[2000];
int DP[2000][2000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, a, b;
    cin>>n;

    for(int i=1; i<=n; i++) cin>>V[i];

    for(int i=1; i<=n; i++) DP[i][i] = 1;
    for(int i=1; i<n; i++) {
        DP[i][i+1] = 1 + (V[i] != V[i+1]);
    }

    for(int delta=2; delta<=n; delta++)
    for(int i=1; i+delta<=n; i++) {
        int j = i+delta;

        DP[i][j] = 250000;
        for(int k=i; k<j; k++) {
            DP[i][j] = min(DP[i][j], DP[i][k] + DP[k+1][j]);
        }

        if(V[i] == V[j])
            DP[i][j] = min(DP[i][j], DP[i+1][j-1]);
    }

    cout << DP[1][n] << '\n';

    return 0;
}