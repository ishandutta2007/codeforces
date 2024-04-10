/*
 template by c8kbf
 */

// macOS doesn't have <bits/stdc++.h> (shame)
#include <cstdlib>

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>

#include <cmath>
#include <cstring>
#include <ctime>

#include <deque>
#include <string>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

#include <algorithm>
#include <numeric>
#include <random>

//dont worry bout me, i'm not high
#define ef else if
#define leave exit(0);

#define v(x) vector<x >
#define v2(x) vector<vector<x > >
#define v3(x) vector<vector<vector<x > > >

#define ss(x) v(_)(x+8, 0)
#define ssz(type, x) v(type)(x+8, 0)
#define s2(x, y) v2(_)(x+8, v(_)(y+8, 0))
#define s2z(type, x, y) v2(type)(x+8, v(type)(y+8, 0))
#define s3(x, y, z) v3(_)(x+8, v2(_)(y+8, v(_)(z+8, 0)))
#define s3z(type, x, y, z) v3(type)(x+8, v2(type)(y+8, v(type)(z+8, 0)))

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef long double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

char untl = '\n';

//fastIO cos why not
inline _ read() {
    _ x = 0, f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    return x*f;
}

inline bool read(_ &x) {
    x = 0;
    _ f = 1;
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ch = getchar()) if(ch == '-') f *= -1;
    for(; (ch >= '0' && ch <= '9'); ch = getchar()) x = (x<<3)+(x<<1)+(ch^48);
    x *= f;
    if(ch == '\r') ch = getchar();
    return ch != untl && ch != EOF;
}

inline char getDg() {
    char ch = getchar();
    for(; !(ch >= '0' && ch <= '9'); ) ch = getchar();
    return ch;
}

inline char getLw() {
    char ch = getchar();
    for(; !(ch >= 'a' && ch <= 'z'); ) ch = getchar();
    return ch;
}

inline char getUp() {
    char ch = getchar();
    for(; !(ch >= 'A' && ch <= 'Z'); ) ch = getchar();
    return ch;
}

inline char getLtr() {
    char ch = getchar();
    for(; !((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')); ) ch = getchar();
    return ch;
}

inline char gc() {
    char ch = getchar();
    for(; ch == '\n' || ch == '\r' || ch == ' '; ) ch = getchar();
    return ch;
}

inline void write(_ x) {
    if(x < 0) {
        putchar('-');
        write(-x);
        return;
    }
    if(x > 9) write(x/10);
    putchar((x%10)^48);
    return;
}

inline void write(char const * a) {
    for(_ i = 0; a[i]; ++i) putchar(a[i]);
    return;
}

inline void clr() {
    putchar(10);
    return;
}

inline void spc() {
    putchar(32);
    return;
}

inline void writeln(_ x) { //pascal vibes
    write(x);
    clr();
    return;
}

inline void writeln(char const * a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writesc(_ x) {
    write(x);
    spc();
    return;
}

inline void writesc(char const * a) {
    write(a);
    spc();
    return;
}

inline void AC();
int main(int argc, char * argv[]) {

    //#define file_IO
#ifdef file_IO
    str fileN = "";
    freopen((fileN+".in").c_str(), "r", stdin);
    freopen((fileN+".out").c_str(), "w", stdout);
#endif
    
    #define multiple_testcases
#ifdef multiple_testcases
    _ tc = read();
    for(; tc--; ) AC(); // good luck!
#else
    AC(); // good luck!
#endif
    
    
    return 0;
}



// ----- End of Template -----



constant maxn = 2E5+8;

_ n, m, x, dp[maxn];
v_ ar, al, br, bl;
set<_> sn;

inline void AC() {
    
    n = read();
    m = read();
    ar.clear();
    al.clear();
    br.clear();
    bl.clear();
    for(_ i = 1; i <= n; ++i) {
        x = read();
        if(x < 0) al.push_back(-x);
        else ar.push_back(x);
    }
    for(_ i = 1; i <= m; ++i) {
        x = read();
        if(x < 0) bl.push_back(-x);
        else br.push_back(x);
    }
    if(!al.empty()) reverse(al.begin(), al.end());
    if(!bl.empty()) reverse(bl.begin(), bl.end());
    _ lmx = 0, rmx = 0;
    if(!al.empty() && !bl.empty()) {
        _ p = al.size()-1;
        dp[bl.size()] = 0;
        sn.clear();
        for(_ i = bl.size()-1; i >= 0; --i) {
            dp[i] = dp[i+1];
            for(; p >= 0 && al[p] > bl[i]; --p) if(sn.count(al[p])) ++dp[i];
            sn.insert(bl[i]);
        }
        lmx = dp[0];
        for(; p >= 0; --p) if(sn.count(al[p])) ++lmx;
        _ ca = 0;
        for(_ i = 0; i < bl.size(); ++i) {
            for(; ca < al.size() && al[ca] <= bl[i]; ) ++ca;
            lmx = max(lmx, dp[i]+(lower_bound(bl.begin(), bl.end(), bl[i])-lower_bound(bl.begin(), bl.end(), bl[i]-ca+1))+1);
        }
    }
    if(!ar.empty() && !br.empty()) {
        _ p = ar.size()-1;
        dp[br.size()] = 0;
        sn.clear();
        for(_ i = br.size()-1; i >= 0; --i) {
            dp[i] = dp[i+1];
            for(; p >= 0 && ar[p] > br[i]; --p) if(sn.count(ar[p])) ++dp[i];
            sn.insert(br[i]);
        }
        rmx = dp[0];
        for(; p >= 0; --p) if(sn.count(ar[p])) ++rmx;
        _ ca = 0;
        for(_ i = 0; i < br.size(); ++i) {
            for(; ca < ar.size() && ar[ca] <= br[i]; ) ++ca;
            rmx = max(rmx, dp[i]+(lower_bound(br.begin(), br.end(), br[i])-lower_bound(br.begin(), br.end(), br[i]-ca+1))+1);
        }
    }
    writeln(rmx+lmx);

    
    return;
}
/*
1
3 5
-1 1 2
-2 -1 1 2 5
 */