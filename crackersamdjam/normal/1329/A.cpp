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

int n, m, a[MM];
ll sum;

int main(){
    scan(n, m);
    for(int i = 0; i < m; i++){
        scan(a[i]);
        sum += a[i];
    }
    if(sum < n or m-1+a[m-1] > n)
        return print(-1), 0;
    
    vector<int> v;
    int nx = n;
    for(int i = m-1; i >= 0; i--){
        int at = nx;
        int len = a[i];
        a[i]--;
        while(at+len-1 > n){
            at--;
            a[i]--;
        }
        while(a[i] and at > i+1){ //enough space for rest
            a[i]--;
            at--;
        }
        v.push_back(at);
        nx = at-1;
    }
    if(nx != 0)
        return print(-1), 0;
    
    reverse(all(v));
    for(int i: v)
        printf("%d ", i);
    
    return 0;
}