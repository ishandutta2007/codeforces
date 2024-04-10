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

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

ll go(ll n, ll v){
//    print(n, v);
    if(v == 0){
        return 0;
    }
    if(n < v){
        return go(n, v/4);
    }
    n -= v;
    if(n < v){
        return 2*v+go(n, v/4);
    }
    n -= v;
    if(n < v){
        return 3*v+go(n, v/4);
    }
    n -= v;
    return v+go(n, v/4);
}


int main(){
//    freopen("in.txt", "r", stdin);
    int t;
    ll n;
    scan(t);
    while(t--){
        scan(n);
        ll l = log2(n)/log2(4);
        ll v = fpow(4, l, 1e18);
        ll ansa, ansb, ansc;
        
        ll ba = (n%3 == 1), bb = (n%3 == 2), bc = (n%3 == 0);
    
        ansa = v+(n-bb-bc-bc -v)/3;
        
//        if(n == 8)
//            puts("eeeeeee");
//        print(n, l, v, ansa);
        
        ansb = go(ansa-v, v) + v+v;
        
        ansc = ansa^ansb;
        
        if(n%3 == 1){
            print(ansa);
        }
        else if(n%3 == 2){
            print(ansb);
        }
        else{
            print(ansc);
        }
    }
    
    return 0;
}
/*
first is just group

second is 1 3 4 2 recursion
 */