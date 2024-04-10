#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100005];
int sz[100005];

pair<int,int> cen(int x,int p){
    pair<int,int> res(-1,-1);
    bool f=1;
    sz[x]=1;
    for(int &y:g[x])if(y!=p){
        pair<int,int> r=cen(y,x);
        sz[x]+=sz[y];
        f&=sz[y]<=n/2;
        if(r.first!=-1)res.first=r.first;
        if(r.second!=-1)res.second=r.second;
    }
    f&=n-sz[x]<=n/2;
    if(f){
        if(res.first!=-1)res.second=x;
        else res.first=x;
    }
    return res;
}

pair<int,int> leaf(int x,int p){
    if(g[x].size()==1)return make_pair(x,p);
    for(int &y:g[x])if(y!=p){
        pair<int,int> r=leaf(y,x);
        if(r.first)return r;
    }
    return make_pair(0,0);
}

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    pair<int,int> p=cen(1,-1);
    if(p.second==-1){
        cout<<1<<' '<<g[1].front()<<'\n';
        cout<<1<<' '<<g[1].front()<<'\n';
    }else{
        pair<int,int> np=leaf(p.second,p.first);
        cout<<np.first<<' '<<np.second<<'\n';
        cout<<p.first<<' '<<np.first<<'\n';
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}