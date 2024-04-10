#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+2;
int t;
char s[MM];
int main(){
    scanf("%d",&t);
    while(t--){
        int n, x, cnt, mx, mn;
        scanf("%d %d %s", &n, &x, s);
        cnt = mx = mn = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '0')
                cnt++;
            else
                cnt--;
            mx = max(mx, cnt);
            mn = min(mn, cnt);
        }
        
        if(cnt == 0){
            if(x <= mx and x >= mn)
                puts("-1");
            else
                puts("0");
            continue;
        }
        
        int ans = 0, nv = 0;
        for(int i = 0; i < n; i++){
            int m = abs(cnt), eq = ((((nv % m)+m)%m) == ((x%m + m)%m));
            if(nv == x)
                ans++;
            else if(eq and ((x >= nv and cnt > 0) or (x < nv and cnt < 0)))
                ans++;
    
            if(s[i] == '0')
                nv++;
            else
                nv--;
        }
        print(ans);
    }
    
    
    return 0;
}