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

int t, n;
ll a[MM];

int main(){
    
    scan(t);
    while(t--){
        vector<ll> s(3);
        scan(n);
        ll sum = 0, x = 0;
        for(int i = 0; i < n; i++){
            scan(a[i]);
            sum += a[i];
            x ^= a[i];
        }
        ll dif = sum-2*x;
        for(int i = 0; i < 60; i++){
            ll v = (1LL<<i);
            if(abs(dif)&v){
                s[0] |= v;
                dif -= v;
                if(x&v)
                    dif += 4*v;
            }
        }
        for(int i = 1; i < 60; i++){
            ll v = (1LL<<i), pre = (1LL<<(i-1));
            if(abs(dif)&v){
                //add the previous one
                s[1] |= pre;
                s[2] |= pre;
                dif += v;
            }
        }
        print(3);
        print(s[0], s[1], s[2]);
        
        //sum += s[0]+s[1]+s[2];
        //x ^= s[0]^s[1]^s[2];
        //print(sum, x*2);
    }
    
    return 0;
}