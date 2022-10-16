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
const int MM = 2002;
ll mod = 1e9+7;

void addmod(ll &a, ll b){
    a = (a+b)%mod;
}

ll dp[MM][MM];
int n, h, a[MM];

int main(){
    scan(n, h);
    
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        int k = h-a[i]; //need k segments
        if(k < 0) break;
    
        addmod(dp[i][k], dp[i-1][k]); //nothing
        if(k) addmod(dp[i][k-1], dp[i-1][k-1]*(k)); //open and close
        if(k) addmod(dp[i][k-1], (ll)dp[i-1][k]*k); //close
        if(k) addmod(dp[i][k], dp[i-1][k-1]); //open
    }
    
    print(dp[n][0]);
    
    return 0;
}