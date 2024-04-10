#include <iostream>
#include <cstdio>

using namespace std;
typedef unsigned long long var;

var m;
var Rez[2][2], M[2][2], Aux[2][2];

void inm(var A[2][2], var B[2][2]) {
    for(var i=0; i<2; i++) {
        for(var j=0; j<2; j++) {
            Aux[i][j] = (A[i][0] * B[0][j] + A[i][1] * B[1][j]) % m;
        }
    }

    for(var i=0; i<2; i++) {
        for(var j=0; j<2; j++) {
            A[i][j] = Aux[i][j];
        }
    }
}

var getFib(var n) {
    Rez[0][0] = 2 % m;
    Rez[0][1] = Rez[1][0] = Rez[1][1] = 1 % m;

    M[0][0] = M[1][0] = M[0][1] = 1 % m;
    M[1][1] = 0;

    for(var i=1; i<=n; i<<=1) {
        if(n & i) {
            inm(Rez, M);
        }
        inm(M, M);
    }

    return Rez[0][1];
}

var pow2(var e) {
    var b = 2 % m, rez = 1 % m;
    for(var i=1; i<=e; i<<=1) {
        if(e & i) {
            rez *= b;
            rez %= m;
        }
        b *= b;
        b %= m;
    }
    return rez;
}

int main() {


    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var k, n, l;

    cin>>n>>k>>l>>m;

    var pow = pow2(n);
    var fib = getFib(n);
    var total = 1 % m;

    if(l < 64 && ((1LL << l) - 1) < k) {
        cout<<0;
        return 0;
    }


    for(var i=0; i<l; i++) {
        bool bit = (k >> i) & 1;
        if(k & (1LL << i)) {
            total *= pow + m - fib;
        } else {
            total *= fib;
        }
        total %= m;
    }

    cout<<total;
    return 0;
}