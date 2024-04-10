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
const int MM = 2e5+5;

int t, n, p[MM], c[MM];
bool vis[MM];

int main(){
    scan(t);
    while(t--){
        scan(n);
        int ans = n;
        for(int i = 1; i <= n; i++){
            scan(p[i]);
            vis[i] = 0;
        }
        for(int i = 1; i <= n; i++)
            scan(c[i]);
        
        for(int i = 1; i <= n; i++){
            if(vis[i])
                continue;
            vector<int> cur;
            int u = i, len = 0;
            do{
                cur.push_back(u);
                vis[u] = 1;
                u = p[u];
                len++;
            } while(u != i);
            
            for(int j = 1; j <= len; j++){
                if(len%j == 0){
                    //when k = j, the cycle is divided into j parts
                    int sz = len/j;
                    for(int st = 0; st < j; st++){
                        int pos = 1;
                        for(int k = st; k < len; k += j){
//                            print(k, cur[k], c[cur[k]]);
                            if(c[cur[k]] != c[cur[st]])
                                pos = 0;
                        }
                        if(pos){
                            ans = min(ans, j);
//                            print(i, j, sz);
                        }
                    }
                }
            }
        }
        print(ans);
    }
    
    return 0;
}
/*
3
4
1 3 4 2
1 2 2 3
5
2 3 4 5 1
1 2 3 4 5
8
7 4 5 6 1 8 3 2
5 3 6 4 7 5 8 4


1 5 2

 */