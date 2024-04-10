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
#define MOD 1000000007
struct Matrix{
    int row, column;
    LL dat[105][105];
    inline void clear(int tmp1, int tmp2){
        memset(dat, 0, sizeof(dat));
        row = tmp1, column = tmp2;
    }
    inline void one(int tmp){
        clear(tmp, tmp);
        for (register int i = 0;i < tmp;i ++) dat[i][i] = 1;
    }
    inline Matrix operator * (const Matrix &b) const{
        Matrix c;c.clear(row, b.column);
        for (register int i = 0;i < row;i ++){
            for (register int k = 0;k < column;k ++){
                for (register int j = 0;j < b.column;j ++){
                    c.dat[i][j] = (c.dat[i][j] + dat[i][k] * b.dat[k][j]) % MOD;
                }
            }
        }
        return c;
    }
    inline Matrix ksm(int k){
        Matrix ret, tmp;ret.one(row);tmp.row = row;tmp.column = column;
        memcpy(tmp.dat, dat, sizeof(tmp.dat));
        while(k){
            if(k & 1) ret = ret * tmp;
            tmp = tmp * tmp;
            k >>= 1;
        }
        return ret;
    }
}ans, ch;
int n, l;
LL m, a[1000005], b[1000005], c[1000005];
int main(){
    read(n);read(l);read(m);l -= 2;
    ans.clear(1, m);ch.clear(m, m);
    for (register int i = 1;i <= n;i ++){
        read(a[i]);a[i] %= m;
        ans.dat[0][a[i]] ++;
    }
    for (register int i = 1;i <= n;i ++){
        read(b[i]);b[i] %= m;
        for (register int j = 0;j < m;j ++){
            ch.dat[j][(j + b[i]) % m] ++;
        }
    }
    ans = ans * ch.ksm(l);
    LL res = 0;
    for (register int i = 1;i <= n;i ++){
        read(c[i]);c[i] += b[i];c[i] %= m;
        res = (res + ans.dat[0][(m - c[i]) % m]) % MOD;
    }
    fprint(res, 10);
    return 0;
}