#include <bits/stdc++.h>
using namespace std;


int n;
int x,y;
vector<int> v[200005];
int depth[200005];
int pred[200005];

void dfs(int x,int y,int dd=0){
    depth[x]=dd;
    pred[x]=y;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs(to,x,dd+1);
    }
}
int dfs2(int x,int y){
    int last=-1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int res=dfs2(to,x);
        if (res==-1) return -1;
        else if (last==-1) last=res;
        else if (last!=res) return -1;
    }
    return last+1;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,-1);
    int pos=1;
    int mx=0;
    for (int i=1;i<=n;++i)
    if (depth[i]>mx) {
        mx=depth[i];
        pos=i;
    }
    dfs(pos,-1);
    mx=0;
    int pos2=1;
    for (int i=1;i<=n;++i){
        if (depth[i]>mx) {
            mx=depth[i];
            pos2=i;
        }
    }
    int len=mx/2;
    while (len--)
        pos2=pred[pos2];
    set<int> s;
    for (int i=0;i<v[pos2].size();++i) {
        int q=dfs2(v[pos2][i],pos2);
        if (q==-1){
            cout<<"-1";
            return 0;
        }
        s.insert(q+1);
    }
    if (s.size()>2) {
        cout<<"-1";
        return 0;
    }
    int res=0;
    while (!s.empty()) {
        res+=*s.begin();
        s.erase(s.begin());
    }
    while (!(res&1)) res>>=1;
    cout<<res;
}