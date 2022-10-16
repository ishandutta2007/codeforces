#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int n, k, dis[11][80], adj[80][80], c[80], ans = 1e9, tt = 20000;
queue<pair<int, int>> q;
bool inq[11][80];

mt19937 g1(time(0));
int randint(int a, int b){return uniform_int_distribution<int>(a, b)(g1);}

int main(){
    scan(n, k);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scan(adj[i][j]);
        
    while(tt--){
        memset(dis, 0x3f, sizeof dis);
        for(int i = 0; i < n; i++)
            c[i] = randint(0, 1);
        dis[0][0] = 0;
        q.emplace(0, 0);
        while(q.size()){
            int t = q.front().first, cur = q.front().second; q.pop();
            inq[t][cur] = 0;
            for(int u = 0; u < n; u++){
                if(t < k and c[u] != c[cur] and dis[t][cur] + adj[cur][u] < dis[t+1][u]){
                    dis[t+1][u] = dis[t][cur] + adj[cur][u];
                    if(!inq[t+1][u]){
                        inq[t+1][u] = 1;
                        q.emplace(t+1, u);
                    }
                }
            }
        }
        ans = min(ans, dis[k][0]);
    }
    print(ans);
    
    return 0;
}