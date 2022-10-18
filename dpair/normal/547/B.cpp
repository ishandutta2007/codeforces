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

template <typename T>
inline T mn(T x, T y) {return x < y ? x : y;}
template <typename T>
inline T mx(T x, T y) {return x > y ? x : y;}
template <typename T>
inline void chmin(T &x, T y) {(x > y) && (x = y);}
template <typename T>
inline void chmax(T &x, T y) {(x < y) && (x = y);}

int l[200005], r[200005];
int n, a[200005];
inline void work(){
    stack <int> s;
    s.push(0);
    for (register int i = 1;i <= n + 1;i ++){
        while(a[i] < a[s.top()]){
            r[s.top()] = i;
            s.pop();
        }
        l[i] = s.top();
        s.push(i);
    }
}

struct DPair{
    int val, cnt;
    inline bool operator < (const DPair &tmp) const{
        return cnt > tmp.cnt || (cnt == tmp.cnt && val > tmp.val);
    }
}c[200005];

int ret[200005];

int it = 1, cur;

int main(){
    read(n);
    for (register int i = 1;i <= n;i ++) read(a[i]);
    work();
    for (register int i = 1;i <= n;i ++){
        c[i].val = a[i];c[i].cnt = r[i] - l[i] - 1;
    }
    sort(c + 1, c + n + 1);
    for (register int i = n;i >= 1;i --){
        while(c[it].cnt >= i){
            chmax(cur, c[it].val);
            it ++;
        }
        ret[i] = cur;
    }
    for (register int i = 1;i <= n;i ++) fprint(ret[i], 32);
    putchar(10);return 0;
}