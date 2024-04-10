/*
    author: DPair
    language: C++

    description:
    DP
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 5005
template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}
template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int n, s, e;
LL x[MAXN], a[MAXN], b[MAXN], c[MAXN], d[MAXN];

inline LL work(int i, int j){
    if(i > j) return x[i] - x[j] + c[i] + b[j];
    else return x[j] - x[i] + d[i] + a[j];
}
inline void init(){
    for (register int i = 1;i <= n;i ++) read(x[i]);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    for (register int i = 1;i <= n;i ++) read(b[i]);
    for (register int i = 1;i <= n;i ++) read(c[i]);
    for (register int i = 1;i <= n;i ++) read(d[i]);
}
LL ans = 0;
int nxt[MAXN];
int main(){
    read(n);read(s);read(e);
    init();
    nxt[s] = e;
    ans = work(s, e);
    for (register int i = 1;i <= n;i ++){
        if(i == s || i == e) continue;
        int cur = s, pos = s;
        LL con = 0x3f3f3f3f3f3f3f3f;
        while(nxt[cur]){
            LL num = work(cur, i) + work(i, nxt[cur]) - work(cur, nxt[cur]);
            if(num < con){
                con = num;
                pos = cur;
            }
            cur = nxt[cur];
        }
        nxt[i] = nxt[pos];
        nxt[pos] = i;
        ans += con;
        // printf("i = %d, pos = %d, nxt = %d, con = %lld, work(pos, nxt) = %lld\n", i, pos, nxt[i], con, work(pos, nxt[i]));
    }
    fprint(ans, 10);
}