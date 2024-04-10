#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;
typedef int var;

map<var, var> Vals;
unordered_map<var, var> Map;
vector< pair<var, var> > Ops;

void print(vector<var> &V) {
    for(auto v : V) {
        cerr << v << " ";
    }
    cerr << endl;
}

#define MAX 500000
var Tree[MAX], V[MAX], No[MAX];
#define zeros(a) ((a)&(-a))
void add(var ind, var val) {
    for(;ind<MAX; ind += zeros(ind))
        Tree[ind] += val;
}
var query(var ind) {
    var s = 0;
    for(;ind;ind -= zeros(ind))
        s += Tree[ind];
    return s;
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

    // freopen("debug.in", "r", stdin);
    // freopen("debug.out", "w", stdout);

    var n, a, b;
    cin.read(buff, DIM);
    Read(n);

    for(var i=1; i<=n; i++) {
        Read(a);
        Read(b);
        Ops.push_back(make_pair(a, b));
        Vals[a-1] = Vals[a] = Vals[b-1] = Vals[b] = 1;
    }
    Vals[0] = 1;

    var i = 1;
    auto it = Vals.begin(), last = Vals.begin();
    for(++it; it != Vals.end(); ++it, ++last, i++) {
        No[i] = it->first - last->first;
        V[i] = i;
        Map[it->first] = i;
    }

    // print(No);

    for(auto op : Ops) {
        swap(V[Map[op.first]], V[Map[op.second]]);
    }

    // print(V);
    int64_t inv = 0;
    for(var i=Vals.size() - 1; i>=0; i--) {
        var v = V[i];

        if(v == 0)
            continue;

        inv += 1LL * No[v] * query(v - 1);
        add(v, No[v]);
    }

    cout << inv;




    return 0;
}