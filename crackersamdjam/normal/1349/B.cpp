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

int t, n, k, a[MM], b[MM];

int main(){
    scan(t);
    while(t--){
        scan(n, k);
        int ans = 0, f = 0, best = 1e9;
        for(int i = 1; i <= n; i++){
            scan(a[i]);
            if(a[i] == k)
                f = 1;

            if(a[i] < k)
                a[i] = -1;
            else
                a[i] = 1;
            b[i] = b[i-1]+a[i];
            if(i >= 2)
                best = min(best, b[i-2]); //bc seg len must > 1

            if(b[i] - best > 0)
                ans = 1;
        }
        
        if(n == 1 and a[1] > 0)
            ans = 1;

        puts(ans and f ?"yes":"no");
    }

    
    return 0;
}
/*
reqs:
k must be in arr
can always make smaller one at a time, so no worry about large eles
now for small, must have 1 more >= k then < k in a seg
let all a[i] >= k --> 1
all a[i] < k --> -1
find if contig seg of len > 1 has pos sum
ans if whether found
*/