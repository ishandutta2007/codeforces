#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int n;
    vector<int> fa;

    UnionFind(int _n=0){
        fa.resize((n=_n)+1);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    void unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
    }

    void clear(){
        iota(fa.begin(),fa.end(),0);
    }
}uf;

typedef long long ll;

int n,m,u[305],v[305],w[305];
vector<pair<int,pair<ll,int>>> ans;

void calc(int x){
    uf.clear();
    static vector<pair<int,pair<int,int>>> e;
    e.resize(m);
    for(int i=0;i<m;i++)e[i]={w[i],make_pair(u[i],v[i])};
    ll tot=0;int lower=0;
    sort(e.begin(),e.end(),[&](const pair<int,pair<int,int>> &a,const pair<int,pair<int,int>> &b){
        if(abs(a.first-x)!=abs(b.first-x))return abs(a.first-x)<abs(b.first-x);
        return a<b;
    });
    for(auto &[w,p]:e){
        auto &[u,v]=p;
        if(uf.find(u)!=uf.find(v)){
            uf.unite(u,v);
            tot+=abs(w-x);
            lower+=w<=x;
        }
    }
    ans.emplace_back(x,make_pair(tot,lower));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    uf=UnionFind(n);
    for(int i=0;i<m;i++){
        cin>>u[i]>>v[i]>>w[i];
    }
    calc(0);
    for(int i=0;i<m;i++){
        calc(w[i]);
        for(int j=0;j<i;j++)calc((w[i]+w[j])/2+1);
    }
    sort(ans.begin(),ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    int p,q,k,a,b,c;
    cin>>p>>k>>a>>b>>c;
    vector<int> qs;
    ll rans=0;
    for(int i=0;i<p;i++){
        cin>>q;
        qs.emplace_back(q);
    }
    for(int i=p;i<k;i++){
        q=((ll)q*a+b)%c;
        qs.emplace_back(q);
    }
    sort(qs.begin(),qs.end());
    int id=0;
    for(int cq:qs){
        while(id+1<ans.size()&&ans[id+1].first<=cq)id++;
        rans^=ans[id].second.first+(cq-ans[id].first)*(2ll*ans[id].second.second-n+1);
    }
    cout<<rans;

    return 0;
}