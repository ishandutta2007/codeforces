#include <cstdio>
#include <cstring>

#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int max_int = (1LL << 31) - 1;

//#define LOCAL

#ifdef LOCAL
#include <fstream>
ifstream cin("input.txt");
ofstream cout("output.txt");
#else
#include <iostream>
#endif

const int max_n = 1e5 + 100;

int n;
vector<vector<int> > g, w;
int c[max_n], ch[max_n];

int is_happy(int x) {
    while (x > 0) {
        if (x % 10 != 4 && x % 10 != 7)
            return 0;
        x /= 10;
    }
    return 1;
}

void go(int v, int pr) {
    c[v] = 1;
    ch[v] = 0;
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if (g[v][i] == pr) continue;
        
        go(g[v][i], v);
        c[v] += c[g[v][i]];
        if (w[v][i]) {
            ch[v] += c[g[v][i]];
        } else {
            ch[v] += ch[g[v][i]];
        }
    }
}

void go1(int v, int pr) {
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if (g[v][i] == pr) continue;
        
        if (w[v][i]) {
            ch[g[v][i]] += n - c[g[v][i]];
        } else {
            ch[g[v][i]] = ch[v];
        }
    }
    for (int i = 0; i < (int) g[v].size(); ++i) {
        if (g[v][i] == pr) continue;
        
        go1(g[v][i], v);
    }
}

int main() { 
    cin >> n;
    g.resize(n);
    w.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2, ww;
        cin >> v1 >> v2 >> ww;
        --v1; --v2; 
        g[v1].push_back(v2);
        g[v2].push_back(v1);
        int r = is_happy(ww);
        w[v1].push_back(r);
        w[v2].push_back(r);
    }
    go(0, 0);
    go1(0, 0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) 
        ans = ans + 1LL * ch[i] * (ch[i] - 1);
    cout << ans << endl;
    return 0;
}