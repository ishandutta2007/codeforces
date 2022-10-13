#include <bits/stdc++.h>

using namespace std;
typedef int var;
typedef pair<var, var> Pair;

#define MAXN 500000
bool Table[MAXN];
vector<var> G[MAXN];
priority_queue< Pair, vector<Pair> > Heap;

var getBad(var node) {
    var total = 0;
    for(auto vec : G[node]) {
        total += Table[vec] == Table[node];
    }
    return total;
}

void Clean() {
    while(Heap.top().first != getBad(Heap.top().second))
        Heap.pop();
}

void Push(var node) {
    Heap.emplace(getBad(node), node);
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

    var n, m, a, b;
    Read(n); Read(m);
    while(m--) {
        Read(a); Read(b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(var i=1; i<=n; i++) {
        Push(i);
    }

    var it = 2 * n + 100;
    while(it--) {
        Clean();
        auto top = Heap.top();
        Heap.pop();
        if(top.first < 2) {
            for(var i=1; i<=n; i++) {
                cout<<Table[i];
            }
            return 0;
        }


        Table[top.second] ^= 1;
        //Push(top.second);
        for(auto vec : G[top.second]) {
            Push(vec);
        }

    }

    cout<<"-1";
    return 0;
}