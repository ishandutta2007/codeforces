#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 305;

int n, cnta;
char s[MM], ans[MM];

int out(char arr[MM]){
    for(int i = 0; i < n; i++)
        pc(arr[i]);
    pc(10);
    fflush(stdout);
    return 0;
}

int ask(int j){
    for(int i = 0; i < n; i++)
        pc(s[i] = 'a' + (i==j));
    pc(10);
    fflush(stdout);
    
    int r;
    scanf("%d", &r);
    if(!r) out(s);
    return r;
}

int main(){
    
    printf("a\n");
    fflush(stdout);
    scanf("%d", &n);
    
    if(n == 300){
        for(int i = 0; i < n; i++)
            ans[i] = 'b';
        return out(ans);
    }
    
    n++;
    int cnt = ask(n);
    if(!cnt) return 0;
    if(cnt == n){
        n--;
        for(int i = 0; i < n; i++)
            ans[i] = 'b';
        return out(ans);
    }
    
    for(int i = 0; i < n; i++)
    
        ans[i] = 'a';
    
    for(int i = 0; i < n-1; i++){
        int v = ask(i);
        if(v == cnt-1){
            ans[i]++;
            cnta++;
        }
        if(!v) return 0;
    }
    if(cnta < cnt)
        ans[n-1]++;
    
    return out(ans);
}