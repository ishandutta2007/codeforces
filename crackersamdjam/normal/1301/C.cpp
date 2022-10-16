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
using T = int;

int t, n, m;

T exgcd(T a, T b, T &x, T &y){
    if(a == 0){
        x = 0, y = 1;
        return b;
    }
    T x1, y1;
    T d = exgcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
    //freopen("in.txt", "r", stdin);
    scan(t);
    while(t--){
        scan(n, m);
        int non = n-m;
        if(m == 0){
            print(0);
            continue;
        }
        if(non == 0){
            print((ll)n*(n+1)/2);
            continue;
        }
        int f = non/(m+1), s = (non+m)/(m+1), x, y;
        if(f == s){
            x = non/f, y = 0;
        }
        else{
            int ex = non-f*(m+1);
            x = m+1-ex, y = ex;
        }
        //print(f, x, s, y);
        ll ans = (ll)n*(n+1)/2;
        //print((ll)n*(n+1)/2, -(ll)f*(f+1)/2*x, -(ll)s*(s+1)/2*y);
        ans -= (ll)f*(f+1)/2*x;
        ans -= (ll)s*(s+1)/2*y;
        print(ans);
    }
    
    return 0;
}