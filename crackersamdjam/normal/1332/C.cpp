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
const int MM = 2e5+5;

int t, n, k, cnt[MM][26];
char s[MM];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        int m = n/k;
        
        for(int i = 0; i <= n; i++){
            for(int j = 0; j < 26; j++)
                cnt[i][j] = 0;
        }
        
        for(int i = 0; i < n; i++){
            cnt[i%k][s[i]-'a']++;
        }
        int ans = 0;
        for(int i = 0; i <= k-1-i; i++){
            int minn = 1e9;
            for(int j = 0; j < 26; j++){
                minn = min(minn, m+m-cnt[i][j]-cnt[k-1-i][j]);
            }
            if(i == k-1-i)
                minn /= 2;
            ans += minn;
        }
        print(ans);
    }
    
    
    return 0;
}