#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
using namespace std;

int t, q;
ll a, b, l, r, ff;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}

int main(){
    
    scan(t);
    while(t--){
        scan(a, b, q);
        if(a < b){
            ll c = a;
            a = b;
            b = c;
        }
        ff = a/gcd(a, b)*b;
        while(q--){
            scan(l, r);
            l--;
            ll diva = l/ff, divb = r/ff;
            l -= diva*ff, r -= divb*ff;
            
            ll ans = (divb-diva)*(ff-a) - max(0LL, l+1-a) + max(0LL, r+1-a);
            
            printn(ans);
            pc(32);
        }
        pc(10);
    }
    
    return 0;
}
/*
1
4 6 10
6 18
5 17
7 18
11 23
11 24
11 25
12 23
12 24
12 25
 
 */