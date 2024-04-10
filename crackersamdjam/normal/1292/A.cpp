#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+5;

int n, q, a[2][MM];
set<int> both, one[2];

int main(){
    
    scan(n, q);
    
    for(int i = 0,r,c; i < q; i++){
        scan(r, c);
        r--;
        if(!a[r][c]){
            a[r][c] = 1;
            if(a[!r][c])
                both.insert(c);
            if(a[!r][c+1])
                one[r].insert(c);
            if(a[!r][c-1])
                one[!r].insert(c-1);
        }
        else{
            a[r][c] = 0;
            if(a[!r][c])
                both.erase(c);
            if(a[!r][c+1])
                one[r].erase(c);
            if(a[!r][c-1])
                one[!r].erase(c-1);
        }
        if(both.size() + one[0].size() + one[1].size())
            puts("No");
        else
            puts("Yes");
    }
    
    return 0;
}