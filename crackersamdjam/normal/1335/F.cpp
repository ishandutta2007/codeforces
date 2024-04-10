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
const int MM = 1e6+2;

int t, n, m, c[MM];
char s[MM];

vector<int> adj[MM], cc[MM];
int cnt[MM], good[MM], totall, totgood;
bool done, vis[MM];
int len, dis[MM], rt;

void find(int cur, int d){
//    printerr("find", cur, d);
    if(++cnt[cur] == 2){
        done = 1;
        len = d-dis[cur];
        rt = cur;
        return;
    }
    dis[cur] = d;
    for(int u: cc[cur]){
        find(u, d+1);
        if(done)
            return;
    }
}

void go(int cur, int d){
    if(vis[cur])
        return;
    if(d == len)
        d = 0;
    good[d] |= c[cur];
    vis[cur] = 1;
    
    for(int u: adj[cur]){
        go(u, d+1);
    }
}

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            for(int j = 0; j < m; j++){
                c[i*m+j] = (s[j] == '0');
                adj[i*m+j].clear();
                cc[i*m+j].clear();
                cnt[i*m+j] = 0;
                vis[i*m+j] = 0;
                dis[i*m+j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            scanf("%s", s);
            for(int j = 0; j < m; j++){
                int ni = i, nj = j;
                if(s[j] == 'U')
                    ni--;
                else if(s[j] == 'D')
                    ni++;
                else if(s[j] == 'R')
                    nj++;
                else if(s[j] == 'L')
                    nj--;
                
//                printerr(i*m+j, ni*m+nj, "add");
                
                adj[ni*m+nj].emplace_back(i*m+j);
                //reverse graph for dp
                
                cc[i*m+j].emplace_back(ni*m+nj);
                //regular graph to detect cycle (start with nodes when no incoming edges, then loop through all on second run)
            }
        }
        totall = totgood = 0;
        int k = n*m;
        for(int i = 0; i < k; i++){
            if(!vis[i]){
//                printerr("st", i);
                
                len = 0;
                done = 0;
                rt = k;
                find(i, 0);
                
                totall += len;
//                printerr("len rt", len, rt);
                
                //then "dp"
                go(rt, 0);
                int v = 0;
                for(int j = 0; j < len; j++){
//                    printerr("g", j, good[j]);
                    v += good[j];
                    good[j] = 0;
                }
                
//                printerr("addvals", len, v);
                totgood += v;
            }
        }
        
        print(totall, totgood);
    }
    
    return 0;
}
/*
9
1 2
01
RL
3 3
001
101
110
RLL
DLD
ULL
3 3
000
000
000
RRD
RLD
ULL
1 2
01
RL
3 3
001
101
110
RLL
DLD
ULL
3 3
000
000
000
RRD
RLD
ULL
1 2
01
RL
3 3
001
101
110
RLL
DLD
ULL
3 3
000
000
000
RRD
RLD
ULL

 */