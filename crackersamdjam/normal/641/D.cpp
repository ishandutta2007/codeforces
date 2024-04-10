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
const int MM = 1e5+2;

int n;
ld a[MM], b[MM], c[MM], d[MM], C, D, X;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
        cin>>n;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    for(int i = 1; i <= n; i++)
        cin>>b[i];
    for(int i = 1; i <= n; i++){
        map<ld, int> mp;
        X = a[i] + b[i];
        C += c[i-1], D += d[i-1];
        
        ld ta = -1, tb = X-C+D, tc = X*C-a[i];
        ld delta = sqrtl(tb*tb - 4*ta*tc);
        ld v = (-tb + delta)/(2*ta);
        
        c[i] = max(ld(0), v);
        d[i] = max(ld(0), X-v);
    }
    c[n] = 1-accumulate(c+1, c+n, (ld)0);
    d[n] = 1-accumulate(d+1, d+n, (ld)0);
    
    cout<<fixed<<setprecision(10);
    for(int i = 1; i <= n; i++)
        cout<<c[i]<<' ';
    cout<<'\n';
    for(int i = 1; i <= n; i++)
        cout<<d[i]<<' ';
    cout<<'\n';
    
    return 0;
}