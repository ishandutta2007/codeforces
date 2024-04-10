#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e6+1;
struct edge{
    int u,v,w;
    edge(){u=0,v=0,w=0;}
    const bool operator<(const edge & rhs) const{
        return rhs.w<w;
    }
};
edge edges[MAXN];
pair<pii,bool> dsu[MAXN];
int find(int a){
    if(dsu[a].first.first==a)return a;
    int rt=find(dsu[a].first.first);
    dsu[a].second=!(dsu[a].second^dsu[dsu[a].first.first].second);
    return dsu[a].first.first=rt;
}
bool sameasparent(int a){
    find(a);
    return dsu[a].second;
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].first.second<dsu[bp].first.second)swap(ap,bp);
    dsu[bp].second=sameasparent(a)^sameasparent(b);
    dsu[ap].first.second+=dsu[bp].first.second;
    dsu[bp].first.first=ap;
    return true;
}
pair<vector<edge>,int> getrange(vector<edge> a,vector<edge> b){
    vector<edge> te(sz(a)+sz(b));
    merge(a.begin(),a.end(),b.begin(),b.end(),te.begin());
    for(auto x:te)dsu[x.u]={{x.u,1},1},dsu[x.v]={{x.v,1},1};
    vector<edge> fin;
    for(auto x:te){
        if(uni(x.u,x.v))fin.push_back(x);
        else if(sameasparent(x.u)==sameasparent(x.v)){
            fin.push_back(x);
            return {fin,x.w};
        }
    }
    return {fin,-1};
}
struct seg{
    pair<vector<edge>,int> t[MAXN];
    void mt(int ind, int le, int ri){
        if(le==ri){
            t[ind]={{edges[le]},-1};
            return;
        }
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        mt(left,le,mid),mt(right,mid+1,ri);
        t[ind]=getrange(t[left].first,t[right].first);
    }
    pair<vector<edge>,int> query(int ind, int le, int ri, int l, int r){
        if(l>ri||r<le)return {{},-1};
        if(le>=l&&ri<=r)return t[ind];
        int mid=(le+ri)/2;
        int left=ind+1,right=ind+(mid-le+1)*2;
        return getrange(query(left,le,mid,l,r).first,query(right,mid+1,ri,l,r).first);
    }
}tree;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,q,m;
    cin>>n>>m>>q;
    for(int i=1;i<=m;i++)cin>>edges[i].u>>edges[i].v>>edges[i].w;
    tree.mt(0,1,m);
    int l,r;
    while(q--){
        cin>>l>>r;
        printf("%d\n",tree.query(0,1,m,l,r).second);
    }
    return 0;
}