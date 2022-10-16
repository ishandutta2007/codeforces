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

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

const int MM = 1005;

queue<int> q;
int n, m, dis[MM*2];
char s[MM];
vector<int> adj[MM*2];

int at(int i, int j){
    return i*m+j;
}

int main(){
    init();
    scan(n, m);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        for(int j = 0; j < m; j++){
            if(s[j] == '#'){
                adj[i].emplace_back(j+MM);
                adj[j+MM].emplace_back(i);
            }
        }
    }
    memset(dis, -1, sizeof dis);
    dis[0] = 0;
    q.emplace(0);
    while(q.size()){
        int cur = q.front(); q.pop();
        for(int u: adj[cur]){
            if(dis[u] == -1){
                dis[u] = dis[cur]+1;
                q.emplace(u);
            }
        }
    }
    print(dis[n-1]);

    
    return 0;
}