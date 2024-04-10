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

#define i(x) x::iterator

using namespace std;

//weirdest typedefs ever??
typedef long long _;
typedef double _D;
typedef unsigned long long u_;
typedef string str;
typedef pair<_, _> _p;
typedef vector<_> v_;
typedef const long long constant;

const char untl = '\n';

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
    str fileN = "puzzle";
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

_ n, m, a[maxn], lg2[maxn], mn[31][maxn], gd[31][maxn], f[maxn], lt[maxn], rt[maxn], s;
set<_p> st;
set<_> sw;

inline _ rggd(_ l, _ r);
inline _ rgmn(_ l, _ r);
inline _ find(_ x);
inline _ gcd(_ a, _ b);
inline void AC() {
    
    st.clear();
    sw.clear();
    s = 0;
    
    n = read();
    m = read();
    for(_ i = 1; i <= n; ++i) {
        a[i] = read();
        st.insert(make_pair(a[i], i));
        f[i] = lt[i] = rt[i] = i;
    }
    for(_ i = 2; i <= n; ++i) lg2[i] = lg2[i>>1]+1;
    for(_ i = 1; i <= n; ++i) mn[0][i] = gd[0][i] = a[i];
    for(_ i = 1; i <= lg2[n]; ++i) for(_ j = 1; j+(1<<i)-1 <= n; ++j) {
        mn[i][j] = min(mn[i-1][j], mn[i-1][j+(1<<(i-1))]);
        gd[i][j] = gcd(gd[i-1][j], gd[i-1][j+(1<<(i-1))]);
    }
    for(_p i : st) {
        if(i.first >= m) break;
        for(_ l = lt[find(i.second)]; l > 1; l = lt[find(i.second)]) {
            if(rggd(l-1, i.second) != rgmn(l-1, i.second)) break;
            lt[find(i.second)] = min(lt[find(i.second)], lt[find(l-1)]);
            f[find(l-1)] = find(i.second);
            s += rgmn(l-1, i.second);
        }
        for(_ r = rt[find(i.second)]; r < n; r = rt[find(i.second)]) {
            if(rggd(i.second, r+1) != rgmn(i.second, r+1)) break;
            rt[find(i.second)] = max(rt[find(i.second)], rt[find(r+1)]);
            f[find(r+1)] = find(i.second);
            s += rgmn(i.second, r+1);
        }
    }
    for(_ i = 1; i <= n; ++i) sw.insert(find(i));
    writeln((sw.size()-1)*m+s);
    
    return;
}

inline _ gcd(_ a, _ b) {
    return !b ? a : gcd(b, a%b);
}

inline _ find(_ x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

inline _ rgmn(_ l, _ r) {
    return min(mn[lg2[r-l+1]][l], mn[lg2[r-l+1]][r-(1<<lg2[r-l+1])+1]);
}

inline _ rggd(_ l, _ r) {
    return gcd(gd[lg2[r-l+1]][l], gd[lg2[r-l+1]][r-(1<<lg2[r-l+1])+1]);
}

/*
1
4 5
5 2 4 9
*/
/*
1
8 8
5 3 3 6 10 100 9 15
*/