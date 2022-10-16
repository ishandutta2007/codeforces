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
const int MM = 1e5+5;

int t, n, a[MM], b[MM];

int main(){
    scan(t);
    while(t--){
        scan(n);
        for(int i = 0; i < n; i++){
            scan(a[i]);
        }
        for(int j = 0; j < n; j++){
            scan(b[j]);
        }
        int l = 0;
        while(l < n and a[l] == b[l])
            l++;
        if(l == n){
            puts("YES");
            continue;
        }
        bool hi = 0, lo = 0;
        for(int i = n-1; i >= 0; i--){
            if(a[i] == 1)
                lo = 0;
            else if(a[i] == -1)
                hi = 0;
            
            if(i >= l){
                if(a[i] > b[i])
                    hi = 1;
                else if(a[i] < b[i])
                    lo = 1;
            }
        }
//        print(l, lo, hi);
        if(lo or hi)
            puts("NO");
        else
            puts("YES");
    }
    
    
    return 0;
}