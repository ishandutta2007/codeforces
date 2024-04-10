#include <bits/stdc++.h>

using namespace std;
typedef int var;

#define MAXN 100005

var V[MAXN], D[MAXN], Last[MAXN];
bool Viz[MAXN];
vector<var> G[MAXN];

#define MAX 2005000
vector<var> Prime;
bool P[MAX+1];
unordered_map<var, var> PI;
void ciur() {
    for(var i=2; i<=MAX; i++) {
        if(P[i]) continue;
        PI[i] = Prime.size();
        Prime.push_back(i);
        for(var j=i+i; j<=MAX; j+=i)
            P[j]=1;
    }
}

void Factorize(var val, vector<var> &F) {
    for(var i=0, d=2; d*d<=val; d=Prime[++i]) {
        if(val % d == 0) {
            F.push_back(i);
            while(val % d == 0)
                val /= d;
        }
    }
    if(val > 1)
        F.push_back(PI[val]);
}

var LastAp[300000];

void dfs(var node) {
    vector<var> Fact, Aux;
    Factorize(V[node], Fact);
    Viz[node] = 1;
    Last[node] = 0;

    for(auto f : Fact) {
        if(D[LastAp[f]] > D[Last[node]])
            Last[node] = LastAp[f];
        Aux.push_back(LastAp[f]);
        LastAp[f] = node;
    }

    for(auto vec : G[node]) {
        if(!Viz[vec]) {
            D[vec] = D[node] + 1;
            dfs(vec);
        }
    }

    for(var i=0; i<Fact.size(); i++) {
        LastAp[Fact[i]] = Aux[i];
    }
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

    var n, m, a, b, c;
    Read(n); Read(m);
    ciur();

    for(var i=1; i<=n; i++) {
        Read(V[i]);
    }

    for(var i=1; i<n; i++) {
        Read(a); Read(b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    D[0] = -1;
    dfs(1);

    var t;
    while(m--) {
        Read(t);
        if(t == 1) {
            Read(a);
            cout<<( Last[a] ? Last[a] : -1 )<<'\n';
        } else {
            Read(a); Read(V[a]);
            memset(LastAp, 0, sizeof(LastAp));
            memset(Viz, 0, sizeof(Viz));
            dfs(1);
        }
    }

    return 0;
}