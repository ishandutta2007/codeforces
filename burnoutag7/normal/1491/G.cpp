//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,c[200005];
vector<pair<int,int>> ans;
bool vis[200005];

void swp(int u,int v){
    tie(c[u],c[v])=make_pair(-c[v],-c[u]);
    ans.emplace_back(u,v);
}

void cycswp(int u,int v){
    swp(u,v);
    int x=u;
    while(c[-c[x]]>0)swp(x,-c[x]);
    x=-c[x];
    while(c[-c[x]]>0)swp(x,-c[x]);
    swp(x,-c[x]);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>c[i];
    int p=-1;
    for(int i=1;i<=n;i++)if(!vis[i]&&c[i]!=i){
        int x=i;
        do vis[x=c[x]]=true;
        while(x!=i);
        if(p==-1)p=i;
        else cycswp(p,i),p=-1;
    }
    if(p!=-1){
        bool f=true;
        for(int i=1;i<=n;i++)if(c[i]==i){
            cycswp(p,i);
            f=false;
            break;
        }
        if(f){
            int x=c[p],y=c[c[p]];
            swp(p,x);
            cycswp(x,y);
        }
    }
    cout<<ans.size()<<'\n';
    for(pair<int,int> &p:ans)cout<<p.first<<' '<<p.second<<'\n';

    return 0;
}