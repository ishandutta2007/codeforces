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
const int MM = 1e5+5;

int n, m, q[MM], a[MM];
ll ans;

int main(){
    scan(n);
    for(int i = 0; i < n; i++)
        scan(q[i]);
    sort(q, q+n);
    int v = q[0];
    scan(m);
    for(int i = 0; i < m; i++)
        scan(a[i]);
    sort(a, a+m);
    int rem = 0, r = 0;
    for(int i = m-1; i >= 0; i--){
//        print(i, a[i], rem);
        if(rem){
            rem--;
        }
        else{
            for(int j = i; j > max(-1, i-v); j--)
                ans += a[j];
            i -= v-1;
            rem = 2;
        }
    }
    
    print(ans);
    
    return 0;
}