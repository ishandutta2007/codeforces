#include <bits/stdc++.h>

using namespace std;
typedef int var;

var State[5000], End[5000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    var n;
    cin>>n;

    for(var i=1; i<=n; i++) {
        cin>>End[i];
    }

    for(var i=1; i<=n; i++) {
        State[i] = i-1;
    }

    for(var it=1; it<=n; it++) {
        bool bad = 0;
        for(var i=1; i<=n; i++) {
            if(i & 1) {
                State[i]++;
                if(State[i] >= n) State[i] -= n;
            } else {
                State[i]--;
                if(State[i] < 0) State[i] += n;
            }
            if(State[i] != End[i]) bad = 1;
        }

        if(!bad) {
            cout<<"Yes";
            return 0;
        }
    }

    cout<<"No";
    return 0;
}