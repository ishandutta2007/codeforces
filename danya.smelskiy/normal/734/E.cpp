#include <bits/stdc++.h>
using namespace std;
int n;
int p[200001];
vector<int> v[200001];
int x,y;
vector<pair<int,int> > q;
int a[200001];
int get(int x){
    if (x==p[x]) return x;
    else return p[x]=get(p[x]);
}
int ans;
int dfs(int x,int y){
    int sz1=0,sz2=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int res=dfs(to,x);
        if (res>sz2) {
            sz2=res;
            if (sz2>sz1) swap(sz1,sz2);
        }
    }
    ans=max(ans,sz1+sz2);
    return sz1+1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        p[i]=i;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        q.push_back(make_pair(x,y));
        x=get(x);
        y=get(y);
        if (a[x]==a[y]) p[y]=x;
    }
    int last=1;
    for (int i=0;i<q.size();++i) {
        x=q[i].first;
        y=q[i].second;
        x=get(x);
        y=get(y);
        if (x!=y) {
            v[x].push_back(y);
            v[y].push_back(x);
        }
        last=x;
    }
    dfs(last,-1);
    cout<<(ans+1)/2;
}