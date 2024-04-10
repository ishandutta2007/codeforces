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


int main(){
    long long t, a, b, c, d, x, y, x1, y1, x2, y2;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>x>>y>>x1>>y1>>x2>>y2;
//        scan(a, b, c, d, x, y, x, y, x1, y1, x2, y2);
        b -= a, d -= c;
        bool bs = (x1 <= x and x <= x2 and y1 <= y and y <= y2);
        bs &= (x1 <= x+b and x+b <= x2 and y1 <= y+d and y+d <= y2);
        if(a || b)
            bs &= (x1 != x2);
        if(c || d)
            bs &= (y1 != y2);
        if(bs)
            puts("Yes");
        else
            puts("No");
    }
    
    return 0;
}