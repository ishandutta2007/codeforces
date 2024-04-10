#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, a[102], dp[102][102][2];
//number of odd

int main(){
    
    memset(dp, 0x3f, sizeof dp);
    scan(n);
    for(int i = 0; i < n; i++)
        scan(a[i]);
    if(!a[0]){
        dp[0][0][0] = dp[0][1][1] = 0;
    }
    else{
        int v = a[0]&1;
        dp[0][v][v] = 0;
    }
    
    for(int i = 1; i < n; i++){
        if(a[i] % 2 == 0){
            for(int j = 0; j <= n; j++){
                dp[i][j][0] = min(dp[i][j][0], min(dp[i-1][j][0], dp[i-1][j][1]+1));
            }
        }
        if(a[i] % 2 == 1 or a[i] == 0){
            for(int j = 1; j <= n; j++){
                dp[i][j][1] = min(dp[i][j][1], min(dp[i-1][j-1][1], dp[i-1][j-1][0]+1));
            }
        }
    }
    
    print(min(dp[n-1][(n+1)/2][0], dp[n-1][(n+1)/2][1]));
    
    return 0;
}