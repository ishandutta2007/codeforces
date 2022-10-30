#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
int fa[maxn];
int sz[maxn];
set<int> root;
int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void merge(int u,int v){
    int fu = find(u);
    int fv = find(v);
    if (fu == fv)return;
    if (sz[fu] > sz[fv]){
        // v -> u
        fa[fv] = fu;
        sz[fu] += sz[fv];
        root.erase(fv);
    }else{
        // u -> v
        fa[fu] = fv;
        sz[fv] += sz[fu];
        root.erase(fu);
    }
}
vector<int> E[maxn];
int n,m;
int cnt[maxn];
int main(){
    cin>>n>>m;
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i=1;i<=n;i++){
        fa[i] = i;
        sz[i] = 1;
        root.insert(i);
    }
    for (int i=1;i<=n;i++){
        for (int v : E[i]){
            cnt[find(v)] = 0;
        }
        for (int v : E[i]){
            if (v < i)cnt[find(v)] ++;
        }
        vector<int> check(0);
        for (int x : root){
            if (x < i){
                check.push_back(x);
            }else break;
        }
        vector<int> to_merge(0);
        for (int x : check){
            if (sz[x] > cnt[x]){
                to_merge.push_back(x);
            }
        }
        for (int v : E[i]){
            cnt[find(v)] = 0;
        }
        for (int x : to_merge){
            merge(x,i);
        }
    }
    cout<<root.size() - 1<<endl;
    return 0;
}