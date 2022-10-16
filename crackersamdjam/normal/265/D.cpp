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
const int MM = 1e5+2;

int n, a[MM];
ll dp[MM], ans;

int main(){
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        ll v = 0;
        vector<int> p;
        for(int j = 2; j*j <= a[i]; j++){
            if(a[i]%j == 0){
                v = max(v, dp[j]);
                p.push_back(j);
                while(a[i]%j == 0)
                    a[i] /= j;
            }
        }
        if(a[i] > 1){
            p.push_back(a[i]);
            v = max(v, dp[a[i]]);
        }
        v++;
        ans = max(ans, v);
        for(int j : p)
            dp[j] = v;
    }
    print(ans);
    
    return 0;
}