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
const int MM = 5e4+5;

int t, n;
char a[MM], b[MM], c[MM];

int main(){
    scan(t);
    while(t--){
        scan(n);
        scanf("%s", a);
        int s = 0;
        for(int i = 0; i < n; i++){
            if(!s){
                if(a[i] == '1'){
                    b[i] = '1', c[i] = '0';
                    s = 1;
                }
                else if(a[i] == '2')
                    b[i] = c[i] = '1';
                else
                    b[i] = c[i] = '0';
            }
            else{
                b[i] = '0';
                c[i] = a[i];
            }
        }
        b[n] = c[n] = 0;
        printf("%s\n%s\n", b, c);
    }
    
    return 0;
}