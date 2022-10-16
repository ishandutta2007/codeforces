#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using T = long long;
constexpr T mod = 1e9+7;

struct matrix{
    int n, m;
    vector<vector<T>> a;
    matrix(int _n = 0, int _m = 0){
        n = _n, m = _m;
        a.resize(n);
        for(int i = 0; i < n; i++)
            a[i].resize(m);
    }
};
matrix mul(matrix ma, matrix mb){
    matrix c(ma.n, mb.m);
    for(int i = 0; i < ma.n; i++){
        for(int j = 0; j < mb.m; j++){
            T t = 0;
            for(int k = 0; k < ma.m; k++)
                t = (t + ma.a[i][k] * mb.a[k][j]) % mod;
            c.a[i][j] = t;
        }
    }
    return c;
}

matrix fpow(matrix m, T exp){
    if(exp == 1)
        return m;
    matrix ret = fpow(m, exp/2);
    ret = mul(ret, ret);
    if(exp&1)
        ret = mul(ret, m);
    return ret;
}

T in[101];

int main(){
    int n; T k;
    scan(n, k);
    if(k == 1){
        return print(n), 0;
    }
    
    for(int i = 0; i < n; i++){
        scan(in[i]);
    }
    matrix a(n, n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            a.a[i][j] = (__builtin_popcountll(in[i]^in[j]) % 3 == 0);
        }
    }
    a = fpow(a, k-1);
    T res = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            res += a.a[i][j];
            res %= mod;
        }
    }
    
    print(res);
    
    return 0;
}