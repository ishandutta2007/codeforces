#include <bits/stdc++.h>
using namespace std;



int n,x,y,f,s;
int ans[3005];
int pred[3005];
vector<int> v[3005];
bool used[3005];
bool used2[3005];
void dfs2(int x,int d,int p=-1){
    ans[x]=d;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (to==p) continue;
        if (used2[to]==false) dfs2(to,d+1,x);
    }
}
void dfs(int x,int y){
    pred[x]=y;
    used[x]=1;
    for (int i=0;i<v[x].size();++i){
        int to=v[x][i];
        if (used[to]==2 || to==y) continue;
        if (used[to]==1) {
            s=x;
            f=to;
            used[x]=2;
            return;
        }
        dfs(to,x);
    }
    used[x]=2;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    swap(f,s);
    while (s!=f) {
        used2[s]=true;
        s=pred[s];
    }
    used2[f]=true;
    for (int i=1;i<=n;++i)
        if (used2[i]==true) dfs2(i,0);
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}