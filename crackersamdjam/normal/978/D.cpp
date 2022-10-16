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

int n, ans = 1e9;
ll a[MM], b[MM];

void go(int vv){
    
    int cnt = vv;
    ll dif = b[1] - b[0];
    for(int i = 2; i < n; i++){
        if(b[i]-b[i-1] == dif) continue;
        cnt++;
        b[i]++;
        if(b[i]-b[i-1] == dif) continue;
        b[i] -= 2;
        if(b[i]-b[i-1] == dif) continue;
        
        cnt = 1e9;
    }
    ans = min(ans, cnt);
    
    for(int i = 0; i < n; i++)
        b[i] = a[i];
}

int main(){
    scan(n);
    if(n == 2)
        ans = 0;
    for(int i = 0; i < n; i++){
        scan(a[i]);
        b[i] = a[i];
    }
    
    go(0);
    b[0]++;
    go(1);
    b[0]--;
    go(1);
    b[1]++;
    go(1);
    b[1]--;
    go(1);
    
    b[0]++, b[1]++;
    go(2);
    b[0]++, b[1]--;
    go(2);
    b[0]--, b[1]++;
    go(2);
    b[0]--, b[1]--;
    go(2);
    
    if(ans == 1e9)
        ans = -1;
    print(ans);
    
    
    return 0;
}