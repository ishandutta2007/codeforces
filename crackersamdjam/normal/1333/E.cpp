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

int n, a[505][505], t;

int main(){
    scan(n);
    if(n < 3){
        return print(-1), 0;
    }
    else if(n == 3){
        printf("1 8 7\n2 4 3\n6 5 9\n");
        return 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(i==0 and j==1)
                continue;
            a[i][j] = ++t;
        }
    }
    for(int i = n-2; i >= 0; i--)
        a[i][n-1] = ++t;
    
    a[0][1] = ++t;
    a[n-1][n-1] = ++t;
    
    swap(a[n-2][0], a[n-2][n-2]);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        pc(10);
    }
    
    return 0;
}