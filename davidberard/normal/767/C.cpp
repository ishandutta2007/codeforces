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

const int NMAX = 1000100;

int n, cc;
struct edge{int to, next;} e[NMAX];
int head[NMAX];
int sum[NMAX];
int t[NMAX];
int root;
int c1, c2;
int g1, g2;

int dfs(int u, int goal) {
    sum[u] = t[u];
    int f = 0;
    for(int h = head[u]; h; h = e[h].next) {
        f = max(dfs(e[h].to, goal), f);
        sum[u] += sum[e[h].to];
    }
    if(u == root) return 0;
    if(sum[u] == goal && !f) {
        if(!c1) {
            c1 = u;
            f = 1;
        } else {
            c2 = u;
            f = 2;
        }
        if(c1 && c2) {
            g1 = c1;
            g2 = c2;
        }
    } else if(sum[u] == goal*2 && f) {
        if(f == 1) c2 = u;
        else c1 = u;
        g1 = c1;
        g2 = c2;
    }
    return f;
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
    int sgn = 1;
    for(c=get(); c>'9' || c<'0'; c=get()) if(c == '-') sgn = -1;
    for(; c>='0' && c<='9'; c=get()) x = x*10+c-'0';
    x *= sgn;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    read(n);
    int tot = 0;
    for(int i=1; i<=n; ++i) {
        int par;
        read(par); read(t[i]);
        tot += t[i];
        if(par == 0) root = i;
        else {
            ++cc;
            e[cc].to = i;
            e[cc].next = head[par];
            head[par] = cc;
        }
    }
    if(tot%3) {
        cout << -1 << endl;
        return 0;
    }
    dfs(root, tot/3);
    if(!g1 || !g2) {
        cout << -1 << endl;
        return 0;
    }
    cout << g1 << " " << g2 << endl;
    return 0;
}