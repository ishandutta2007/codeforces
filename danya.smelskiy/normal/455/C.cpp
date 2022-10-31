#include <bits/stdc++.h>
using namespace std;

int n,m,q,x,y,ans;
int p[300005];
int sz[300005];
vector<int> v[300005];
bool used[300005];
int get(int x){
    if (x==p[x]) return x;
    return p[x]=get(p[x]);
}
int dfs(int x,int y,int z,int xx){
    used[x]=true;
    p[x]=xx;
    int sz1=0,sz2=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int res=dfs(to,x,z+1,xx);
        if (res>sz2) sz2=res;
        if (sz2>sz1) swap(sz2,sz1);
    }
    ans=max(ans,max(sz1+sz2+1,sz1+z));
    return sz1+1;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i){
        p[i]=i;
    }
    for (int i=1;i<=n;++i)
    if (used[i]==false) {
        ans=0;
        dfs(i,-1,1,i);
        sz[i]=ans-1;
    }
    for (int i=1;i<=q;++i) {
        cin>>x;
        if (x==1) {
            cin>>x;
            cout<<sz[get(x)]<<'\n';
        } else {
            cin>>x>>y;
            x=get(x);
            y=get(y);
            if (x==y) continue;
            p[y]=x;
            sz[x]=max(max(sz[x],sz[y]),(sz[x]+1)/2+(sz[y]+1)/2+1);
        }
    }
}