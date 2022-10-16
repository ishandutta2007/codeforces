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
using ll = long long;
const int MM = 2e5+5;

int n, m;
ll a[MM], b[MM];

int main(){
    scan(n, m);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        a[i] += a[i-1];
    }
    for(int i = 0; i < m; i++){
        ll v;
        scan(v);
        int id = upper_bound(a, a+n, v-1)-a-1;
        print(id+1, v-a[id]);
    }
    
    
    return 0;
}
/*
3 6
10 15 12
1 8 9 10 11
 */