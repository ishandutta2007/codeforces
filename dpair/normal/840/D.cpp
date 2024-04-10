#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
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

namespace My_Rand{
    int index, MT[624];
    inline void srand(int seed){
        index = 0;
        MT[0] = seed;
        for (register int i = 1;i < 624;i ++){
            int t = 1812433253 * (MT[i - 1] ^ (MT[i - 1] >> 30)) + i;
            MT[i] = t & 0xffffffff;
        }
    }
    inline void rotate(){
        for (register int i = 0;i < 624;i ++){
            int tmp = (MT[i] & 0x80000000) + (MT[(i + 1) % 624] & 0x7fffffff);
            MT[i] = MT[(i + 397) % 624] ^ (tmp >> 1);
            if(tmp & 1) MT[i] ^= 2567483615;
        }
    }
    inline int rand(){
        if(!index) rotate();
        int ret = MT[index];
        ret = ret ^ (ret >> 11);
        ret = ret ^ ((ret << 7) & 2636928640);
        ret = ret ^ ((ret << 15) & 4022730752);
        ret = ret ^ (ret >> 18);
        index = (index + 1) % 624;
        return ret;
    }
} // namespace My_Rand

int n, m;
const int block = 500;
int a[300005];

inline int idb(int x){return (x / block);}

struct QUEST{
    int l, r, k;
    int id;
    inline bool operator <(const QUEST &tmp) const{
        return (idb(l) ^ idb(tmp.l)) ?(l > tmp.l) : ((idb(l) & 1)? r < tmp.r : r > tmp.r);
    }
}q[300005];

int ans, cnt[300005];
int ret[300005];

int main(){
    My_Rand :: srand(time(NULL));
    read(n);read(m);
    for (register int i = 1;i <= n;++ i) read(a[i]);
    for (register int i = 1;i <= m;++ i) {read(q[i].l);read(q[i].r);read(q[i].k);q[i].id = i;}
    sort(q + 1, q + m + 1);
    int l = q[1].l, r = l - 1;
    for (register int i = 1;i <= m;++ i){
        while(l > q[i].l) cnt[a[-- l]] ++;
        while(r < q[i].r) cnt[a[++ r]] ++;
        while(l < q[i].l) cnt[a[l ++]] --;
        while(r > q[i].r) cnt[a[r --]] --;
        int TIM = 200;
        ans = -1;
        while(TIM --){
            int x = My_Rand :: rand() % (r - l + 1) + l;
            if(cnt[a[x]] > ((r - l + 1) / q[i].k)){
                if(~ans) chmin(ans, a[x]);
                else ans = a[x];
            }
        }
        ret[q[i].id] = ans;
    }
    for (register int i = 1;i <= m;++ i) {fprint(ret[i], 10);}
    return 0;
}