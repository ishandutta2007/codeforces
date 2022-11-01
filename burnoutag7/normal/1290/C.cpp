#include<bits/stdc++.h>
using namespace std;

struct dsu{
    int n;
    vector<int> fa,eq,neq,wt,must;

    dsu(int sz){
        n=sz;
        fa.resize(n);
        iota(fa.begin(),fa.end(),0);
        eq.assign(n,1);
        neq.assign(n,0);
        wt.assign(n,0);
        must.assign(n,-1);
    }

    int find(int x){
        if(x==fa[x])return x;
        int root=find(fa[x]);
        wt[x]^=wt[fa[x]];
        fa[x]=root;
        return fa[x];
    }

    bool unite(int x,int y,int z){
        x=find(x);
        y=find(y);
        if(x!=y){
            fa[x]=y;
            wt[x]=z;
            if(z==0){
                eq[y]+=eq[x];
                neq[y]+=neq[x];
            }else{
                eq[y]+=neq[x];
                neq[y]+=eq[x];
            }
            if(must[x]!=-1){
                must[y]=must[x]^wt[x];
            }
            return true;
        }
        return false;
    }
};

int eval(dsu &d,int x){
    if(d.must[x]==0)return d.neq[x];
    if(d.must[x]==1)return d.eq[x];
    return min(d.eq[x],d.neq[x]);
}

int n,k;
string s;
vector<int> g[300005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    dsu d(k);
    cin>>s;
    for(int i=0;i<k;i++){
        int c;
        cin>>c;
        for(int j=0;j<c;j++){
            int t;
            cin>>t;
            t--;
            g[t].push_back(i);
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(g[i].size()==1){
            int v=g[i][0],root=d.find(v);
            ans-=eval(d,root);
            d.must[root]=!(s[i]=='1')^d.wt[v];
            ans+=eval(d,root);
        }else
        if(g[i].size()==2){
            int u=g[i][0],v=g[i][1],rootu=d.find(u),rootv=d.find(v);
            if(rootu!=rootv){
                ans-=eval(d,rootu);
                ans-=eval(d,rootv);
                d.unite(rootv,rootu,(s[i]=='0')^d.wt[v]^d.wt[u]);
                ans+=eval(d,rootu);
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}