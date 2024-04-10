#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

vector<int> convolution(const vector<int> a,const vector<int> &b){
    vector<int> res(a.size()+b.size()-1);
    for(int i=0;i<a.size();i++){
        for(int j=0;j<b.size();j++){
            res[i+j]=(res[i+j]+(ll)a[i]*b[j])%mod;
        }
    }
    return res;
}

int n;
int fa[1505],ec[1505],rk[1505];
vector<pair<int,pair<int,int>>> e;
vector<int> dp[1505];

int find(const int &x){
    if(x==fa[x])return x;
    return fa[x]=find(fa[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    fa[y]=x;
    rk[x]+=rk[y];
    ec[x]+=ec[y];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    iota(fa+1,fa+1+n,1);
    fill(rk+1,rk+1+n,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            static int w;
            cin>>w;
            if(i!=j)e.emplace_back(w,make_pair(i,j));
        }
        dp[i].emplace_back(1);
    }
    sort(e.begin(),e.end());
    for(pair<int,pair<int,int>> &ce:e){
        int u=ce.second.first,v=ce.second.second;
        u=find(u);
        v=find(v);
        if(u!=v){
            unite(u,v);
            dp[u]=convolution(dp[u],dp[v]);
            dp[u].insert(dp[u].begin(),0);
        }
        ec[u]++;
        dp[u][0]=ec[u]==rk[u]*(rk[u]-1);
    }
    for(int k=0;k<n;k++){
        cout<<dp[find(1)][k]<<' ';
    }
    cout<<'\n';

    return 0;
}