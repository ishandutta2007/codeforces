#pragma GCC optimize("O3")
#pragma GCC target("sse4")

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
const int MM = 3e5+69;

mt19937 g1(time(0));
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}

int n, in[MM], a[MM], b[MM];
int *at = in+9;

int main(){
    scan(n);
    for(int i = 0; i < n; i++){
        scan(at[i]);
    }
    
    for(int i = 0; i < n; i++){
        b[i] = max(at[i], at[i+1]);
        a[i] = min(at[i], max(at[i+1], at[i-1]));
    }
    
    int aa = 0, bb = 0, m = (n-1)/2;
    int tb = n&1, ta = !tb;
    int d1 = 0, d2 = 0;
    
    for(int i = 0; i < n-1; i++){
        //rm how many
        if((n-i)&1){
            aa = max(aa, max(a[m-d1], a[m+d1+ta]));
            d1++;
            printf("%d ", aa);
        }
        else{
            bb = max(bb, max(b[m-d2-tb], b[m+d2]));
            d2++;
            printf("%d ", bb);
        }
    }
    print(*max_element(at, at+n));
    
    return 0;
    
    return 0;
}