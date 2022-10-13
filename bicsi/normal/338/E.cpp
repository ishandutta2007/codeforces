#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
typedef int var;

#define MAXN 150001

var Small[MAXN];
var Val[MAXN];
var M;
var n, k, h;
var Right[MAXN];

void getRight(var ind) {
    var val = Val[ind];

    var poz = 0;
    for(var i=M; i; i>>=1) {
        if(poz + i <= k && Small[poz+i] + val >= h)
            poz += i;
    }

    Right[ind] = poz;
}

#define mid(a,b) ((a+b)/2)
#define INF 1000000000

var Min[4*MAXN], Lazy[4*MAXN];

void update(var node, var b, var e) {
    Min[node] += Lazy[node];
    if(b != e) {
        Lazy[node*2] += Lazy[node];
        Lazy[node*2+1] += Lazy[node];
    }
    Lazy[node] = 0;
}

void addTree(var node, var b, var e, var l, var r, var add) {

    update(node, b, e);

    if(b >= l && e <= r) {
        Min[node] += add;
        if(b != e) {
            Lazy[node*2] += add;
            Lazy[node*2+1] += add;
        }
        return;
    }

    if(e < l || b > r)
        return;

    var m = mid(b, e);
    addTree(node*2, b, m, l, r, add);
    addTree(node*2+1, m+1, e, l, r, add);

    Min[node] = min(Min[node*2], Min[node*2+1]);
}

void build(var node, var b, var e) {
    if(b == e) {
        Min[node] = b-k-1;
        return;
    }
    var m = mid(b, e);
    build(node*2, b, m);
    build(node*2+1, m+1, e);
    Min[node] = min(Min[node*2], Min[node*2+1]);
}


void dump(var node, var b, var e) {
    update(node, b, e);
    if(b == e) {
        cerr << Min[node] << " ";
        return;
    }
    var m = mid(b, e);
    dump(node*2, b, m);
    dump(node*2+1, m+1, e);
}

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    cin>>n>>k>>h;
    for(var i=1; i<=k; i++) {
        cin>>Small[i];
    }

    for(M=1; M<=k; M<<=1);
    M>>=1;

    sort(Small+1, Small+k+1, std::greater<var>());

    build(1, 1, k);

    for(var i=1; i<=k; i++) {
        cin>>Val[i];
        getRight(i);

        if(Right[i])
            addTree(1, 1, k, 1, Right[i], 1);
    }

    var cnt = 0;

    #ifndef ONLINE_JUDGE
    dump(1, 1, k);
    cerr<<'\n';
    #endif // ONLINE_JUDGE

    update(1, 1, k);
    if(Min[1] >= 0) {
        cnt++;
    }

    for(var i=k+1; i<=n; i++) {
        cin>>Val[i];
        getRight(i);

        if(Right[i-k])
            addTree(1, 1, k, 1, Right[i-k], -1);
        if(Right[i])
            addTree(1, 1, k, 1, Right[i], 1);

        update(1, 1, k);
        if(Min[1] >= 0) {
            cnt++;
        }

        #ifndef ONLINE_JUDGE
        dump(1, 1, k);
        cerr<<'\n';
        #endif // ONLINE_JUDGE

    }

    cout<<cnt;

    return 0;
}