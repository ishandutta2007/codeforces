#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2;

int t,n;
long long a[MM];
pair<long long, int> suf[MM];

int main(){
    
    scan(t);
    while(t--){
        scan(n);
        for(int i = 0; i < n; i++){
            scan(a[i]);
            a[i] -= i;
        }
        suf[n] = {-1e10, -1};
        for(int i = n-1; i >= 0; i--)
            suf[i] = max(suf[i+1], {a[i], i});
        bool done = 0;
        for(int i = 0; i < n; i++){
            if(suf[i].first - a[i] > 0){
                done = 1;
                printf("YES\n%d %d\n", i+1, suf[i].second+1);
                break;
            }
        }
        for(int i = 0; i < n; i++)
            a[i] += i;
        reverse(a, a+n);
        for(int i = 0; i < n; i++)
            a[i] -= i;
        suf[n] = {-1e10, -1};
        for(int i = n-1; i >= 0; i--)
            suf[i] = max(suf[i+1], {a[i], i});
        for(int i = 0; i < n; i++){
            if(!done and suf[i].first - a[i] > 0){
                done = 1;
                printf("YES\n%d %d\n", n-suf[i].second, n-i);
                break;
            }
        }
        
        if(!done) puts("NO");
    }
    
    return 0;
}