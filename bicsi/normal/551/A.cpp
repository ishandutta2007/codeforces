#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef int var;

var P[5000], Place[5000], I[5000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n;
    cin>>n;

    for(var i=1; i<=n; i++) {
        cin>>P[i];
        I[i] = i;
    }

    sort(I+1, I+n+1, [](var a, var b) {
            return P[a] > P[b];
    });

    var last = -1;
    for(var i=1; i<=n; i++) {
        if(P[I[i]] == P[I[i-1]]) {
            Place[I[i]] = Place[I[i-1]];
        } else {
            Place[I[i]] = i;
        }
    }

    for(var i=1; i<=n; i++) {
        cout<<Place[i]<<" ";
    }

    return 0;
}