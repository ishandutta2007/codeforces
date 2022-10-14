#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
const int MAXN=2e5+1;
pii dsu[MAXN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
void uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
}
map<int,vector<pii>> edges;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=n;i++)dsu[i]={i,1};
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        edges[w].push_back({u,v});
    }
    int cost=0;
    for(auto x:edges){
        vector<pii> good;
        for(auto y:x.second){
            if(find(y.first)!=find(y.second))good.push_back(y);
        }
        for(auto y:good){
            if(find(y.first)==find(y.second))cost++;
            else uni(y.first,y.second);
        }
    }
    printf("%d\n",cost);
    return 0;
}