#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5;

char s[MM];
int n, q, psa[30][MM];

int main(){
    scanf("%s", s+1);
    n = strlen(s+1);
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < 30; j++)
            psa[j][i] = psa[j][i-1];
        psa[s[i]-'a'][i]++;
    }
    scanf("%d", &q);
    while(q--){
        int l, r, dif = 0;
        scanf("%d%d", &l, &r);
        for(int i = 0; i < 30; i++)
            dif += (psa[i][r] - psa[i][l-1] > 0);
        if(l == r || s[l] != s[r] || dif > 2){
            puts("Yes");
            // if more than 2 distinct
            continue;
        }
        puts("No");
    }
    
    return 0;
}