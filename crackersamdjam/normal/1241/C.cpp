#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5+2;

int q, n, a[MM];
ll x, xa, y, yb, k;

bool test(int m){
    ll gcd = xa/__gcd(xa, yb)*yb;
    ll both = m/gcd;
    ll sum = 0;
    int id = 1;
    for(int i = 0; i < both; i++)
        sum += a[id++]*(x+y);
    
    ll first = m/xa;
    for(int i = 0; i < first-both; i++){
        sum += a[id++]*x;
    }
    
    ll second = m/yb;
    for(int i = 0; i < second-both; i++)
        sum += a[id++]*y;
    
    //assert(first + second - both <= n);
    
    return sum >= k;
}

int main(){
    
    scan(q);
    
    while(q--){
    
        scan(n);
        
        for(int i = 1; i <= n; i++){
            scan(a[i]);
            a[i] /= 100;
        }
        
        sort(a+1, a+1+n, greater<int>());
        
        scan(x, xa, y, yb, k);
        
        if(x < y){
            swap(x, y);
            swap(xa, yb);
            //so x is always larger
        }
        
        int l = 1, m, r = n;
        while(l <= r){
            m = (l+r)/2;
            if(test(m))
                r = m-1;
            else
                l = m+1;
        }
        
        if(l == n+1)
            puts("-1");
        else
            print(l);
    }
    
    return 0;
}