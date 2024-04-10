#include<bits/stdc++.h>
using namespace std;

struct edge{
    int id,x,y;
    edge(int _id=0,int _x=0,int _y=0):id(_id),x(_x),y(_y){}
    bool operator<(const edge &rhs)const{
        if(id!=rhs.id)return id<rhs.id;
        if(x!=rhs.x)return x<rhs.x;
        return y<rhs.y;
    }
    edge rev(){
        edge res=*this;
        swap(res.x,res.y);
        return res;
    }
};

int m;
string ans[100005];
map<int,set<pair<int,edge>>> g;

void dfs(int x){
    while(!g[x].empty()){
        auto &[_y,_e]=*g[x].begin();
        int y=_y;edge e=_e;
        g[x].erase(g[x].begin());
        g[y].erase(make_pair(x,e.rev()));
        ans[e.id][e.x]='L';
        ans[e.id][e.y]='R';
        dfs(y);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m;
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        ans[i].resize(n);
        map<int,int> unp;
        for(int j=0;j<n;j++){
            int a;
            cin>>a;
            if(unp.count(a)){
                unp.erase(a);
                ans[i][j]='R';
            }else{
                unp.emplace(a,j);
                ans[i][j]='L';
            }
        }
        int pk=-1,pv;
        for(auto &[k,v]:unp){
            if(pk==-1){
                pk=k;pv=v;
            }else{
                g[pk].emplace(k,edge(i,pv,v));
                g[k].emplace(pk,edge(i,v,pv));
                pk=-1;
            }
        }
    }
    vector<int> nds;
    for(auto &[k,v]:g)if(v.size()&1){
        cout<<"NO\n";
        return 0;
    }else nds.emplace_back(k);
    for(int u:nds)dfs(u);
    cout<<"YES\n";
    for(int i=0;i<m;i++)cout<<ans[i]<<'\n';

    return 0;
}