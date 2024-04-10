#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int sz;
    vector<int> fa;

    UnionFind(int _sz=100000){
        fa.resize((sz=_sz)+1);
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
};

int n,m,p[300005],ori[300005];
vector<int> v[300005];

bool check(int x){
    for(int i=0;i<n;i++)ori[(i+x)%n]=i;
    UnionFind uf(n);
    for(int i=0;i<n;i++){
        uf.unite(p[i],ori[i]);
    }
    vector<int> sz(n,0);
    for(int i=0;i<n;i++)sz[uf.find(i)]++;
    int res=0;
    for(int i=0;i<n;i++)if(uf.find(i)==i)res+=sz[i]-1;
    return res<=m;
}

void mian(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        v[i].clear();
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
        p[i]--;
        v[(p[i]-i+n)%n].emplace_back(i);
    }
    vector<int> ansv;
    for(int i=0;i<n;i++)if(v[i].size()>=n-m*2){
        if(check((n-i)%n))ansv.emplace_back((n-i)%n);
    }
    sort(ansv.begin(),ansv.end());
    cout<<ansv.size()<<' ';
    for(int x:ansv)cout<<x<<' ';
    cout<<'\n';
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