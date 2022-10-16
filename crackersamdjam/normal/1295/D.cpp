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
const int MM = 1e5+1;
int t;
ll a, m;
bool np[MM];
vector<ll> prime;
int main(){
    
    for(int i = 2; i < MM; i++){
        if(np[i])
            continue;
        prime.emplace_back(i);
        for(int j = i; j < MM; j += i)
            np[j] = 1;
    }
    
    scan(t);
    while(t--){
        scan(a, m);
        ll v = __gcd(a, m);
        a /= v;
        m /= v;
        ll phi = m, rem = m;
        for(auto i: prime){
            if(i*i > m)
                break;
            if(m % i == 0){
                phi -= phi/i;
                while(rem % i == 0)
                    rem /= i;
            }
        }
        if(rem > 1)
            phi -= phi/rem;
        print(phi);
    }
    
    return 0;
}