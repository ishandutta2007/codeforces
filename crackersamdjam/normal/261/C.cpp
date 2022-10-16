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
const int MM = 69;

ll n, t, ans, C[MM][MM];

int main(){
    
    scan(n, t);
    n++; //stupid input
    if(__builtin_popcountll(t) != 1){
        print(0);
        return 0;
    }
    ll tar = __lg(t)+1;
    
    C[0][0] = 1;
    for(int i = 1; i < MM; i++){
        C[i][0] = 1;
        for(int j = 1; j < MM; j++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    
    for(ll i = __lg(n); i >= 0 and tar >= 0; i--){
        if(n&(1LL<<i)){
            //don't take this, but take future ones
            ans += C[i][tar];
            
            //take this
            tar--;
        }
    }
    if(tar == 0)
        ans++;
    
    if(t == 1)
        ans--;
    
    print(ans);
    
    return 0;
}