//
// Created by calabash_boy on 18-7-6.
//
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB(x) push_back(x)
#define debug(x) cerr<<"[debug] "<<#x<<":"<<x<<endl;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
const int maxn = 1e6+100;
const int MOD = 1e9+7;
int rid[maxn*2];
int first[2*maxn],nxt[maxn*2],des[maxn*2],d[maxn*2],tot;
int n;
int fa[maxn*2];
pair<int,int> E[maxn];
map<int,int> id;int idcnt;
int nodeCnt[maxn*2],edgeCnt[maxn*2];
int ans = -1;
int find(int x){
    return x == fa[x]?x : fa[x] = find(fa[x]);
}
bool used[maxn*2];
int D[maxn*2];
vector<int> nodes[maxn*2];
inline void addEdge(int x,int y){
    tot ++;
    des[tot] = y;
    nxt[tot] = first[x];
    first[x] = tot;
    d[y] ++;
}
bool check(int x,int Val){
    for (int node :nodes[x]){
        D[node] = 0;
    }
    for (int node:nodes[x]){
        for (int t = first[node];t;t=nxt[t]){
            used[t] = false;
        }
    }
    for (int node :nodes[x]){
        for (int t = first[node];t;t=nxt[t]){
            int v = des[t];
            int uVal = rid[node];
            int vVal = rid[v];
            if (uVal < vVal)continue;
            if (uVal >=Val && vVal >=Val) return false;
            if (uVal <Val && vVal <Val )continue;
            used[t] = 1;
            used[((t-1)^1)+1] = 1;
            if (uVal < Val){
                D[node]++;
                if (D[node] == 2)return false;
            }else{
                D[v] ++;
                if (D[v] == 2)return false;
            }
        }
    }

    queue<int> Q;
    while (!Q.empty())Q.pop();
    for (int node :nodes[x]){
        if (D[node] == 1){
            Q.push(node);
        }
    }
    while (!Q.empty()){
        int head =Q.front();Q.pop();
        for (int t = first[head];t;t=nxt[t]){
            if (used[t])continue;
            used[t] = 1;
            used[((t-1)^1)+1] = 1;
            D[des[t]] ++;
            if (D[des[t]] == 2)return false;
            Q.push(des[t]);
        }
    }
    return true;
}

vector<int> tmp;
void work2(int x){
    int l = 0,r = nodes[x].size();
    tmp.clear();
    for (int node:nodes[x]){
        tmp.push_back(rid[node]);
    }
    sort(tmp.begin(),tmp.end());
    while (r-l>1){
        int mid = l+r >>1;
        if (check(x,tmp[mid])){
            r = mid;
        }else{
            l = mid;
        }
    }
    if(check(x,tmp[l]+1)){
        ans = max(ans,tmp[l]);
    }else{
        ans = max(ans,tmp[r]);
    }
}
void work(int x){
    if (edgeCnt[x] > nodeCnt[x]){
        puts("-1");
        exit(0);
    }
    if (edgeCnt[x] == nodeCnt[x]){
        int tempAns = -1;
        for (int node :nodes[x]){
            tempAns = max(tempAns,rid[node]);
        }
        ans = max(ans,tempAns);
    }else{
        work2(x);
    }
}
int main(){
    scanf("%d",&n);
    for (int i=1;i<=2*n;i++){
        fa[i] = i;
    }
    for (int i=1;i<=n;i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        if (!id[u]){
            id[u] = ++idcnt;
            rid[idcnt] = u;
        }
        if (!id[v]){
            id[v] = ++idcnt;
            rid[idcnt] = v;
        }
        int idu = id[u];
        int idv = id[v];
        E[i] = {idu,idv};
        addEdge(idu,idv);
        addEdge(idv,idu);
    }
    for (int i=1;i<=n;i++){
        int u = E[i].first;
        int v = E[i].second;
        int fu = find(u);
        int fv = find(v);
        if (fu == fv)continue;
        fa[fu] = fv;
    }

    for (int i=1;i<=idcnt;i++){
        nodes[find(i)].push_back(i);
        nodeCnt[find(i)]++;
    }
    for (int i=1;i<=n;i++){
        edgeCnt[find(E[i].first)]++;
    }
    for (int i=1;i<=idcnt;i++){
        if (i == find(i)){
            work(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}