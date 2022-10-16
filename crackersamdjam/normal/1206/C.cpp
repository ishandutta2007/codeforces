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
const int MM = 1e6+2;

int n, a[MM];
set<ll> st;

int main(){
    
    scan(n);
    
    for(int i = 1, j = 1; i <= n; i++){
        if(i&1){
            a[i] = j;
            a[i+n] = j+1;
        }
        else{
            a[i] = j+1;
            a[i+n] = j;
        }
        j += 2;
    }
    
    for(int i = n*2+1; i <= n*4; i++)
        a[i] = a[i-n*2];
    
    ll sum = 0;
    for(int i = 1; i <= n*4; i++){
        sum += a[i];
        if(i >= n){
            sum -= a[i-n];
            st.insert(sum);
        }
    }
    
    if(st.size() > 2){
        puts("NO");
        return 0;
    }
    
    if(st.size() == 2 && ((*(++st.begin())) - *st.begin() > 1)){
        puts("NO");
        return 0;
    }
    
    puts("YES");
    
    for(int i = 1; i <= n*2; i++)
        printf("%d ", a[i]);
    
    return 0;
}