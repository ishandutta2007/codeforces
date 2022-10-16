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
const int MM = 3005;
const ll mod = 998244353;

void addmod(ll &a, ll b){
    a += b;
    if(a >= mod)
        a -= mod;
}

char s[MM], t[MM];
int n, m;

ll dp[MM][MM];


int main(){
    scanf("%s %s", s+1, t+1);
    n = strlen(s+1);
    m = strlen(t+1);
    
    for(int i = 1; i <= n; i++){
        if(s[1] == t[i] || i > m)
            dp[i][i] = 2;
    }
    
    for(int len = 1; len <= n; len++){
        for(int l = 1; l+len-1 <= n; l++){
            int r = l+len-1;
            if(s[len+1] == t[l-1] || l-1 > m)
                addmod(dp[l-1][r], dp[l][r]);
            if(s[len+1] == t[r+1] || r+1 > m)
                addmod(dp[l][r+1], dp[l][r]);
        }
    }
    
    ll ans = 0;
    for(int i = m; i <= n; i++){
        addmod(ans, dp[1][i]);
    }
    
    print(ans);
    
    
    return 0;
}