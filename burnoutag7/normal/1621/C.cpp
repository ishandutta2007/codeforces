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
};

int ask(int x){
    cout<<"? "<<x<<endl;
    int res;
    cin>>res;
    return res;
}

int n,p[10005];
bool vis[10005];

void mian(){
    cin>>n;
    memset(vis+1,0,n);
    for(int i=1;i<=n;i++)if(!vis[i]){
        vector<int> v(1,ask(i));
        do{
            v.emplace_back(ask(i));
        }while(v.back()!=v.front());
        int len=v.size()-1;
        while(v.size()<2*len)v.emplace_back(ask(i));
        v.resize(len);
        for(int j=0;j<len;j++){
            p[v[j]]=v[(j+1)%len];
            vis[v[j]]=1;
        }
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<p[i]<<' ';
    cout<<endl;
}

int main(){

    ios::sync_with_stdio(false);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}