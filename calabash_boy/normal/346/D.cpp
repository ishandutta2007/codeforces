#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1e6  + 100;
vector<int> E[maxn];
vector<int> EE[maxn];
int dis[maxn];
int n,m;
int d[maxn];
bool in[maxn];
void spfa(int root){
    queue<int> Q;
    for (int i=1;i<=n;i++){
        dis[i] = inf;
    }
    in[root] = 1;
    dis[root] = 0;
    Q.push(root);
    while (!Q.empty()){
        int head = Q.front();Q.pop();
        in[head] = false;
        for (int v : E[head]){
            if (dis[head] + 1 < dis[v]){
                dis[v] = dis[head] + 1;
                if (!in[v]){
                    in[v] = true;
                    Q.push(v);
                }
            }
        }
        int tmp_dis = 0;
        for (int v : EE[head]){
            tmp_dis = max(tmp_dis,dis[v]);
        }
        if (tmp_dis < dis[head]){
            dis[head] = tmp_dis;
            in[head] = true;
            Q.push(head);
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        EE[u].push_back(v);
        E[v].push_back(u);
//        d[u] ++;
    }
    int S,T;
    scanf("%d%d",&S,&T);
    spfa(T);
    printf("%d\n",dis[S]==inf?-1:dis[S]);
    return 0;
}