#include <bits/stdc++.h>
using namespace std;


long long n,xx,x,y;
vector<int> v[200005];
int pred[200005];
int len[200005];
int depth[200005];
int ans;

void dfs(int x,int y){
    pred[x]=y;
    len[x]=len[y]+1;
    if (x==1) --len[x];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        depth[x]=max(depth[x],depth[to]+1);
    }
    depth[x]=max(depth[x],1);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>xx;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    int kol=0;
    ans=0;
    while (xx!=0) {
        int z=len[xx];
        if (kol>=z) break;
        ans=max(ans,len[xx]+depth[xx]-1);
        ++kol;
        xx=pred[xx];
    }
    if (len[xx]==1 && depth[xx]==1) cout<<1; else
    cout<<ans*2;
}