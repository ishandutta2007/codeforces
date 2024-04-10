#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef std::pair<int, int> pii;
constexpr int MM = 1e4+1, MN = 1000;

int n, m, a[MM], A, B;
int dis[MM][MN];
bool vis[MM][MN];
std::deque<pii> q;

int main(){
    scan(n, m);
    for(int i = 0; i < m; i++)
        scan(a[i]);
    scan(A, B);
    std::sort(a, a+m);
    memset(dis, 0x3f, sizeof dis);
    dis[0][0] = 0;
    q.emplace_back(0, 0);
    while(q.size()){
        int i = q.front().first, d = q.front().second; q.pop_front();
        if(vis[i][d])
            continue;
        vis[i][d] = 1;
    
        if(i < m-1){
            int w = a[i+1]-a[i], nd = d+w;
            if(nd == A){
                nd = 0;
                w += B;
            }
            if(nd < A and dis[i][d]+w < dis[i+1][nd]){
                dis[i+1][nd] = dis[i][d]+w;
                if(nd){
                    q.emplace_front(i+1, nd);
                }
                else{
                    q.emplace_back(i+1, nd);
                }
            }
            if(i){
                w = a[i]-a[i-1], nd = d+w;
                if(nd == A){
                    nd = 0;
                    w += B;
                }
                if(nd < A and dis[i][d]+w < dis[i-1][nd]){
                    dis[i-1][nd] = dis[i][d]+w;
                    if(nd){
//                    inq[i+1][nd] = 1;
                        q.emplace_front(i-1, nd);
                    }
                    else{
//                    inq[i+1][nd] = 1;
                        q.emplace_back(i-1, nd);
                    }
                }
            }
        }
    }
    
    int ans = dis[m-1][0]-B;
    
    for(int i = 1; i < A; i++){
        if(dis[m-1][i] < ans)
            ans = dis[m-1][i];
    }
    
    print(ans == dis[m][0]-B ? -1 : ans);
    
    return 0;
}