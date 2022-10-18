
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
#define l "%lld"
#define ll "%lld%lld"
#define lll "%lld%lld%lld"
#define llll "%lld%lld%lld%lld"
#define e else if
std::string _l = l;

using namespace std;

typedef unsigned long long u_;
typedef long long _;
typedef int _0;
typedef unsigned int u_0;
typedef long double _D;
typedef string str;
typedef const long long constant;

constant maxn = 2E5+88;
_ n, trie[maxn*30][2], cnt, s, c, t, p;

void dfs(_ r, _ lv);
_ find(_ a, _ b, _ lv);
void insert();
int main(int argc, char * argv[]) {
    
    scanf(l, &n);
    for(_ i = 1; i <= n; ++i) insert();
    dfs(0, 30);
    printf(fs(_l+"\n"), s);
    
    return 0;
}

void insert() {
    scanf(l, &c);
    t = p = 0;
    for(_ i = 30; ~i; --i) {
        if(!trie[p][!!((1<<i)&c)]) trie[p][!!((1<<i)&c)] = ++cnt;
        p = trie[p][!!((1<<i)&c)];
    }
    return;
}

_ find(_ a, _ b, _ lv) {
    if(!~lv) return 0;
    _ x, y;
    x = y = ~(_)0;
    if(trie[a][0] && trie[b][0]) x = find(trie[a][0], trie[b][0], lv-1);
    if(trie[a][1] && trie[b][1]) y = find(trie[a][1], trie[b][1], lv-1);
    if(~x && ~y) return min(x, y);
    if(~x) return x;
    if(~y) return y;
    if(trie[a][1] && trie[b][0]) x = find(trie[a][1], trie[b][0], lv-1)+(1<<lv);
    if(trie[a][0] && trie[b][1]) y = find(trie[a][0], trie[b][1], lv-1)+(1<<lv);
    if(~x && ~y) return min(x, y);
    if(~x) return x;
    return y;
}

void dfs(_ r, _ lv) {
    if(!~lv) return;
    if(trie[r][0] && trie[r][1]) s += find(trie[r][0], trie[r][1], lv-1)+(1<<lv);
    if(trie[r][0]) dfs(trie[r][0], lv-1);
    if(trie[r][1]) dfs(trie[r][1], lv-1);
    return;
}