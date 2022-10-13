#include <bits/stdc++.h>

using namespace std;
typedef int var;
typedef pair<var, var> Pair;

#define MAXN 100005


var Len[MAXN], I[MAXN], Cost[MAXN];
var CountC[400];

unordered_map<var, var> Coost, Count;


#define DIM 100000
char buff[DIM];
var poz=DIM-1;
void Read(var &a) {
    while(!isdigit(buff[poz]))
        if(++poz == DIM)
            cin.read(buff, DIM), poz=0;
    a = 0;
    while(isdigit(buff[poz])) {
        a = a * 10 + buff[poz] - '0';
        if(++poz == DIM)
            cin.read(buff, DIM), poz=0;
    }
}


int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, x;
    Read(n);

    for(var i=1; i<=n; i++) {
        Read(Len[i]);
        Count[Len[i]]++;
    }
    var tc = 0;
    for(var i=1; i<=n; i++) {
        Read(Cost[i]);
        I[i] = i;
        tc += Cost[i];
        Coost[Len[i]] += Cost[i];
    }

    sort(I+1, I+n+1, [](var a, var b) { return Len[a] < Len[b]; });

    var best = 2e9;

    for(var ii=1; ii<=n; ii++) {
        var len = Len[I[ii]];

        var howmany = Count[len];

        var econ = 0;
        var maxneeded = howmany - 1;
        for(var d=200; d; d--) {
            if(maxneeded > CountC[d]) {econ += d*CountC[d];maxneeded-=CountC[d];}
            else {econ += d*maxneeded; break;}
        }

        var cost = tc - econ - Coost[len];
        best = min(best, cost);

        for(; Len[I[ii]] == len; ii++) {
            CountC[Cost[I[ii]]]++;
        }
        ii--;
    }


    cout<<best;

    return 0;
}