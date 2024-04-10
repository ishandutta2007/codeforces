#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1005;

long long ans = 1, mod = 1e9+7;
int n, m;
bool no[MM][MM];
int v[MM][MM];

int main(){
    
    scan(n, m);
    
    for(int i = 1,r; i <= n; i++){
        scan(r);
        for(int j = 1; j <= r+1; j++){
            no[i][j] = 1;
            if(j != r+1)
                v[i][j] = 1; //not block
            else
                v[i][j] = 2; //block
        }
    }
    
    for(int i = 1,c; i <= m; i++){
        scan(c);
        for(int j = 1; j <= c+1; j++){
            no[j][i] = 1;
            
            if(j != c+1){
                if(v[j][i] == 2){
                    puts("0");
                    return 0;
                }
                v[j][i] = 1;
            }
            else{
                if(v[j][i] == 1){
                    puts("0");
                    return 0;
                }
                v[j][i] = 2;
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!no[i][j])
                ans = (ans*2)%mod;
        }
    }
    
    print(ans);
    
    /*
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            printf("%d ", no[i][j]);
        pc(10);
    }
    */
    
    return 0;
}