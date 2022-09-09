#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
const int SIZE = 1024;
const long long INF = 1e18; //INF should be enough large.
typedef long long MYTYPE;
struct Data{
    MYTYPE v;
    int id;
    Data(MYTYPE _v,int _id):v(_v),id(_id){}
    bool operator<(const Data& b)const{return v>b.v;}
};
struct Dijkstra{
    vector<pair<int,MYTYPE> >e[SIZE];
    MYTYPE mi[SIZE];
    bool used[SIZE];
    int n,tt;
    void init(int _n){
        n=_n;
    }
    void add_edge(int x,int y,MYTYPE v){
        e[x].PB(MP(y,v));
    }
    void query(int st, int result[]){
        priority_queue<Data>qq;
        for(int i = 0; i < n; i++) {
            mi[i]=INF,used[i]=0;
        }
        mi[st]=0;
        qq.push(Data(0,st));
        while(!qq.empty()){
            Data now=qq.top();qq.pop();
            if(used[now.id])continue;
            used[now.id]=1;
            for(int i = 0; i < SZ(e[now.id]); i++){
                int y=e[now.id][i].first;
                if(mi[y]>now.v+e[now.id][i].second){
                    mi[y]=now.v+e[now.id][i].second;
                    qq.push(Data(mi[y],y));
                }
            }
        }
        for(int i = 0; i < n; i++) {
            result[i] = mi[i];
        }
    }
}dij;
int dd[1024][1024];
int _x[1024];
int _y[1024];
int a[1024];
int b[1024];
void solve() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    dij.init(n);
    for(int i = 0; i < m; i++) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        x--;
        y--;
        _x[i] = x;
        _y[i] = y;
        dij.add_edge(x, y, w);
        dij.add_edge(y, x, w);
    }
    for(int i = 0; i < k; i++) {
        scanf("%d%d", &a[i], &b[i]);
        a[i]--;
        b[i]--;
    }
    for(int i = 0; i < n; i++) {
        dij.query(i, dd[i]);
    }
    int answer = 1e9;
    for(int i = 0; i < m; i++) {
        int now = 0;
        for(int j = 0; j < k; j++) {
            now += min({dd[a[j]][b[j]], dd[a[j]][_x[i]] + dd[b[j]][_y[i]], dd[b[j]][_x[i]] + dd[a[j]][_y[i]]});
        }
        answer = min(answer, now);
    }
    printf("%d\n", answer);
}
int main() {
    solve();
    return 0;
}