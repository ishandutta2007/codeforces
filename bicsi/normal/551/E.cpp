#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef int var;

#define SIZE 700

const var MAXV = 1e9 + 1;

var B[1000][SIZE];
var I[1000][SIZE];
var ADD[1000];
var n;

void Sort(var bi) {
    sort(I[bi], I[bi]+SIZE, [&bi](var a, var b) {
            if(B[bi][a] != B[bi][b])
                return B[bi][a] < B[bi][b];
            return a < b;
    });
}

void add(var b, var e, var val) {
    var buck;
    var i = b;
    for(buck=i/SIZE; i%SIZE && i<=e;i++) {
        B[buck][i%SIZE] += val;
        B[buck][i%SIZE] = min(B[buck][i%SIZE], MAXV);
    }
    Sort(buck);

    if(i > e)
        return;

    for(buck=i/SIZE; i+SIZE-1<=e; buck++, i+=SIZE) {
        ADD[buck] += val;
        ADD[buck] = min(ADD[buck], MAXV);
    }

    if(i > e)
        return;

    for(buck=i/SIZE; i<=e; i++) {
        B[buck][i%SIZE] += val;
        B[buck][i%SIZE] = min(B[buck][i%SIZE], MAXV);
    }
    Sort(buck);
}

var firstApp(var ind, var val) {

    var *Bb = B[ind];
    var *Ii = I[ind];

    var poz = -1;
    for(var i = (1 << 9); i; i>>=1) {
        if(i + poz < SIZE && Bb[Ii[i+poz]] < val)
            poz += i;
    }
    poz++;

    if(Bb[Ii[poz]] != val)
        return -1;
    return Ii[poz];
}

var lastApp(var ind, var val) {

    var *Bb = B[ind];
    var *Ii = I[ind];

    var poz = -1;
    for(var i = (1 << 9); i; i>>=1) {
        if(i + poz < SIZE && Bb[Ii[i+poz]] <= val)
            poz += i;
    }

    if(Bb[Ii[poz]] != val)
        return -1;
    return Ii[poz];
}

var query(var val) {

    var first = 1000000, last = 0;

    for(var i=0, buck=0; i<=n; buck++, i+=SIZE) {
        var p1 = firstApp(buck, val - ADD[buck]);
        if(p1 == -1) continue;
        var p2 = lastApp(buck, val - ADD[buck]);

        first = min(first, i + p1);
        last = max(last, i + p2);
    }

    return max(-1, last - first);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var q;
    cin>>n>>q;

    for(var i=1; i<=n; i++) {
        cin>>B[i/SIZE][i%SIZE];
    }
    for(var i=n+1; i%SIZE; i++)
        B[i/SIZE][i%SIZE] = MAXV;

    for(var i=0; i<=n/SIZE; i++) {
        for(var j=0; j<SIZE; j++) {
            I[i][j] = j;
        }
        Sort(i);
    }

    var type, b, e, val;

    while(q--) {
        cin>>type;
        if(type == 1) {
            cin>>b>>e>>val;
            add(b, e, val);
        } else {
            cin>>val;
            cout<<query(val)<<'\n';
        }
    }

    return 0;
}