#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2004;

ll dif[MM][MM], ans;
int n, k;
char gd[MM][MM];

void add(int a, int b, int c, int d){
    a = max(1, a);
    b = max(1, b);
    c = min(n+1, c);
    d = min(n+1, d);
    dif[a][b]++;
    dif[a][d+1]--;
    dif[c+1][b]--;
    dif[c+1][d+1]++;
}

int main(){
    
    scanf("%d %d", &n ,&k);
    
    for(int i = 1; i <= n; i++){
        scanf("%s", gd[i]+1);
    }
    
    for(int i = 1; i <= n; i++){
        //row update
        int first = n+1, last = 0, seen = 0;
        for(int j = 1; j <= n; j++){
            if(gd[i][j] == 'B'){
                first = min(first, j);
                last = max(last, j);
                seen = 1;
            }
        }
        if(!seen){
            ans++;
            continue;
        }
        
        int len = last-first+1;
        
        if(len <= k){
            int extra = k-len;
            add(i-k+1, first-extra, i, first);
            //print(i-k+1, first-extra, i, first);
        }
    }
    
    //puts("2");
    
    for(int j = 1; j <= n; j++){
        int first = n+1, last = 0, seen = 0;
        for(int i = 1; i <= n; i++){
            if(gd[i][j] == 'B'){
                first = min(first, i);
                last = max(last, i);
                seen = 1;
            }
        }
        if(!seen){
            ans++;
            continue;
        }
        int len = last-first+1;
    
        if(len <= k){
            int extra = k-len;
            add(first-extra, j-k+1, first, j);
            //print(first-extra, j-k+1, first, j);
        }
    }
    
    ll best = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            dif[i][j] += dif[i-1][j] + dif[i][j-1] - dif[i-1][j-1];
            best = max(best, dif[i][j]);
        }
    }
    
    print(best + ans);
    
    return 0;
}