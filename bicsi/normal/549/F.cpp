#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
typedef int var;

#define MAXK 1000000
#define MAXN 300005

vector<var> Maxes[MAXK];
var I[MAXK];
var V[MAXN];
bool InQ[MAXK];
vector<var> Undo;

long long total = 0;
var k;

void Count(var b1, var e1, var step1, var b2, var e2, var step2, bool equals) {
    var sum = 0, maxx = 0;
    for(var i=b1; i!=e1; i+=step1) {
        sum += V[i];
        sum %= k;

        maxx = max(maxx, V[i]);
        Maxes[sum].push_back(maxx);
        if(!InQ[sum]) {
            Undo.push_back(sum);
            InQ[sum] = 1;
        }
    }

    sum = maxx = 0;
    for(var i=b2; i!=e2; i+=step2) {
        sum += V[i];
        sum %= k;
        maxx = max(maxx, V[i]);

        var rem = (maxx - sum) % k;
        if(rem < 0) rem += k;

        vector<var> &Max = Maxes[rem];
        var &ind = I[rem];
        while(ind < Max.size() && Max[ind] + equals <= maxx)
            ind++;
        total += ind;
    }

    while(Undo.size()) {
        auto r = Undo.back();
        Undo.pop_back();
        I[r] = 0;
        Maxes[r].clear();
        InQ[r] = 0;
    }
}

void Solve(var b, var e) {

    // auto oldtotal = total;

    if(b == e) {
        return;
    }

    var m = (b + e) / 2;
    Solve(b, m);
    Solve(m+1, e);

    var sum = 0, maxx = 0;

    Count(m, b-1, -1, m+1, e+1, 1, 0);
    Count(m+1, e+1, 1, m, b-1, -1, 1);

    // cerr << "IN: " << b << " " << e << " FOUND " << total - oldtotal << '\n';
}

#define DIM 100000
char buff[DIM];
var poz;
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

    var n;
    Read(n); Read(k);
    for(var i=1; i<=n; i++) {
        Read(V[i]);
    }

    Solve(1, n);
    cout << total;

    return 0;
}