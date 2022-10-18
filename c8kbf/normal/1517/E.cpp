
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
//
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

#define pr(x, y) pair< x, y >
#define mp(x, y) make_pair(x, y)

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

inline void write(char ch) {
    putchar(ch);
    return;
}

inline void write(_p a, char const * b = " ") {
    write(a.first);
    write(b);
    write(a.second);
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

inline void writeln(char a) { //pascal vibes
    write(a);
    clr();
    return;
}

inline void writeln(_p a, char const * b = " ") {
    write(a, b);
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

inline void writesc(char a) {
    write(a);
    spc();
    return;
}

inline void writesc(_p a, char const * b = " ") {
    write(a);
    spc();
    return;
}

inline void AC();
int main(int argc, char * argv[]) {

//    #define file_IO
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
constant mod = 998244353;

_ n, a[maxn], p[maxn], b[maxn][2], s;

inline void AC() {
    
    n = read();
    for(_ i = 1; i <= n; ++i) {
        a[i] = read();
        p[i] = p[i-1]+a[i];
        b[i][0] = i & 1 ? b[i-1][0] : b[i-1][0]+a[i];
        b[i][1] = i & 1 ? b[i-1][1]+a[i] : b[i-1][1];
    }
    s = 1;
    for(_ i = 1; i <= n-1; ++i) if((p[n] & 1) || (p[i] != (p[n]>>1))) ++s;
    if(n >= 4) {
        _ cp = 0, cc = 0;
        for(_ i = 2; i <= n-2; ++i) {
            cp = a[1]+p[n-1]-p[i];
            cc = a[n]+p[i]-p[1];
            _ l = i, r = n-2, md, s = -1;
            for(; l <= r; ) {
                md = (l+r)>>1;
                if(cp-b[md][i&1]+b[i][i&1] > cc+b[md][i&1]-b[i][i&1]) {
                    s = md;
                    l = md+1;
                } else r = md-1;
            }
            if(~s) ::s = (::s+((s-i)>>1)+1)%mod;
        }
    }
    if(n >= 4) {
        _ cp = 0, cc = 0;
        for(_ i = 1; i <= n-2; ++i) {
            cp = p[n]-p[i];
            cc = p[i];
            _ l = i, r = n-1, md, s = -1;
            for(; l <= r; ) {
                md = (l+r)>>1;
                if(cp-b[md][i&1]+b[i][i&1] > cc+b[md][i&1]-b[i][i&1]) {
                    s = md;
                    l = md+1;
                } else r = md-1;
            }
            if(~s) ::s = (::s+((s-i)>>1))%mod;
        }
    }
    if(n >= 3) {
        _ cp = 0, cc = 0;
        for(_ i = 1; i <= n-2; ++i) {
            cp = p[n-1]-p[i];
            cc = a[n]+p[i];
            _ l = i, r = n-2, md, s = -1;
            for(; l <= r; ) {
                md = (l+r)>>1;
                if(cp-b[md][i&1]+b[i][i&1] > cc+b[md][i&1]-b[i][i&1]) {
                    s = md;
                    l = md+1;
                } else r = md-1;
            }
            if(~s) ::s = (::s+((s-i)>>1)+1)%mod;
        }
    }
    if(n >= 3) {
        _ cp = 0, cc = 0;
        for(_ i = 2; i <= n-1; ++i) {
            cp = a[1]+p[n]-p[i];
            cc = p[i]-p[1];
            _ l = i, r = n-1, md, s = -1;
            for(; l <= r; ) {
                md = (l+r)>>1;
                if(cp-b[md][i&1]+b[i][i&1] > cc+b[md][i&1]-b[i][i&1]) {
                    s = md;
                    l = md+1;
                } else r = md-1;
            }
            if(~s) ::s = (::s+((s-i)>>1)+1)%mod;
        }
    }
    writeln(s);
    
    return;
}