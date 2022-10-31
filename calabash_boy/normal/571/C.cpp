#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int ans[maxn];
int n,m;
bool used[maxn];
bool ok[maxn];
vector<int> vars[maxn][2];
vector<int> liters[maxn];
vector<pair<int,int> > E[maxn];
void dfs(int u,vector<int> &nodes){
    nodes.push_back(u);
    ok[u] = 1;
    for (auto pr : E[u]){
        int v,flag;
        tie(v,flag) = pr;
        if (ok[v])continue;
        dfs(v,nodes);
    }
}
vector<int> nodes(0);
int vis[maxn];
vector<int> chain;
stack<pair<int,int> > stk;
void dfs2(int u){
    for (auto e : E[u]){
        int v,flag;
        tie(v,flag) = e;
        if (vis[v] == 3)continue;
        vis[v] = 3;
        ans[abs(flag)] = flag>0?1:-1;
        dfs2(v);
    }
}
void search_chain(int u,int e_flag){
    vis[u] = 1;
    stk.push(make_pair(u,e_flag));
    for (auto e : E[u]){
        int v,flag;
        tie(v,flag) = e;
        if (vis[v] == 2)continue;
        if (vis[v] == 1){
            if(e_flag + flag == 0)continue;
            ans[abs(flag)] = flag > 0? -1:1;
            vector<int> vised(0);
            while (stk.top().first != v){
                int temp = stk.top().first;
                int e_id = stk.top().second;
                stk.pop();
                ans[abs(e_id)] = e_id >0?-1:1;
                vised.push_back(temp);
            }
            vised.push_back(v);
            for (int x : vised)vis[x] = 3;
            for (int x : vised)dfs2(x);
            throw 1;
        }
        if (vis[v] == 0){
            search_chain(v,flag);
        }
    }
    vis[u] = 2;
    stk.pop();
}
void gao(int x){
    nodes.clear();
    dfs(x,nodes);
    int node_cnt = nodes.size();
    int edge_cnt = 0;
    for (int x : nodes){
        edge_cnt += E[x].size();
    }
    assert(edge_cnt %2 == 0);
    edge_cnt /= 2;
    if (edge_cnt == node_cnt - 1){
        puts("NO");
        exit(0);
    }
    while (!stk.empty()) stk.pop();
    chain.clear();
    try{
        search_chain(x,m + 1);
    }catch(int x){
        assert(x == 1);
        for (int x : nodes){
            ok[x] = 1;
        }
        return;
    }
    assert(0);
}
void erase(vector<int> & tar,int val){
    vector<int> ans(0);
    bool find = false;
    for (int x : tar){
        if (x == val){
            find = true;
        }else{
            ans.push_back(x);
        }
    }
    assert(find);
    tar = ans;
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        while (k--){
            int v;
            scanf("%d",&v);
            liters[i].push_back(v);
            vars[abs(v)][v >0?0:1].push_back(i);
        }
    }
    static bool in[maxn];
    memset(in,0,sizeof in);
    queue<int> Q;
    for (int i=1;i<=m;i++){
        if (vars[i][0].empty()){
            ans[i] = -1;
            for (int x: vars[i][1]){
                if (!in[x]){
                    in[x] = 1;
                    Q.push(x);
                }
            }
        }
        if (vars[i][1].empty()){
            ans[i] = 1;
            for (int x : vars[i][0]){
                if (!in[x]){
                    in[x] = 1;
                    Q.push(x);
                }
            }
        }
    }
    while (!Q.empty()){
        int head = Q.front();Q.pop();
        ok[head] = 1;
        for (int v : liters[head]){
            erase(vars[abs(v)][v>0?0:1],head);
            v = abs(v);
            if (vars[v][0].empty() && ans[v] == 0){
                ans[v] = -1;
                for (int x : vars[v][1]){
                    if (!in[x]){
                        in[x] = 1;
                        Q.push(x);
                    }
                }
            }
            if (vars[v][1].empty() && ans[v] == 0){
                ans[v] = 1;
                for (int x : vars[v][0]){
                    if (!in[x]){
                        in[x] = 1;
                        Q.push(x);
                    }
                }
            }
        }
    }
    for (int i=1;i<=m;i++){
        if (vars[i][0].empty() && vars[i][1].empty())continue;
        if (vars[i][0].size() == 1 && vars[i][1].size() == 1){
            int u = vars[i][0].front();
            int v = vars[i][1].front();
            E[u].push_back(make_pair(v,-i));
            E[v].push_back(make_pair(u,i));
            continue;
        }
        assert(0);
    }
    for (int i=1;i<=n;i++){
        if (ok[i])continue;
        gao(i);
    }
    puts("YES");
    for (int i=1;i<=m;i++){
        if(ans[i] == 1){
            putchar('1');
        }else{
            putchar('0');
        }
    }
    puts("");
    return 0;
}