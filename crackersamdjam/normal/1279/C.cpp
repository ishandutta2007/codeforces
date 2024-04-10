#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+5;

int t, n, m, a[MM], at[MM], bit[MM];

void up(int i, int v){
    for(i++; i < n+5; i += i&-i)
        bit[i] += v;
}
int q(int i){
    int r = 0;
    for(i++; i; i -= i&-i)
        r += bit[i];
    return r;
}

int main(){
    scan(t);
    while(t--){
        long long ans = 0;
        int low = 0;
        scan(n, m);
        for(int i = 0; i < n; i++){
            scan(a[i]);
            at[a[i]] = i;
            up(i, 1);
        }
        for(int i = 0,b; i < m; i++){
            scan(b);
            up(at[b], -1);
            ans++;
            if(at[b] > low){
                ans += 2*q(at[b]);
                low = at[b];
            }
        }
        print(ans);
        for(int i = 0; i <= n+5; i++)
            bit[i] = 0;
    }
    
    return 0;
}