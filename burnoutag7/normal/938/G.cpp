#include<bits/stdc++.h>
using namespace std;

struct DSU{
    struct node{
        int fa,rk,fe;
        node(){fa=rk=fe=0;}
    };
    vector<node> d;
    int sz;
    stack<pair<int,node>> s;

    DSU(int _sz=0){
        d.resize(sz=_sz+1);
        for(int i=0;i<sz;i++)d[i].fa=i;
    }

    pair<int,int> find(int x){
        if(d[x].fa==x)return make_pair(x,0);
        else{
            auto res=find(d[x].fa);
            res.second^=d[x].fe;
            return res;
        }
    }

    void unite(int x,int y,int v){
        auto p=find(x);
        v^=p.second;
        x=p.first;
        p=find(y);
        v^=p.second;
        y=p.first;
        if(d[x].rk>d[y].rk)swap(x,y);
        s.emplace(x,d[x]);
        d[x].fa=y;
        d[x].fe=v;
        d[y].rk+=d[x].rk==d[y].rk;
    }

    void undo(){
        d[s.top().first]=s.top().second;
        s.pop();
    }
}dsu;

struct LinearBasis{
    int n;
    vector<int> v;
    LinearBasis(int _n=0){
        n=_n;
        v.resize(n);
    }
    void add(int a){
        for(int i=n-1;i>=0;i--)if(a>>i&1){
            if(v[i])a^=v[i];
            else{
                for(int j=i-1;j>=0;j--)if(a>>j&1)a^=v[j];
                for(int j=i+1;j<n;j++)if(v[j]>>i&1)v[j]^=a;
                v[i]=a;
                return;
            }
        }
    }
    int min(int res){
        for(int i=n-1;i>=0;i--)if((res^v[i])<res)res^=v[i];
        return res;
    }
};

struct edge{
    int x,y,d;
    edge(){x=y=d=0;}
    edge(int _x,int _y,int _d):x(_x),y(_y),d(_d){}
};

const int sz=1<<18;
int n,m,q,aid[sz<<1],qx[sz<<1],qy[sz<<1],ans[200005],aq;
map<pair<int,int>,pair<int,int>> mp;
vector<edge> edat[sz<<1];

void addedge(int id,int l,int r,int ql,int qr,const edge &val){
    if(qr<l||r<ql)return;
    if(ql<=l&&r<=qr){
        edat[id].emplace_back(val);
        return;
    }
    addedge(id<<1,l,l+r>>1,ql,qr,val);
    addedge(id<<1|1,(l+r>>1)+1,r,ql,qr,val);
}

void sol(int id,int l,int r,const LinearBasis &flb){
    auto lb=flb;
    int fsz=dsu.s.size();
    for(auto &[x,y,v]:edat[id]){
        if(dsu.find(x).first!=dsu.find(y).first){
            dsu.unite(x,y,v);
        }else{
            lb.add(v^dsu.find(x).second^dsu.find(y).second);
        }
    }
    if(l==r){
        if(aid[id]){
            ans[aid[id]]=lb.min(dsu.find(qx[id]).second^dsu.find(qy[id]).second);
        }
    }else{
        sol(id<<1,l,l+r>>1,lb);
        sol(id<<1|1,(l+r>>1)+1,r,lb);
    }
    while(dsu.s.size()>fsz)dsu.undo();
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    dsu=DSU(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        mp[make_pair(u,v)]=make_pair(1,w);
    }
    cin>>q;
    for(int i=1;i<=q;i++){
        int typ,x,y,d;
        cin>>typ>>x>>y;
        if(typ==1){
            cin>>d;
            mp[make_pair(x,y)]=make_pair(i,d);
        }else if(typ==2){
            auto it=mp.find(make_pair(x,y));
            addedge(1,1,sz,it->second.first,i-1,edge(x,y,it->second.second));
            mp.erase(it);
        }else{
            aid[i+sz-1]=++aq;
            qx[i+sz-1]=x;
            qy[i+sz-1]=y;
        }
    }
    for(auto &[k,v]:mp)addedge(1,1,sz,v.first,sz,edge(k.first,k.second,v.second));
    sol(1,1,sz,LinearBasis(30));
    for(int i=1;i<=aq;i++)cout<<ans[i]<<'\n';

    return 0;
}