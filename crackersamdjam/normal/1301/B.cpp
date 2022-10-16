#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+2;
int t, n, a[MM], b[MM];

int go(int k){
    int ret = 0;
    for(int i = 0; i < n; i++){
        b[i] = a[i];
        if(b[i] == -1)
            b[i] = k;
        if(i) ret = max(ret, abs(b[i]-b[i-1]));
    }
    return ret;
}

int main(){
    scan(t);
    while(t--){
        scan(n);
        for(int i = 0; i < n; i++)
            scan(a[i]);
        
        int l = 0, m, r = 1e9;
        while(l <= r){
            m = (l+r)/2;
            if(go(m) < go(m+1))
                r = m-1;
            else
                l = m+1;
        }
        print(go(l), min(l, (int)1e9));
    }
    
    
    return 0;
}