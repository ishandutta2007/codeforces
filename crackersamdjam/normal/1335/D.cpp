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

int t, a[9][9];
char s[11];

void go(int &v){
    v++;
    if(v == 10)
        v = 1;
}

int main(){
    scanf("%d", &t);
    while(t--){
        for(int i = 0; i < 9; i++){
            scanf("%s", s);
            for(int j = 0; j < 9; j++){
                a[i][j] = s[j]-'0';
            }
        }
        go(a[0][0]);
        go(a[1][3]);
        go(a[2][6]);
        go(a[3][1]);
        go(a[4][4]);
        go(a[5][7]);
        go(a[6][2]);
        go(a[7][5]);
        go(a[8][8]);
        
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                printf("%d", a[i][j]);
            }
            pc(10);
        }
    }
    
    
    return 0;
}