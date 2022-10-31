// Created by calabash_boy on 18-9-14.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 3000;
const int maxm = 10000;
const int inf = 0x3f3f3f3f;
struct Max_Flow{
    int first[maxn],nxt[maxm*2],des[maxm*2],c[maxm*2],tot;
    int dep[maxn];int ss,tt;
    Max_Flow(){ clear(); }
    void clear(){
        //memset(first,-1,sizeof first);
        for (int i=0;i<maxn;i++)first[i] = -1;
        tot =-1;
    }
    inline void addEdge(int u,int v,int w){
        tot++;
        des[tot] = v;c[tot] =w;
        nxt[tot] = first[u];first[u] = tot;
    }
    bool bfs(){
        for (int i=0;i<maxn;i++)dep[i] = -1;
        //memset(dep,-1,sizeof dep);
        dep[ss] =0;
        queue<int> Q;Q.push(ss);
        while (!Q.empty()){
            int q = Q.front();Q.pop();
            for (int t = first[q];t!=-1;t= nxt[t]){
                int v = des[t],cx = c[t];
                if (dep[v]==-1&&cx){
                    dep[v] = dep[q]+1;
                    Q.push(v);
                }
            }
        }
        return dep[tt]!=-1;
    }
    int dfs(int node,int now){
        if (node==tt)return now;
        int res =0;
        for (int t = first[node];t!=-1&&res<now;t=nxt[t]){
            int v = des[t],cx = c[t];
            if (dep[v]==dep[node]+1&&cx){
                int x = min(cx,now-res);
                x = dfs(v,x);
                res+=x;c[t]-=x;c[t^1]+=x;
            }
        }
        if (!res) dep[node] = -2;
        return res;
    }
    // tuple<from,to,flow>
    void init(vector<tuple<int,int,int> > Edge){
        for (auto tp : Edge){
            int u,v,w;tie(u,v,w) = tp;
            //cerr<<u<<"->"<<v<<" "<<w<<endl;
            addEdge(u,v,w);addEdge(v,u,0);
        }
    }
    // s->t max_flow
    ll max_flow(int s,int t){
        ss = s;tt = t;
        ll res =0,del =0;
        while (bfs()){while (del = dfs(ss,inf)){res += del;}}
        return res;
    }
}net;
//int n,m,s,t;
vector<tuple<int,int,int> > E;
int n,h,m;
int main(){
    scanf("%d%d%d",&n,&h,&m);
    int s = 1;
    int t = 2;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=h;j++){
            int id = 3 + (i-1) * (h+1) + j;
            if (j != h){
                E.push_back(make_tuple(id,id+1,h * h - j * j));
            }else{
                E.push_back(make_tuple(id,t,0));
            }
            if (j == 0){
                E.push_back(make_tuple(s,id,inf));
            }
        }
    }
    for (int i=0;i<m;i++){
        int id = 3 + n * (h+1) + i;
        int L,R,X,C;
        scanf("%d%d%d%d",&L,&R,&X,&C);
        if (X == h)continue;
        for (int j=L;j<=R;j++){
            int idd = 3 + (j-1) * (h+1) + X + 1;
            E.push_back(make_tuple(idd,id,inf));
        }
        E.push_back(make_tuple(id,t,C));
    }
    net.init(E);
    printf("%lld\n",h * h * n - net.max_flow(s, t));
    return 0;
}