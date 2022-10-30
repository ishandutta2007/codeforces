#include <bits/stdc++.h>
using namespace std;


vector<pair<int,long long> > v[5005];
long long sum[5005],ans2[5005],kol[5005];
long long ans;
int clr[5005];
int n,x,y,z;
vector<pair<pair<int,int>,long long> > vv;
void dfs(int x,int y,int z){
    clr[x]=z;
    sum[x]=0;
    kol[x]=1;
    for (int j=0;j<v[x].size();++j) {
        int to=v[x][j].first;
        if (to==y) continue;
        dfs(to,x,z);
        ans+=sum[x]*(kol[to])+sum[to]*(kol[x])+(kol[x]*kol[to])*v[x][j].second;
        sum[x]+=sum[to]+kol[to]*v[x][j].second;
        kol[x]+=kol[to];
    }
}
void dfs2(int x,int y,int z,int zz,int kolall){
    ans2[x]=sum[x];
    if (z!=-1) {
        long long xx=ans2[y];
        xx-=sum[x]+kol[x]*zz;
        ans2[x]+=xx+(kolall-kol[x])*zz;
    }
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        if (to!=y) dfs2(to,x,x,v[x][i].second,kolall);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y>>z;
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
        vv.push_back(make_pair(make_pair(x,y),z));
    }
    long long res=1e18;
    for (int i=0;i<vv.size();++i) {
        ans=0;
        x=vv[i].first.first;
        y=vv[i].first.second;
        dfs(x,y,1);
        dfs(y,x,2);
        dfs2(x,y,-1,0,kol[x]);
        dfs2(y,x,-1,0,kol[y]);
        long long s1=1e18;
        long long s2=1e18;
        for (int j=1;j<=n;++j) {
            long long ss=ans2[j];
            if (clr[j]==1) ss*=kol[y];
            else ss*=kol[x];
            if (clr[j]==1) s1=min(s1,ss);
            else s2=min(s2,ss);
        }
        res=min(res,ans+s1+s2+kol[x]*kol[y]*vv[i].second);
    }
    cout<<res;
}