#include <cstdio>
#include <iostream>
#include <cstdlib>
 
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <sstream>
 
#include <cmath>
#include <cstring>
#include <ctime>
 
#include <bitset>
#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <algorithm>
#include <numeric>
 
#define fs(str) (str).c_str()
#define _lin "%lld"
#define _llin "%lld%lld"
#define _lllin "%lld%lld%lld"
#define _llllin "%lld%lld%lld%lld"
std::string _l = "%lld";
std::string _d = "%d";
std::string _s = "%s";
std::string _f = "%Lf";
 
using namespace std;
 
typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;
 
constant maxn = 2E5+88;
constant absmax = maxn<<2;
//constant maxn = 4;
struct point {
    _ x, y;
    bool operator < (const point &b) const {
        return x*maxn+y < b.x*maxn+b.y;
    }
} a[absmax];
struct edge {
    _ to, id;
};
_ n, head[absmax], cnt;
vector<edge> g[absmax];
map<point, bool> s;
bool u[absmax], c, v[absmax];
 
void dfs(_ x);
int main(int argc, char * argv[]) {
    
    scanf(_lin, &n);
    for(_ i = 1; i <= n; ++i) {
        scanf(_llin, &a[i].x, &a[i].y);
        a[i].y += maxn;
        g[a[i].x].push_back({a[i].y, i});
        g[a[i].y].push_back({a[i].x, i});
    }
    cnt = n;
    for(_ i = 1; i <= maxn; ++i) if(g[i].size() & 1) {
        g[(maxn<<1)+1].push_back({i, ++cnt});
        g[i].push_back({(maxn<<1)+1, cnt});
    }
    for(_ i = maxn+1; i <= maxn<<1; ++i) if(g[i].size() & 1) {
        g[(maxn<<1)+2].push_back({i, ++cnt});
        g[i].push_back({(maxn<<1)+2, cnt});
    }
    if(g[(maxn<<1)+1].size() & 1) {
        g[(maxn<<1)+1].push_back({(maxn<<1)+2, ++cnt});
        g[(maxn<<1)+2].push_back({(maxn<<1)+1, cnt});
    }
    for(_ i = 1; i <= (maxn<<1); ++i) if(!v[i]) dfs(i);
    for(_ i = 1; i <= n; ++i) putchar(s[a[i]] ? 'b' : 'r');
    putchar(10);
    
    return 0;
}
 
void dfs(_ x) {
    v[x] = true;
    for(_ i = head[x]; i < g[x].size(); i = head[x]) {
        ++head[x];
        if(!u[g[x][i].id]) {
            u[g[x][i].id] = true;
            dfs(g[x][i].to);
            s[{min(g[x][i].to, x), max(g[x][i].to, x)}] = c;
            c = !c;
            //cout << x <<' '<< g[x][i].to << endl;
        }
    }
    return;
}