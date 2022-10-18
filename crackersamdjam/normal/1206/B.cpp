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

int n, pos, zero, neg;
ll ans;

int main(){
    
    scan(n);
    
    for(int i = 0,a; i < n; i++){
        scan(a);
        if(a == 0)
            zero++;
        else if(a > 0){
            ans += a-1;
            pos++;
        }
        else{
            ans += -a-1;
            neg++;
        }
    }
    
    neg %= 2;
    
    if(neg == 1){
        if(zero){
            zero--;
            ans++;
        }
        else{
            neg--;
            ans += 2;
        }
    }
    
    ans += zero;
    
    print(ans);
    
    return 0;
}