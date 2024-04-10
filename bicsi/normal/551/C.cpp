#include <iostream>
#include <cstdio>

using namespace std;
typedef long long var;

var n, m;
var W[200000], V[200000];

bool good(var T) {
    var curelem = 1;
    var curperson = 1;
    var curtime = T - 1;

    for(var i=1; i<=n; i++) {
        V[i] = W[i];
    }


    while(true) {
        var sub = min(V[curelem], curtime);
        curtime -= sub;
        V[curelem] -= sub;

        if(V[curelem] == 0) {
            curelem ++;
            curtime --;
        }

        if(curtime <= 0) {
            curperson ++;
            curtime = T - curelem;
        }

        if(curelem > n)
            return true;

        if(curperson > m)
            return false;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin>>n>>m;
    var last;
    for(var i=1; i<=n; i++) {
        cin>>W[i];
        if(W[i])
            last = i;
    }
    n = last;

    var sol = 0;
    for(var M = (1LL << 61); M; M >>=1) {
        if(!good(sol + M))
            sol += M;
    }

    cout<<sol + 1;
    return 0;
}