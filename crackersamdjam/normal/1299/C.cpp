#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using ld = long double;
const int MM = 1e6+5;

int n, q[MM], l, r;
ll a[MM], psa[MM];
ld out[MM];

ld val(int j, int i){
    return ld(psa[i]-psa[j])/ld(i-j);
}
bool cmp(int i, int j, int k){
    return (psa[j]-psa[i])*(k-i) > (psa[k]-psa[i])*(j-i);
    //if should merge (i, j] and (j, k] into (i, k]
}

int main(){
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        out[i] = a[i];
        psa[i] = a[i] + psa[i-1];
        while(l < r and cmp(q[r-1], q[r], i))
            r--;
        q[++r] = i;
    }
    for(int i = l; i <= r; i++){
        ld v = val(q[i-1], q[i]);
        for(int j = q[i-1]+1; j <= q[i]; j++)
            printf("%.9Lf\n", v);
    }
    
    return 0;
}