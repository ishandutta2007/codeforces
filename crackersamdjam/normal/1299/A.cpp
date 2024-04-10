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
const int MM = 1e5+2;

int n, cnt[33], id;
ll a[MM], best;

int main(){
    scan(n);
    for(int i = 0; i < n; i++){
        scan(a[i]);
        for(int j = 0; j < 32; j++){
            if(a[i]&(1LL<<j))
                cnt[j]++;
        }
    }
    for(int i = 0; i < n; i++){
        ll v = 0;
        for(int j = 0; j < 32; j++){
            if(a[i]&(1LL<<j)){
                if(cnt[j] < 2)
                    v += (1LL<<j);
            }
        }
        if(v > best){
            best = v;
            id = i;
        }
    }
    printf("%lld ", a[id]);
    for(int i = 0; i < n; i++){
        if(i != id)
            printf("%lld ", a[i]);
    }
    
    return 0;
}