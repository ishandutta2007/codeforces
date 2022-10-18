#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
#define MOD 1000000007

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

struct Matrix{
    LL dat[105][105], row, column;
    inline void clear(int tmp1, int tmp2){
        row = tmp1, column = tmp2;
        memset(dat, 0, sizeof(dat));
    }
    inline void one(int tmp){
        clear(tmp, tmp);
        for (register int i = 0;i < tmp;i ++) dat[i][i] = 1;
    }
    inline Matrix operator * (const Matrix &b) const{
        Matrix ret;
        ret.clear(row, b.column);
        for (register int i = 0;i < row;i ++){
            for (register int k = 0;k < column;k ++){
                for (register int j = 0;j < b.column;j ++){
                    ret.dat[i][j] = (ret.dat[i][j] + dat[i][k] * b.dat[k][j]) % MOD;
                }
            }
        }
        return ret;
    }
    inline Matrix ksm(int y){
        Matrix ret, tmp;ret.one(row);
        tmp.row = row, tmp.column = column;
        memcpy(tmp.dat, dat, sizeof(tmp.dat));
        while(y){
            if(y & 1) ret = ret * tmp;
            tmp = tmp * tmp;
            y >>= 1;
        }
        return ret;
    }
}ans, ch;

int n, b, x, k;

int main(){
    read(n);read(b);read(k);read(x);
    ch.clear(x, x);ans.clear(1, x);
    for (register int i = 1;i <= n;i ++){
        int tmp;read(tmp);
        for (register int j = 0;j < x;j ++){
            ch.dat[j][((j * 10) + tmp) % x] ++;
        }
    }
    ans.dat[0][0] = 1;
    ans = ans * ch.ksm(b);
    fprint(ans.dat[0][k], 10);
    return 0;
}