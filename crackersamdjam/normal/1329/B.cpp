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

ll cnt[64], dp[64];
ll t, d, m;

int main(){
    scan(t);
    while(t--){
        memset(cnt, 0, sizeof cnt);
        memset(dp, 0, sizeof dp);
        scan(d, m);
        for(int i = 0,pre=0; i <= 30; i++){
            cnt[i] = (1<<i)%m;
            if((1<<(i+1)) > d){
                cnt[i] -= (1<<(i+1))-1-d;
                cnt[i] = (cnt[i]%m+m)%m;
                break;
            }
            pre = (1<<i);
        }
        dp[0] = cnt[0];
        ll ans = dp[0];
        ll dpsum = dp[0];
        for(int i = 1; i <= 30; i++){
            dp[i] = (dpsum + 1)*cnt[i]%m;
            //prev, 0, current
            dpsum = (dpsum + dp[i])%m;
            ans = (ans + dp[i])%m;
        }
        print(ans);
        
//        for(int i = 0; i < 5; i++)
//            print(i, cnt[i], dp[i]);
    }
    
    
    return 0;
}