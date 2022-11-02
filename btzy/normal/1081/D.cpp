#include <bits/stdc++.h>
using namespace std;

int ufds_parent[100000];
int ufds_rank[100000];
int specials[100000];

int ufds_root(int x){
    if(ufds_parent[x]==-1){
        return x;
    }
    return ufds_parent[x]=ufds_root(ufds_parent[x]);
}
int ufds_merge(int base, int other){
    if(ufds_rank[base]>ufds_rank[other]){
        ufds_parent[other]=base;
        specials[base]+=specials[other];
        return specials[base];
    }
    else if(ufds_rank[base]<ufds_rank[other]){
        ufds_parent[base]=other;
        specials[other]+=specials[base];
        return specials[other];
    }
    else{
        ufds_parent[other]=base;
        ufds_rank[base]++;
        specials[base]+=specials[other];
        return specials[base];
    }
}

struct edge {
    int u, v, w;
} edges[100000];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m,k;
    cin>>n>>m>>k;
    fill_n(ufds_parent, n, -1);
    int ct=1;
    for(int i=0;i<k;++i){
        int tmp;
        cin>>tmp;
        --tmp;
        specials[tmp]++;
    }
    for(int i=0;i<m;++i){
        cin>>edges[i].u>>edges[i].v>>edges[i].w;
        --edges[i].u;
        --edges[i].v;
    }
    sort(edges,edges+m,[](const edge& a, const edge& b){
        return a.w<b.w;
    });
    int ans;
    for(int i=0;true;++i){
        const edge& e=edges[i];
        int rootu=ufds_root(e.u);
        int rootv=ufds_root(e.v);
        if(rootu!=rootv){
            ++ct;
            if(ufds_merge(rootv, rootu)==k){
                ans=e.w;
                break;
            }
        }
    }
    for(int i=0;i<k;++i)
    cout<<ans<<' ';
    cout<<'\n';
}