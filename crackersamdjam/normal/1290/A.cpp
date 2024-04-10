#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 3502;

int t, n, m, k, a[MM];

int main(){
    scan(t);
    while(t--){
        scan(n, m, k);
        for(int i = 1; i <= n; i++)
            scan(a[i]);
        k = min(k, m-1);
        int ans = 0, len = n-k, rem = m-1-k;
        for(int l = 1; l+len-1 <= n; l++){
            int r = l+len-1;
            int v = 1e9;
            for(int ls = 0; ls <= rem; ls++){
                if(l+ls > r || r-(rem-ls) < l) continue;
                v = min(v, max(a[l+ls], a[r-(rem-ls)]));
            }
            //print(l, r, v, len, rem);
            ans = max(ans, v);
        }
        print(ans);
    }
    
    return 0;
}