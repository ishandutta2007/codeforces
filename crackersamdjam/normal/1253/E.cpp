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
const int MM = 3e5+5, MN = 82;

int n, m, x[MN], s[MN];
ll dp[MM];
//dp[i-k] <= dp[i]
//if late one is updated, all before should be as well

ll bit[MM];
void up(int i, ll v){
    for(i = MM-2-i; i < MM; i += i&-i)
        bit[i] = min(bit[i], v);
}
ll qu(int i){
    ll r = LLONG_MAX;
    for(i = MM-2-i; i; i -= i&-i)
        r = min(r, bit[i]);
    return r;
}

int main(){
    
    memset(bit, 0x3f, sizeof bit);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    
    scan(n, m);
    
    for(int i = 0; i < n; i++)
        scan(x[i], s[i]);
    
    for(int i = 1; i <= m; i++){
        int cov = 1;
        for(int j = 0; j < n; j++){
            if(x[j]+s[j] >= i && x[j]-s[j] <= i)
                cov = 0;
        }
        if(i > 1) dp[i] = min(dp[i], dp[i-1]+cov);
        if(i == 1 && !cov)
            dp[i] = 0;
        
        for(int j = 0; j < n; j++){
            int d = x[j]-s[j]-i;
            if(d <= 0) continue;
            
            int ed = x[j]+s[j]+d;
            ll nv = d+dp[i-1];
            //update
            up(ed, nv);
            //pc('t'); print(i, ed, nv);
        }
        
        dp[i] = min(dp[i], qu(i));
        
        //print(i, dp[i]);
    }
    
    print(dp[m]);
    
    return 0;
}