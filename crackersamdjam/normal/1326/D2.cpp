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
const int MM = 2e6+5;

int t, n, d[MM];
char s[MM];

bool check2(int l, int r){
    int m = (l+r)/2;
    if(m+d[m] >= r)
        return 1;
    return 0;
}

int main(){
//    freopen("in.txt", "r", stdin);
    scanf("%d", &t);
    while(t--){
        scanf("%s", s+1);
        n = strlen(s+1);
        
        for(int i = n*2+2; i; i--){
            if(i&1)
                s[i] = s[i/2];
            else
                s[i] = '#';
        }
        s[1] = '@';
        n = n*2+2;
        
        for(int i = 2, mid = 0, r = 0; i <= n; i++){
            if(i <= r){
                d[i] = min(r-i, d[mid - (i-mid)]);
            }
            while(s[i+d[i]] == s[i-d[i]])
                d[i]++;
            d[i]--;
            if(i+d[i] > r){
                r = i+d[i];
                mid = i;
            }
        }
        /*
        for(int i = 2; i <= n; i++)
            pc(s[i]);
        pc(10);
        for(int i = 2; i <= n; i++)
            printf("%d ", d[i]);
        */
        
        int l = 3, r = n-1;
        while(l < r and s[l] == s[r]){
            l += 2, r -= 2;
        }
        //here loop both sides
        l -= 2, r += 2;
        int ls = l+1, rs = r-1;
        for(int i = l; i < r; i += 2){
            if(check2(l+1, i+1))
                ls = i;
        }
        for(int i = r; i > l; i -= 2){
            if(check2(i-1, r-1))
                rs = i;
        }
        //print(l, ls, rs, r, n);
        if(ls-l >= r-rs){
            for(int i = 3; i <= ls; i += 2)
                pc(s[i]);
            for(int i = r; i < n; i += 2)
                pc(s[i]);
            pc(10);
        }
        else{
            for(int i = 3; i <= l; i += 2)
                pc(s[i]);
            for(int i = rs; i < n; i += 2)
                pc(s[i]);
            pc(10);
        }
        
        for(int i = 0; i <= n; i++){
            s[i] = 0;
            d[i] = 0;
        }
    }
    fflush(stdout);
    
    return 0;
}