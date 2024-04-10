#include<bits/stdc++.h>
using namespace std;

struct UnionFind{
    int n;
    vector<int> fa;

    UnionFind(int _n=0){
        fa.resize(n=_n);
        iota(fa.begin(),fa.end(),0);
    }

    int find(int x){
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }

    bool unite(int x,int y){
        x=find(x);
        y=find(y);
        fa[x]=y;
        return x!=y;
    }

    void clear(){
        iota(fa.begin(),fa.end(),0);
    }
};

int n,m,ans=0;
UnionFind uf;
char s[1<<12|5];
bool g[1<<14],pg[1<<14];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    uf=UnionFind(m*2);
    for(int i=0;i<n;i++){
        for(int i=0;i<m;i++){
            uf.fa[i+m]=uf.fa[i]+m;
            uf.fa[i]=i;
        }
        swap(pg,g);
        cin>>s;
        for(int i=0;i*4<m;i++){
            int v=isdigit(s[i])?s[i]-'0':s[i]-'A'+10;
            g[i<<2|0]=v>>3&1;
            g[i<<2|1]=v>>2&1;
            g[i<<2|2]=v>>1&1;
            g[i<<2|3]=v>>0&1;
            ans+=__builtin_popcount(v);
        }
        for(int i=1;i<m;i++)if(g[i]&&g[i-1]){
            ans-=uf.unite(i,i-1);
        }
        for(int i=0;i<m;i++)if(g[i]&&pg[i]){
            ans-=uf.unite(uf.find(i+m),i);
        }
    }
    cout<<ans;

    return 0;
}