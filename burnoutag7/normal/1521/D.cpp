#include<bits/stdc++.h>
using namespace std;

int n;
multiset<int> g[100005];
vector<pair<int,int>> ansr,ansa;

void rmv(int x,int y){
    g[x].erase(y);
    g[y].erase(x);
    ansr.emplace_back(x,y);
}

void add(int x,int y){
    g[x].emplace(y);
    g[y].emplace(x);
    ansa.emplace_back(x,y);
}

void dfs(int x,int p){
    vector<int> e;
    for(int y:g[x])e.emplace_back(y);
    for(int y:e)if(y!=p){
        dfs(y,x);
    }
    if(g[x].size()<=2)return;
    if(p!=-1)rmv(x,p);
    while(g[x].size()>2)rmv(*g[x].begin(),x);
}

void mian(){
    cin>>n;
    ansr.clear();
    ansa.clear();
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].emplace(v);
        g[v].emplace(u);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)if(g[i].size()<=1){
        if(g[i].size()==0){
            add(i,i);
            continue;
        }
        int x=*g[i].begin(),p=i;
        while(g[x].size()>1){
            if(*g[x].begin()==p){
                p=x;
                x=*++g[x].begin();
            }else{
                p=x;
                x=*g[x].begin();
            }
        }
        add(i,x);
    }
    for(int i=0;i+1<ansa.size();i++)ansa[i].second=ansa[i+1].second;
    cout<<ansr.size()<<'\n';
    for(int i=0;i<ansr.size();i++){
        cout<<ansr[i].first<<' '<<ansr[i].second<<' '<<ansa[i].first<<' '<<ansa[i].second<<'\n';
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