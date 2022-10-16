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

vector<ll> x(1), y(1);
ll ax, ay, bx, by, sx, sy, t;

int main(){
    
    scan(x[0], y[0], ax, ay, bx, by, sx, sy, t);
    int n = 1;
    while(1){
        x.push_back(x[n-1]*ax+bx);
        y.push_back(y[n-1]*ay+by);
        if(x[n] > 2e16 or y[n] > 2e16)
            break;
        n++;
    }
    
    int ans = 0;
    for(int st = 0; st <= n; st++){
        ll rem = t;
        int cnt = 1;
        rem -= abs(sx - x[st]) + abs(sy - y[st]);
        if(rem < 0) continue;
        ans = max(ans, 1);
        for(int i = st-1; i >= 0; i--){
            ll dif = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
            rem -= dif;
            if(rem < 0)
                break;
            cnt++;
            ans = max(ans, cnt);
        }
        if(rem < 0) continue;
        for(int i = st+1; i <= n; i++){
            ll dif = (i == st+1 ? (abs(x[i] - x[0]) + abs(y[i] - y[0])) : (abs(x[i-1] - x[i]) + abs(y[i-1] - y[i])));
            rem -= dif;
            if(rem < 0)
                break;
            cnt++;
            ans = max(ans, cnt);
        }
    }
    
    print(ans);
    
    return 0;
}