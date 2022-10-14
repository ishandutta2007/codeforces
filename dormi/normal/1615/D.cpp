#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define A first
#define B second
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
vector<pii> adj[MN];
pii dsu[MN];
void reset(int n){
    for(int i=0;i<=n;i++)dsu[i]={i,1};
}
int find(int a){
    if(dsu[a].first==a)return a;
    int te=find(dsu[a].first);
    if(te==dsu[a].first)dsu[a].second^=0;
    else dsu[a].second^=dsu[dsu[a].first].second;
    return dsu[a].first=te;
}
int get(int a){
    if(find(a)==a)return 0;
    return dsu[a].second;
}
bool uni(int a, int b, int c){
    int ap=find(a),bp=find(b);
    if(ap==bp){
        return (get(b)^get(a))==c;
    }
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp),swap(a,b);
    int te=c^get(a)^get(b);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    dsu[bp].second=te;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b,c;
        cin>>n>>m;
        reset(n);
        for(int i=1;i<=n;i++)adj[i]=vector<pii>();
        vector<pair<pii,int>> edges;
        for(int i=1;i<n;i++){
            cin>>a>>b>>c;
            edges.push_back({{a,b},c});
            if(c==-1)continue;
            uni(a,b,__builtin_popcount(c)%2);
        }
        bool work=true;
        for(int i=1;i<=m;i++){
            cin>>a>>b>>c;
            if(!uni(a,b,c)){
                work=false;
            }
        }
        if(!work){
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        for(auto x:edges){
            if(x.second==-1){
                if(uni(x.first.first,x.first.second,0)){
                    printf("%d %d %d\n",x.first.first,x.first.second,0);
                }
                else{
                    uni(x.first.first,x.first.second,1);
                    printf("%d %d %d\n",x.first.first,x.first.second,1);
                }
            }
            else printf("%d %d %d\n",x.first.first,x.first.second,x.second);
        }
    }
    return 0;
}