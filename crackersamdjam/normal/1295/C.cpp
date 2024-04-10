#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+9;

int tc, n, m;
char s[MM], t[MM];
vector<int> cnt[30];

int main(){
    scanf("%d", &tc);
    while(tc--){
        scanf("%s %s", s, t);
        for(int i = 0; i < 30; i++)
            cnt[i].clear();
        n = strlen(s), m = strlen(t);
        for(int i = 0; i < n; i++){
            cnt[s[i]-'a'].emplace_back(i);
        }
        int ans = 1, at = 0;
        for(int i = 0; i < m; i++){
            char cur = t[i]-'a';
            if(cnt[cur].empty()){
                ans = -1;
                break;
            }
            auto ptr = lower_bound(cnt[cur].begin(), cnt[cur].end(), at);
            if(ptr == cnt[cur].end()){
                ans++;
                at = cnt[cur][0]+1;
            }
            else{
                at = (*ptr)+1;
            }
        }
        print(ans);
    }
    
    return 0;
}