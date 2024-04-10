#include <bits/stdc++.h>

using namespace std;
typedef int var;

#define MAXN 100005
var A[2*MAXN];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n;
    double w;
    cin>>n>>w;

    for(var i=1; i<=2*n; i++) {
        cin>>A[i];
    }
    sort(A+1, A+2*n+1);

    var maxf = 2e9, maxb = 2e9;
    for(var i=1; i<=n; i++) {
        maxf = min(maxf, A[i]);
        maxb = min(maxb, A[i+n]);
    }

    double q;
    if(2*maxf <= maxb) q = maxf;
    else q = 0.5 * maxb;

    double totalq = 3 * n * q;
    cout<<fixed<<setprecision(8)<<min(totalq, w);

    return 0;
}