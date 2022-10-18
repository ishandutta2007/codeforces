/*
    author: DPair
    language: C++

    description:
    Duel!
*/
#include <bits/stdc++.h>
using namespace std;

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
int a[100005], b[15], cnt, tot[100005];
const int m = 6;
int n;

pair <int, int> c[1000005];

int main(){
    int T=1;
    // read(T);
    while(T --){
        for (register int i = 1;i <= m;i ++) read(b[i]);
        // sort(b + 1, b + m + 1);
        read(n);cnt = 0;int res = 0;
        for (register int i = 1;i <= n;i ++){
            read(a[i]);tot[i] = 0;
            for (register int j = 1;j <= m;j ++){
                c[++ cnt] = make_pair(a[i] - b[j], i);
            }
        }
        sort(c + 1, c + cnt + 1);
        int ans = 0x3f3f3f3f, it = 1;
        for (register int i = 1;i <= cnt;i ++){
            while(it <= cnt && res < n){
                if(!tot[c[it].second]) res ++;
                tot[c[it].second] ++;
                it ++;
            }
            if(res < n) break;
            chmin(ans, c[it - 1].first - c[i].first);
            -- tot[c[i].second];
            if(!tot[c[i].second]) res --;
        }
        fprint(ans, 10);
    }
}