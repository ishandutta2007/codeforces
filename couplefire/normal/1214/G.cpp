#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define f first
#define s second

int n, m, q;
bitset<N> g[N];
bitset<N> p[N];
set<pair<int, int>> c;
set<pair<int, int>> a;

void cg(int i, int j, bool x){
    if((g[i]&g[j]) != g[i]){
        if(x) a.erase({min(i, j), max(i, j)});
        else a.insert({min(i, j), max(i, j)});
    }
}

void go(int ind, bool x){
    auto it = c.find({g[ind].count(), ind});
    if(it != (--c.end())) cg((*it).s, (*next(it)).s, x);
    if(it != c.begin()) cg((*prev(it)).s, (*it).s, x);
    if(it != c.begin() && it != (--c.end())) cg((*prev(it)).s, (*next(it)).s, x^1);
}

void solve(){
    int ind, l, r; scanf("%d%d%d",&ind,&l,&r); --ind, --l, --r;
    go(ind, 1);
    c.erase({g[ind].count(), ind});
    g[ind] ^= p[r-l+1]<<l;
    c.insert({g[ind].count(), ind});
    go(ind, 0);
    if(a.empty()){
        printf("-1\n"); return;
    }
    int i = (*a.begin()).f, j = (*a.begin()).s;
    int l1 = (g[i]^(g[i]&g[j]))._Find_first();
    int l2 = (g[j]^(g[i]&g[j]))._Find_first();
    if(i>j) swap(i, j); if(l1>l2) swap(l1, l2);
    printf("%d %d %d %d\n",i+1,l1+1,j+1,l2+1);
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i = 1; i<N; i++) p[i] = p[i-1]<<1, p[i].set(0);
    for(int i = 0; i<N; i++) g[i].reset();
    for(int i = 0; i<n; i++) c.insert({0, i});
    while(q--) solve();
}