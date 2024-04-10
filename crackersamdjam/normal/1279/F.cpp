#define ONLINE_JUDGE

#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
using ld = long double;
const int MM = 1e6+2;
const ld eps = 1e-9;

int n, k, d, cnt[MM], ans;
ld dp[MM];
char s[MM];

bool run(ld c){
    //printerr("c", c);
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i-1]+s[i];
        cnt[i] = cnt[i-1];
        int p = max(i-d, 0);
        if(make_pair(dp[p]+c, cnt[p]+1) < make_pair(dp[i], cnt[i])){
            dp[i] = dp[p]+c;
            cnt[i] = cnt[p]+1;
        }
    }
    //printerr("n", dp[n], cnt[n]);
    return cnt[n] <= k;
}

int main(){
    
    scan(n, k, d);
    for(int i = 1; i <= n; i++)
        s[i] = (gc <= 'Z');
    
    ld l = 0, m, r = n+2;
    while(r-l > eps){
        m = (l+r)/2;
        if(run(m))
            r = m;
        else
            l = m;
    }
    run(r);
    ans = round(dp[n]-r*k);
    
    for(int i = 1; i <= n; i++)
        s[i] ^= 1;
    
    l = 0, r = n+2;
    while(r-l > eps){
        m = (l+r)/2;
        if(run(m))
            r = m;
        else
            l = m;
    }
    run(r);
    ans = min(ans, (int)round(dp[n]-r*k));
    print(ans);
    
    return 0;
}