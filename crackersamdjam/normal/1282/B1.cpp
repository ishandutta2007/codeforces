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
const int MM = 2e5+2;

int t, n, p, k;
ll a[MM], psa[MM];

int main(){
    
    scan(t);
    while(t--){
        int ans = 0;
        scan(n, p, k);
        for(int i = 0; i < n; i++)
            scan(a[i]);
        sort(a, a+n);
        for(int i = 0; i < k-1; i++){
            psa[i] = a[i];
            if(i) psa[i] += psa[i-1];
            if(psa[i] <= p)
                ans = i+1;
        }
        
        psa[k-1] = a[k-1];
        if(psa[k-1] <= p)
            ans = k;
        
        for(int i = k; i < n; i++){
            psa[i] = a[i];
            psa[i] += psa[i-k];
            if(psa[i] <= p)
                ans = max(ans, i+1);
        }
        print(ans);
    }
    
    return 0;
}