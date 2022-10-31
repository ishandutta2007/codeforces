#include <bits/stdc++.h>
using namespace std;

int n,k,x,y;
long long ans;
bool used[200001];
vector<int> v[200001];
int mx[200001];
int kol[200001];
int root;

void dfs(int x,int y){
    if (used[x]) kol[x]++;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        mx[x]=max(mx[x],kol[to]);
        kol[x]+=kol[to];
    }
    mx[x]=max(mx[x],k-kol[x]);
    if (mx[x]<=k/2) root=x;
}
void dfs2(int x,int y,int z){
    if (used[x]) ans+=1ll*z;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs2(to,x,z+1);
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin>>n>>k;
    k+=k;
    for (int i=1;i<=k;++i){
        cin>>x;
        used[x]=true;
    }
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    dfs2(root,-1,0);
    cout<<ans;
}