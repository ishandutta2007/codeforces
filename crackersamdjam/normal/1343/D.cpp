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
const int MM = 4e5+5;

int t, n, k, a[MM], cnt[MM], lo[MM], hi[MM];

int main(){
    scan(t);
    while(t--){
        scan(n, k);
        for(int i = 0; i < n; i++){
            scan(a[i]);
        }
        for(int i = 0; i < n/2; i++){
            lo[max(a[i], a[n-1-i])]++;
            hi[min(a[i], a[n-1-i])]++;
            cnt[a[i] + a[n-1-i]]++;
        }
        int ans = n;
        for(int i = 1; i <= 2*k; i++){
            lo[i] += lo[i-1];
        }
        for(int i = 2*k-1; i >= 0; i--){
            hi[i] += hi[i+1];
        }
        for(int i = 1; i <= 2*k; i++){
            int v = n/2 - cnt[i];
            if(i-k-1 > 0)
                v += lo[i-k-1];
            v += hi[i];
            
            ans = min(ans, v);
        }
        print(ans);
        
        for(int i = 0; i <= 2*k; i++){
            cnt[i] = lo[i] = hi[i] = 0;
        }
    }
    
    
    return 0;
}