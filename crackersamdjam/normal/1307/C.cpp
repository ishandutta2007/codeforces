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

char s[MM];
int n;
long long ans, psa[130], cnt[130][130];

int main(){
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n; i++){
        s[i] -= 'a';
        psa[s[i]]++;
        for(int j = 0; j < 27; j++){
            if(s[i] != j)
                cnt[s[i]][j] += psa[j];
        }
    }
    for(int i = 0; i < 27; i++){
        ans = max(ans, psa[i]*(psa[i]-1)/2);
        ans = max(ans, psa[i]);
        for(int j = 0; j < 27; j++){
            ans = max(ans, cnt[i][j]);
        }
    }
    print(ans);
    
    return 0;
}