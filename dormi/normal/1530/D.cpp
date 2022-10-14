#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=2e5+1;
int to[MN],ans[MN];
bool cyc[MN];
int type[MN];
vector<int> adj[MN];
vector<int> path;
int am;
bool dfs(int loc){
    type[loc]=1;
    path.push_back(loc);
    for(auto x:adj[loc]){
        if(type[x]==2)continue;
        if(type[x]==1){
            type[x]=2;
            return true;
        }
        if(dfs(x)){
            type[x]=2;
            return true;
        }
    }
    type[loc]=2;
    path.pop_back();
    return false;
}
pii solve(int loc){
    pii cur={loc,loc};
    for(auto x:adj[loc]){
        pii te=solve(x);
        if(cur.first!=loc){
            to[te.second]=cur.first;
            cur.first=te.first;
            am--;
        }
        else{
            cur.first=te.first;
        }
    }
    return cur;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        am=n;
        for(int i=1;i<=n;i++)adj[i]=vector<int>(),type[i]=0,cyc[i]=false;
        for(int i=1;i<=n;i++){
            cin>>to[i];
            adj[to[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            if(!type[i]){
                if(dfs(i)){
                    for(auto x:path){
                        cyc[x]=true;
                    }
                    path=vector<int>();
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(cyc[i]){
                int cur=i;
                int prev;
                for(auto x:adj[i]){
                    if(cyc[x]){
                        prev=x;
                    }
                }
                for(auto x:adj[i]){
                    if(!cyc[x]){
                        pii te=solve(x);
                        to[prev]=te.first;
                        to[te.second]=cur;
                        cur=te.first;
                        am--;
                    }
                }
            }
        }
        printf("%d\n",am);
        for(int i=1;i<=n;i++)printf("%d%c",to[i]," \n"[i==n]);
    }
    return 0;
}