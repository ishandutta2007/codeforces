#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int sz,tot;
    vector<int> fa;

    UnionFind(){
        tot=sz=100000;
        fa.resize(sz);
        iota(fa.begin(),fa.end(),0);
    }

    UnionFind(const int &_sz){
        tot=sz=_sz;
        fa.resize(sz);
        iota(fa.begin(),fa.end(),0);
    }

    int find(const int &x){
        if(fa[x]==x)return x;
        else return fa[x]=find(fa[x]);
    }

    bool unite(int x,int y){
        x=find(x);
        y=find(y);
        if(fa[y]==x)return false;
        tot--;
        fa[y]=x;
        return true;
    }
};

int n,m,G,S;
long long ans=LLONG_MAX;
vector<pair<pair<int,int>,pair<int,int>>> eg,es;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>G>>S;
    eg.resize(m);
    for(int i=0;i<m;i++){
        cin>>eg[i].first.first>>eg[i].first.second>>eg[i].second.first>>eg[i].second.second;
        eg[i].first.first--;
        eg[i].first.second--;
    }
    sort(eg.begin(),eg.end(),[](const pair<pair<int,int>,pair<int,int>> &a,const pair<pair<int,int>,pair<int,int>> &b){
        if(a.second.first!=b.second.first)return a.second.first<b.second.first;
        if(a.second.second!=b.second.second)return a.second.second<b.second.second;
        if(a.first.first!=b.first.first)return a.first.first<b.first.first;
        return a.first.second<b.first.second;
    });
    for(int i=1;i<=m;i++){
        long long res=0;
        if(i){
            es.insert(lower_bound(es.begin(),es.end(),eg[i-1],[](const pair<pair<int,int>,pair<int,int>> &a,const pair<pair<int,int>,pair<int,int>> &b){
                if(a.second.second!=b.second.second)return a.second.second<b.second.second;
                if(a.second.first!=b.second.first)return a.second.first<b.second.first;
                if(a.first.first!=b.first.first)return a.first.first<b.first.first;
                return a.first.second<b.first.second;
            }),eg[i-1]);
            res=(long long)eg[i-1].second.first*G;
        }
        UnionFind uf(n);
        for(int j=0;j<es.size();j++){
            long long cur=(long long)es[j].second.second*S;
            if(!uf.unite(es[j].first.first,es[j].first.second)){
                es.erase(es.begin()+j);
                j--;
            }
            if(uf.tot==1)ans=min(ans,res+cur);
        }
    }
    if(ans==LLONG_MAX)ans=-1;
    cout<<ans<<endl;

    return 0;
}