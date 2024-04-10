#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
bool exist[maxn][maxn];
int m,n,s,t;
int dis[maxn][2];
vector<int> E[maxn];
void dfss(){
    queue<int> Q;
    Q.push(s);
    for (int i=1;i<=n;i++){
        dis[i][0]=0x3f3f3f3f;
    }
    dis[s][0]=0;
    while (!Q.empty()){
        int q = Q.front();
        Q.pop();
        for (int v:E[q]){
            if (dis[v][0]>dis[q][0]+1){
                dis[v][0] = dis[q][0]+1;
                Q.push(v);
            }
        }
    }
}
void dfst(){
    queue<int> Q;
    Q.push(t);
    for (int i=1;i<=n;i++){
        dis[i][1]=0x3f3f3f3f;
    }
    dis[t][1]=0;
    while (!Q.empty()){
        int q = Q.front();
        Q.pop();
        for (int v:E[q]){
            if (dis[v][1]>dis[q][1]+1){
                dis[v][1] = dis[q][1]+1;
                Q.push(v);
            }
        }
    }
}
int main(){
    cin>>n>>m>>s>>t;
    while (m--){
        int a,b;
        cin>>a>>b;
        E[a].push_back(b);
        E[b].push_back(a);
        exist[a][b] = exist[b][a] = true;
    }
    dfss();
    dfst();
    int len = dis[t][0];
    int ans =0;
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            if (exist[i][j])continue;
            int temp = min(dis[i][0]+dis[j][1],dis[j][0]+dis[i][1]);
            if (temp+1>=len){
                ans++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}