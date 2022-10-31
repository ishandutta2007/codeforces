#include <bits/stdc++.h>
using namespace std;

int kol[400005];
int kol2[400005];
vector<int> v[400005];
short ans[400005];
vector<int> pref[400005];
vector<int> suff[400005];
int n,x,y;
int mn,pos;
void dfs(int x,int y){
    kol[x]=1;
    int mx=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs(to,x);
        kol[x]+=kol[to];
        mx=max(mx,kol[to]);
    }
    mx=max(mx,n-kol[x]);
    if (mx<mn) {
        mn=mx;
        pos=x;
    }
}
void dfs2(int x,int y){
    kol[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        dfs2(to,x);
        kol[x]+=kol[to];
        if (kol[to]<=(n)/2) kol2[x]=max(kol2[x],kol[to]);
        kol2[x]=max(kol2[x],kol2[to]);
    }
    if (kol[x]<=(n)/2) kol2[x]=max(kol2[x],kol[x]);
}
void dfs3(int x,int y,int z){
    if (n-kol[x]-z<=(n)/2) ans[x]=1;
    int last=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        pref[x].push_back(last);
        suff[x].push_back(0);
        if (to==y) continue;
        last=max(last,kol2[to]);
        pref[x][i]=last;
    }
    last=0;
    for (int i=v[x].size()-1;i>=0;--i) {
        int to=v[x][i];
        suff[x][i]=last;
        if (to==y) continue;
        last=max(last,kol2[to]);
        suff[x][i]=last;
    }
    if (n-kol[x]+1<=(n)/2) z=max(z,n-kol[x]+1);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        int qq=z;
        if (i) qq=max(qq,pref[x][i-1]);
        if (i<v[x].size()-1) qq=max(qq,suff[x][i+1]);
        int qq2=0;
        if (i) qq2=pref[x][i-1];
        if (i<v[x].size()-1) qq2=max(qq2,suff[x][i+1]);
        qq=max(qq,qq2);
        if (n-kol[to]<=n/2) qq=max(qq,n-kol[to]);
        dfs3(to,x,qq);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    mn=1e9;
    pos=0;
    dfs(1,-1);
    dfs2(pos,-1);
    dfs3(pos,-1,0);
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}