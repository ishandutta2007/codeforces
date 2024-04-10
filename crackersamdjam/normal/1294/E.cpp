#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2;

int n, m, ans, summ[MM];
map<int, int> d[MM];

int main(){
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 1,a; j <= m; j++){
            scanf("%d", &a);
            if((a%m == j%m) and (a <= n*m)){
                int v = i - (a-1)/m;
                while(v < 0) v += n;
                d[j][v]++;
                //printf("%d ", v);
            }
            else{
                summ[j]++;
                //printf("- ");
            }
        }
        //pc(10);
    }
    for(int j = 1; j <= m; j++){
        if(d[j].empty()){
            ans += n;
            continue;
        }
        int best = n, sum = 0;
        for(auto i: d[j]){
            sum += i.second;
        }
        best = sum;
        for(auto i: d[j]){
            best = min(best, sum-i.second+i.first);
        }
        ans += summ[j] + best;
    }
    
    print(ans);
    
    return 0;
}
/*
3 4
1 6 3 4
5 16 7 8
9 2 11 12

 */