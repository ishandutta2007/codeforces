// Created by calabash_boy on 2019/10/25.
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 100;
struct BIT{
    int sum[maxn];
    void add(int x,int val){
        while (x < maxn){
            sum[x] += val;x += x & -x;
        }
    }
    int query(int x){
        int ret = 0;
        while (x){
            ret += sum[x];x -= x & -x;
        }
        return ret;
    }
    int query(int l,int r){
        return query(r) - query(l-1);
    }
}bit;
int n,m;
int pos[maxn];
string t[maxn];
vector<pair<int,int> > Query[maxn];
int ans[maxn];
int in[maxn],out[maxn],dfn;
struct ACAM {
    int nxt[maxn][26], fail[maxn];
    int Go[maxn][26];
    int root = 0;
    int cnt = 0;
    vector<int> E[maxn];
    void clear(){
        root = cnt = 0;
        memset(nxt[0],0,sizeof nxt[0]);
    }
    int newnode() {
        cnt++;
        return cnt;
    }
    int insert(const char *s) {
        int now = root;
        while (*s){
            now = insert(now,*s - 'a');
            s ++;
        }
        return now;
    }
    int insert(int pre, int ch) {
        return nxt[pre][ch]?nxt[pre][ch] : nxt[pre][ch] = newnode();
    }
    void build() {
        queue<int> Q;
        Q.push(0);
        memcpy(Go[0],nxt[0],sizeof nxt[0]);
        while (!Q.empty()) {
            int head = Q.front();
            Q.pop();
            for (int ch = 0; ch < 26; ch++) {
                int v = nxt[head][ch];
                if (!v)continue;
                if (head == 0) fail[v] = 0;
                else fail[v] = Go[fail[head]][ch];
                memcpy(Go[v],Go[fail[v]],sizeof Go[v]);
                for (int cc = 0; cc < 26; cc++) {
                    if (nxt[v][cc])Go[v][cc] = nxt[v][cc];
                }
                E[fail[v]].push_back(v);
                Q.push(v);
            }
        }
    }
    void dfs(int u){
        in[u] = ++dfn;
        for (int v : E[u]){
            dfs(v);
        }
        out[u] = dfn;
    }
}acam;
struct Trie {
    int nxt[maxn][26];
    vector<int> ed[maxn];
    int root = 0;
    int cnt = 0;
    void clear(){
        root = cnt = 0;
        memset(nxt[0],0,sizeof nxt[0]);
    }
    int newnode() {
        cnt++;
        return cnt;
    }
    int insert(int pre, int ch) {
        return nxt[pre][ch]?nxt[pre][ch] : nxt[pre][ch] = newnode();
    }
    void dfs(int u,int now){
        bit.add(in[now],1);
        for (int si : ed[u]){
            for (auto &q : Query[si]){
                int id = q.second;
                int x = q.first;
                ans[id] = bit.query(in[x],out[x]);
            }
        }
        for (int ch = 0;ch < 26;ch ++){
            int v = nxt[u][ch];
            if (!v)continue;
            int Nxt = acam.Go[now][ch];
            dfs(v,Nxt);
        }
        bit.add(in[now],-1);
    }
}trie;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        int op;
        cin>>op;
        static char buf[10];
        if (op == 1){
            cin>>buf;
            pos[i] = trie.insert(0,*buf - 'a');
        }else{
            int pre;
            cin>>pre>>buf;
            pos[i] = trie.insert(pos[pre],*buf - 'a');
        }
        trie.ed[pos[i]].push_back(i);
    }
    cin>>m;
    for (int i=1;i<=m;i++){
        int tar;
        string temp;
        cin>>tar>>temp;
        int me = acam.insert(temp.c_str());
        Query[tar].push_back(make_pair(me,i));

    }
    acam.build();
    acam.dfs(0);
    trie.dfs(0,0);

    for (int i=1;i<=m;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}