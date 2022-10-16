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

int A, B, C, t;
ll a[MM], b[MM], c[MM], ans;

ll sq(ll x){
    return x*x;
}

void go(){
    //print(A, B, C);
    for(int i = 0; i < A; i++){
        ll j = lower_bound(b, b+B, a[i])-b;
        if(j < B){
            ll k = lower_bound(c, c+C, b[j])-c;
            if(k < C){
                ans = min(ans, sq(a[i]-b[j]) + sq(b[j]-c[k]) + sq(a[i]-c[k]));
            }
            k--;
            if(k >= 0){
                ans = min(ans, sq(a[i]-b[j]) + sq(b[j]-c[k]) + sq(a[i]-c[k]));
            }
        }
        j--;
        if(j >= 0){
            ll k = lower_bound(c, c+C, b[j])-c;
            if(k < C){
                ans = min(ans, sq(a[i]-b[j]) + sq(b[j]-c[k]) + sq(a[i]-c[k]));
            }
            k--;
            if(k >= 0){
                ans = min(ans, sq(a[i]-b[j]) + sq(b[j]-c[k]) + sq(a[i]-c[k]));
            }
        }
    }
}

int main(){
    scan(t);
    while(t--){
        ans = LLONG_MAX;
        scan(A, B, C);
        for(int i = 0; i < A; i++){
            scan(a[i]);
        }
        sort(a, a+A);
        for(int i = 0; i < B; i++)
            scan(b[i]);
        sort(b, b+B);
        for(int i = 0; i < C; i++)
            scan(c[i]);
        sort(c, c+C);
        
        go();
        swap(c, b);
        swap(C, B);
        go();
        swap(C, A);
        swap(c, a);
        go();
        swap(A, B);
        swap(a, b);
        go();
        swap(C, B);
        swap(c, b);
        go();
        swap(a, c);
        swap(A, C);
        go();
        
        
        print(ans);
    }
    
    
    return 0;
}