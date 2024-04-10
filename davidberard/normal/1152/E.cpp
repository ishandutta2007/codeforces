#include <cassert>
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <random>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef long double ld;

const int NMAX = 200100;

int to[NMAX], g[NMAX];
int nxt[NMAX], val[NMAX], head[NMAX], deg[NMAX], pre[NMAX];
int orig[NMAX];

int n;
int b[NMAX], c[NMAX];
unordered_map<int, int> mp;
int cc, m=2;

int lst[NMAX], ln[NMAX], dd;

void add_edge(int u, int v) {
    m += 2;
    deg[u]++;
    deg[v]++;
    nxt[m-2] = head[u];
    pre[head[u]] = m-2;
    val[m-2] = v;
    head[u] = m-2;
    g[m-2] = 1;
    nxt[m-1] = head[v];
    pre[head[v]] = m-1;
    val[m-1] = u;
    head[v] = m-1;
    g[m-1] = 1;
}

void rem_edge(int m) {
    g[m] = 0;
    g[m^1] = 0;

    if(pre[m^1]) {
        nxt[pre[m^1]] = nxt[m^1];
    } else {
        head[val[m]] = nxt[m^1];
    }
    pre[nxt[m^1]] = pre[m^1];

    if(pre[m]) {
        nxt[pre[m]] = nxt[m];
    } else {
        head[val[m^1]] = nxt[m];
    }
    pre[nxt[m]] = pre[m];

    deg[val[m]]--;
    deg[val[m^1]]--;
}

void fill(int u, int pos) {
    lst[++dd] = u;
    ln[dd] = ln[pos];
    ln[pos] = dd;
    int e = head[u];
    for(int e = head[u]; e; e = nxt[e]) {
        //cerr << "  at " << e << endl;
        if(!g[e]) continue;
        //cerr << "Take edge " << e << endl;
        rem_edge(e);
        fill(val[e], ln[pos]);
        e = head[u];
    }
}

inline char get() {
    static char buf[100000], *S=buf, *T=buf;
    if(S == T) {
        T = (S=buf) + fread(buf, 1, 100000, stdin);
        if(S == T) return EOF;
    }
    return *S++;
}

inline void read(int& x) {
    static char c; x = 0;
    for(c=get(); c>'9' || c<'0'; c=get());
    for(; c>='0' && c<='9'; c=get()) x = x*10+c-'0';
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(n);
    for(int i=1; i<n; ++i) {
        read(b[i]);
        mp[b[i]] = -1;
    }
    for(int i=1; i<n; ++i) {
        read(c[i]);
        if(b[i] > c[i]) {
            cout << "-1\n";
            return 0;
        }
        mp[c[i]] = -1;
    }
    for(auto& x : mp) {
        x.second = ++cc;
        orig[x.second] = x.first;
    }
    for(int i=1; i<n; ++i) {
        b[i] = mp[b[i]];
        c[i] = mp[c[i]];
        add_edge(b[i], c[i]);
    }
    vector<int> start;
    for(int i=1; i<=cc; ++i) {
        if(deg[i]%2) start.push_back(i);
    }
    if(start.size() != 0 && start.size() != 2) {
        cout << "-1\n";
        return 0;
    }
    if(!start.size()) start.push_back(1);
    int root = *start.begin();
    dd = 2;
    ln[1] = 2;
    fill(root, 1);
    if(dd != 2+n) {
        cout << "-1\n";
        return 0;
    }
    for(int r = ln[1]; r != 2; r=ln[r]) {
        cout << orig[lst[r]] << " ";
    }
    cout << endl;
    return 0;
}