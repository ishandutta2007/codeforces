//
// Created by calabash_boy on 18-7-13.
//
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
typedef long long LL;
int tot,first[maxn],des[maxn*2],nxt[maxn*2];
int len[maxn*2];
vector<vector<int> > opt;
char s[maxn];
int n,m,k;
void dfs_ans(int dep){
    if (dep==n+1){
        k--;
        cout<<s<<'\n';
        if(!k)throw 0;
        return ;
    }
    for (int x:opt[dep]){
        s[x]='1';
        dfs_ans(dep+1);
        s[x]='0';
    }
}

void bfs(int u){
    queue<int> q;
    q.push(u);
    while (!q.empty()){
        int head = q.front();
        q.pop();
        for (int t = first[head];t;t=nxt[t]){
            int v = des[t];
            if (len[v])continue;
            len[v] = len[head]+1;
            q.push(v);
        }
    }
}

inline void addEdge(int x,int y){
    tot++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
}
int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#endif
    cin>>n>>m>>k;
    for (int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        addEdge(u,v);
        addEdge(v,u);
    }
    len[1]=1;
    bfs(1);
    opt.resize(n+1);
    for (int i=1;i<=n;i++){
       // cout<<i<<" "<<len[i]<<endl;
        assert(len[i]);
        for (int t = first[i];t;t=nxt[t]){
            if (len[des[t]]==len[i]+1){
                opt[des[t]].push_back((t-1)/2);
            }
        }
    }
    LL totAns=1;
    for (int i=2;i<=n;i++){
        totAns *= opt[i].size();
        if (totAns>=k)break;
    }
    k = min(1LL*k,totAns);
    cout<<k<<endl;
    for (int i=0;i<m;i++){
        s[i]='0';
    }
    try{
        dfs_ans(2);
    }catch(int temp){

    }
    return 0;
}