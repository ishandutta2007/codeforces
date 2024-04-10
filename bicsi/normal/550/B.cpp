#include <iostream>
#include <cstdio>

using namespace std;
typedef int var;

var C[500000];

int main() {
    //freopen("debug.in", "r", stdin);
    //freopen("debug.out", "w", stdout);

    var n, l, r, x;

    cin>>n>>l>>r>>x;

    var sol = 0;

    for(var i=0; i<n; i++) {
        cin>>C[i];
    }

    for(var conf = 0; conf < (1<<n); conf++) {
        var chosen = 0, mx = -1, mn = 1000005;
        for(var i=0; i<n; i++) {
            if(conf & (1 << i)) {
                chosen += C[i];
                mx = max(mx, C[i]);
                mn = min(mn, C[i]);
            }
        }
        if(chosen >= l && chosen <= r && mx - mn >= x) {
            sol++;
        }
    }

    cout<<sol;

    return 0;
}