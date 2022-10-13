#include<bits/stdc++.h>
using namespace std;
typedef int64_t var;

bool Take[1000];

var n;
var P[1000];
var Start[1000], End[1000];

bool Bit[1000];

void getBit(var k) {
    memset(Bit, 0, sizeof(Bit));

    if(k > End[1]) return;

    while(k>1) {
        var i;
        for(i=n; k>=Start[i] && i; i--);
        i++;
        Bit[i] = 1;
        k -= Start[i] - 1;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    var k;
    cin>>n>>k;

    if(n == 1) {cout<<1; return 0;}

    Start[n] = End[n] = 1;
    Start[n-1] = 2;
    End[n-1] = 2;
    for(var i=n-2; i; i--) {
        Start[i] = End[i+1] + 1;
        End[i] = Start[i] + End[i+2] - 1;
    }
    Start[0] = End[1] + 1;
    getBit(k);

    for(var i=1; i<=n; i++) P[i] = i;

    for(var i=1; i<=n; i++) {
        if(Bit[i]) swap(P[i], P[i+1]);
    }


    for(var i=1; i<=n; i++) cout<<P[i]<<" ";

    return 0;
}