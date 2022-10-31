#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
const int maxm = 100000 + 5;
char s[10];
struct Edge{
    int u,v;
    int type;
    int id;
    Edge(){};
    void read(int id_){
        scanf("%d%d",&u,&v);
        scanf("%s",s);
        int ch = s[0];
        if(ch == 'S')type = 1;
        else type = 0;
        id = id_;
    }
};
Edge edges[maxm];
int n,m;
struct UFS{
    int fa[maxn];
    void init(int n){
        for (int i=1;i<=n;i++){
            fa[i] = i;
        }
    }
    int find(int x){
        return fa[x] == x?x:fa[x] = find(fa[x]);
    }
    bool merge(int x,int y){
      //  cerr<<"merge:"<<x<<" "<<y<<endl;
        int fx = find(x);
        int fy = find(y);
        if (fx == fy)return false;
        fa[fx] = fy;
        return true;
    }
}ufs;
int main(){
    scanf("%d%d",&n,&m);
    if (n%2 == 0){
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<=m;i++){
        edges[i].read(i);
    }
    ufs.init(n);
    int cnt0 = 0;
    int cnt1 = 0;
    vector<Edge> ans(0);
    for (int i=1;i<=m;i++){
        if (edges[i].type == 0){
            ufs.merge(edges[i].u, edges[i].v);
        }
    }
    for (int i=1;i<=m;i++){
        if (edges[i].type == 1 && ufs.merge(edges[i].u, edges[i].v)){
            ans.push_back(edges[i]);
            cnt1 ++;
        }
    }
    ufs.init(n);
    for (auto e : ans){
        ufs.merge(e.u, e.v);
    }
    for (int i=1;i<=m;i++){
        if (cnt1 == n/2)break;
        if (edges[i].type == 1 && ufs.merge(edges[i].u, edges[i].v)){
            ans.push_back(edges[i]);
            cnt1 ++;
        }
    }
    for (int i=1;i<=m;i++){
        if (cnt0 == n/2)break;
        if (edges[i].type == 0 && ufs.merge(edges[i].u, edges[i].v)){
            ans.push_back(edges[i]);
            cnt0 ++;
        }
    }
    if (ans.size() != n-1 || cnt0 != n/2 || cnt1 != n/2){
        cout<<-1<<endl;
    }else{
        cout<<ans.size()<<endl;
        for (auto e : ans){
            cout<<e.id<<' ';
        }
        cout<<endl;
    }
    return 0;
}