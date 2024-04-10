#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>

using namespace std;
typedef int var;

const var MAXN = 1e5 + 1;

var DSus[MAXN], DJos[MAXN][2];
var Goes[MAXN];
vector<var> G[MAXN];
bool Viz[MAXN];
var Parent[MAXN];

void dfsJos(var node) {
    Viz[node] = 1;
    for(auto vec : G[node]) {
        if(!Viz[vec]) {
            Parent[vec] = node;
            dfsJos(vec);
            if(DJos[vec][0]) {
                if(DJos[vec][0] + 1 > DJos[node][0]) {
                    DJos[node][1] = DJos[node][0];
                    DJos[node][0] = DJos[vec][0] + 1;
                    Goes[node] = vec;
                } else if(DJos[vec][0] + 1 > DJos[node][1]) {
                    DJos[node][1] = DJos[vec][0] + 1;
                }
            }
        }
    }
}

void dfsSus(var node) {

    if(DSus[Parent[node]])
        DSus[node] = DSus[Parent[node]] + 1;

    bool choose = 0;
    if(Goes[Parent[node]] == node) {
        choose = 1;
    }

    if(DJos[Parent[node]][choose])
        DSus[node] = max(DSus[node], DJos[Parent[node]][choose] + 1);

    for(auto vec : G[node]) {
        if(vec != Parent[node]) {
            dfsSus(vec);
        }
    }
}

#define DIM 100000
var poz;
char buff[DIM];

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

    cin.read(buff, DIM);

    var n, k, D, a, b;
    Read(n); Read(k); Read(D);

    while(k--) {
        Read(a);
        DSus[a] = DJos[a][0] = 1;
    }

    for(var i=1; i<n; i++) {
        Read(a); Read(b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    dfsJos(1);
    dfsSus(1);

    var cnt = 0;

    for(var node = 1; node <= n; node ++) {
        var d = max(DSus[node], DJos[node][0]) - 1;
        if(d <= D) {
            // cerr << node << " ";
            cnt ++;
        }
    }

    cout << cnt;

    return 0;
}