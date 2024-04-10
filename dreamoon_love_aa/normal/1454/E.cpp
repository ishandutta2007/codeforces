#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 2e5 + 5;
#define UnionFindSIZE 1234567
struct Union_Find {
    int d[UnionFindSIZE], num[UnionFindSIZE];
    void init(int n){
        for(int i = 0; i < n; i++) {
            d[i]=i;
            num[i]=1;
        }
    }
    int find(int x){
        int y = x, z = x;
        while(y != d[y]) { y = d[y]; }
        while(x != y) {
            x = d[x];
            d[z] = y;
            z = x;
        }
        return y;
    }
    bool is_root(int x) { return d[x] == x; }
    bool uu(int x,int y) {
        x=find(x);
        y=find(y);
        if(x == y) { return 0; }
        if(num[x] > num[y]) { swap(x,y); }
        num[y] += num[x];
        d[x] = y;
        return 1;
    }
}U;
vector<int> e[SIZE];
int deg[SIZE];
int bfs[SIZE];
void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) { e[i].clear(); deg[i] = 0; }
    for(int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        deg[u]++;
        deg[v]++;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int rr = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1) {
            bfs[rr++] = i;
        }
    }
    U.init(n + 1);
    for(int i = 0; i < rr; i++) {
        int x = bfs[i];
        for(int y: e[x]) {
            deg[y]--;
            U.uu(x, y); 
            if(deg[y] == 1) {
                bfs[rr++] = y;
            }
        }
    }
    long long answer = n * (n - 1LL);
    for(int i = 1; i <= n; i++) {
        if(U.is_root(i)) {
            answer -= U.num[i] * (U.num[i] - 1LL) / 2;
        }
    }
    printf("%lld\n", answer);
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}