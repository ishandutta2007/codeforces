#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100;
const int maxm = 5e5 + 100;
vector<pair<int,int> > E[maxn];
pair<int,int> edge[maxm];
bool used[maxm];
int now[maxn];
int n,m;
int d[maxn];
vector<pair<int,int> > tour;
void dfs(int u,int e_id){
    for (; now[u] < E[u].size(); now[u] ++){
        int v,id;
        tie(v,id) = E[u][now[u]];
        if (used[id]) continue;
        used[id] = 1;
        dfs(v,id);
    }
    tour.push_back(make_pair(u,e_id));
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        edge[i] = make_pair(a,b);
        d[a]++;d[b]++;
    }
    vector<int> odd(0);
    for (int i=1;i<=n;i++){
        if (d[i] & 1)odd.push_back(i);
    }
    assert(odd.size() % 2 == 0);
    while (!odd.empty()){
        int a = odd.back();odd.pop_back();
        int b = odd.back();odd.pop_back();
        edge[++m] = make_pair(a,b);
    }
    if (m & 1)edge[++m] = make_pair(1,1);
    for (int i=1;i<=m;i++){
        int a,b;
        tie(a,b) = edge[i];
        E[a].push_back(make_pair(b,i));
        E[b].push_back(make_pair(a,i));
    }
    dfs(1,-1);
    for (int i=1;i<=m;i++){
        int a,b;
        tie(a,b) = edge[i];
    }
    reverse(tour.begin(), tour.end());
   /*
    for (auto pr : tour){
        int u,id;
        tie(u,id) = pr;
        cerr<<u<<" "<<id<<endl;
    }
    */
    printf("%d\n",m);
    for (int i = 1,now = 0;i < tour.size(); i ++,now ^= 1){
        int a = tour[i-1].first;
        int b = tour[i].first;
        if (now)swap(a,b);
        printf("%d %d\n",a,b);
    }
    
    return 0;
}