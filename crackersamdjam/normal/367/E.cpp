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
const int MM = 340;
ll mod = 1e9+7;

void addmod(ll &a, ll b){
    a = (a+b)%mod;
}

int n, m, x;
ll dp[2][MM][MM];
// total open, total closed intervals

int main(){
   scan(n, m, x);
   if(n > m)
       return print(0), 0;
   
   int cur = 1, pre = 0;
   dp[cur][0][0] = 1;
   for(int z = 1; z <= m; z++){
       swap(cur, pre);
       for(int k = 0; k <= min(z, n); k++){
           for(int i = 0; i <= min(z, n); i++){
               if(z != x) dp[cur][i][k] = dp[pre][i][k]; //nothing
               else dp[cur][i][k] = 0;
               if(i) addmod(dp[cur][i][k], dp[pre][i-1][k]); //open
               if(k and z != x) addmod(dp[cur][i][k], dp[pre][i+1][k-1]); //close (last one)
               if(k) addmod(dp[cur][i][k], dp[pre][i][k-1]); //open and close
           }
       }
   }
   
   ll f = 1;
   for(int i = 1; i <= n; i++)
       f = f*i%mod;
   
   print(dp[cur][0][n]*f%mod);
    
    return 0;
}