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
const int MM = 1e6+2;

int t, n;
char s[MM];
ll base = 131, mod = 1685518853;

bool check(int l, int r){
    while(l < r){
        if(s[l] != s[r])
            return 0;
        l++, r--;
    }
    return 1;
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        n = strlen(s);
        int l = 0, r = n-1;
        while(l < r and s[l] == s[r]){
            l++, r--;
        }
        //here loop both sides
        int ls = l-1, rs = r+1;
        for(int i = l; i <= r; i++){
            if(check(l, i))
                ls = i;
        }
        for(int i = r; i >= l; i--){
            if(check(i, r))
                rs = i;
        }
//        print(l, ls, rs, r);
        if(ls-l >= r-rs){
            for(int i = 0; i <= ls; i++)
                pc(s[i]);
            for(int i = r+1; i < n; i++)
                pc(s[i]);
            pc(10);
        }
        else{
            for(int i = 0; i < l; i++)
                pc(s[i]);
            for(int i = rs; i < n; i++)
                pc(s[i]);
            pc(10);
        }
    }
    
    
    return 0;
}