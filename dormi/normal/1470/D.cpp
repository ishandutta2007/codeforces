#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
vector<int> adj[MN];
bool inset[MN];
pii dsu[MN];
int find(int a){
    if(dsu[a].first==a)return a;
    return dsu[a].first=find(dsu[a].first);
}
bool uni(int a, int b){
    int ap=find(a),bp=find(b);
    if(ap==bp)return false;
    if(dsu[ap].second<dsu[bp].second)swap(ap,bp);
    dsu[ap].second+=dsu[bp].second;
    dsu[bp].first=ap;
    return true;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        for(int i=1;i<=n;i++)adj[i]=vector<int>(),dsu[i]={i,1},inset[i]=false;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            uni(a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        if(dsu[find(1)].second!=n){
            printf("NO\n");
        }
        else{
            printf("YES\n");
            vector<int> chosen;
            set<int> q;
            auto addnonpick=[&](int cur){
                inset[cur]=true;
                for(auto x:adj[cur]){
                    if(!inset[x]){
                        q.insert(x);
                    }
                }
            };
            auto addpick=[&](int cur){
                inset[cur]=true;
                for(auto x:adj[cur]){
                    if(!inset[x]){
                        addnonpick(x);
                    }
                }
            };
            addpick(1);
            chosen.push_back(1);
            while(sz(q)){
                auto loc=*q.begin();
                q.erase(q.begin());
                if(inset[loc])continue;
                chosen.push_back(loc);
                addpick(loc);
            }
            printf("%d\n",sz(chosen));
            for(auto x:chosen)printf("%d ",x);
            printf("\n");
        }
    }
    return 0;
}