#include <bits/stdc++.h>

using namespace std;
typedef int64_t var;

var V[500000];
var Part1[500000], Part2[500000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, k, x;
    cin>>n>>k>>x;
    for(int i=1; i<=n; i++) cin>>V[i];

    var r = 1;
    for(int i=1; i<=k; i++) r *= x;

    for(int i=1; i<=n; i++) Part1[i] = Part1[i-1] | V[i];
    for(int i=n; i; i--) Part2[i] = Part2[i+1] | V[i];

    var best = 0;
    for(int i=1; i<=n; i++) {
        best = max(best, Part1[i-1] | Part2[i+1] | (V[i] * r));
    }
    cout<<best;


    return 0;
}