#include <bits/stdc++.h>

using namespace std;
typedef int64_t var;

var cpairs(var A, var B, var C) {
    A = min(A, C);
    B = min(B, C);

    if(C < 0) return 0;
    if(C == 0) return 1;
    if(C >= A+B) return (A+1)*(B+1);

    var x = A+B-C-1;
    return (A+1)*(B+1) - (x+1)*(x+2)/2;
}

var l;
var cnt(var a, var b, var c, var l) {
    //a > b > c
    var maxx = max(max(a, b+1), c+1);
    l -= maxx - a;
    a = maxx;


    int64_t total = 0;
    for(;l>=0; a++, l--) {
        if(b+c+l <= a) break;
        total += cpairs(a-b-1, a-c-1, l) - cpairs(a-b-1, a-c-1, a-b-c);
    }
    return total;

}

var cnteq(var a, var b, var c, var l) {
    var maxx = max(max(a, b), c);

    l -= 3*maxx - a - b - c;

    if(l < 0) return 0;
    return l / 3 + 1;
}

var cntis(var a, var b, var c, var l) {
    //a == b, c < a

    var maxx = max(max(a, b), c+1);
    l -= 2*maxx - a - b;
    a = b = maxx;

    if(l < 0) return 0;

    int64_t total = 0;
    for(;l>=0;a++, b++, l-=2)
        total += min(l, a-c-1) + 1;
    return total;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    var a, b, c;
    cin>>a>>b>>c>>l;
    var eq = cnteq(a, b, c, l);
    var isc = cntis(a, b, c, l) + cntis(b, c, a, l) + cntis(c, a, b, l);
    var cn = cnt(a, b, c, l) + cnt(b, c, a, l) + cnt(c, a, b, l);

    cout<<eq + isc + cn;

    return 0;
}