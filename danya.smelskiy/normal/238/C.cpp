#include <bits/stdc++.h>
using namespace std;



int res;
int kol1[3005];
int kol2[3005];
vector<pair<int,int> > v[3005];
vector<pair<int,int> > q;
int n,x,y;

void dfs1(int x,int y){
    kol1[x]=kol2[x]=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        dfs1(to,x);
        kol1[x]+=kol1[to];
        kol2[x]+=kol2[to];
        kol1[x]+=v[x][i].second;
        kol2[x]+=1-v[x][i].second;
    }
}

void dfs2(int x,int y,int z=0,int zz=0){
    int kol=kol1[x];
    res=min(res,kol+z+zz);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to==y) continue;
        int kk=kol-kol1[to]-v[x][i].second;
        int z1=z+1-v[x][i].second;
        dfs2(to,x,z1,zz+kk);
    }
}
int solve(int x,int y){
    dfs1(x,y);
    res=1e9;
    dfs2(x,y);
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(make_pair(y,0));
        v[y].push_back(make_pair(x,1));
        q.push_back(make_pair(x,y));
    }
    solve(1,2);
    int ans=1e9;
    if (n==1) ans=0;
    for (int i=0;i<q.size();++i) {
        int xx=q[i].first;
        int yy=q[i].second;
        ans=min(ans,solve(xx,yy)+solve(yy,xx));
    }
    cout<<ans;
}