#include <bits/stdc++.h>
using namespace std;
#define int long long
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

int pohai_hang, pohai_lie;
int n, m, k, p;
int sig_hang[1005], sig_lie[1005], ans_hang[1000005], ans_lie[1000005];
int a[1005][1005];
priority_queue <int> hang, lie;
signed main(){
    read(n);read(m);read(k);read(p);
    for (register int i = 1;i <= n;i ++){
        for (register int j = 1;j <= m;j ++){
            read(a[i][j]);
            sig_hang[i] += a[i][j];
            sig_lie[j] += a[i][j];
        }
    }
    int ans = -0x3f3f3f3f3f3f3f3f;
    for (register int i = 1;i <= n;i ++) hang.push(sig_hang[i]);
    for (register int j = 1;j <= m;j ++) lie.push(sig_lie[j]);
    for (register int i = 1;i <= k;i ++){
        int tmp_hang = hang.top(), tmp_lie = lie.top();
        hang.pop();lie.pop();
        hang.push(tmp_hang - p * m);lie.push(tmp_lie - p * n);
        ans_hang[i] = ans_hang[i - 1] + tmp_hang;
        ans_lie[i] = ans_lie[i - 1] + tmp_lie;
    }
    for (register int i = 0;i <= k;i ++) chmax(ans, ans_hang[i] + ans_lie[k - i] - i * (k - i) * p);
    fprint(ans, 10);
}