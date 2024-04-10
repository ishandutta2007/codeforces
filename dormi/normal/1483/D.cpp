#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=601;
ll dist[MN][MN];
vector<pair<int,ll>> adj[MN];
vector<pair<int,ll>> queries[MN];
ll tocheck[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m,a,b,q;
    cin>>n>>m;
    ll w;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)dist[i][j]=INT_MAX;
        dist[i][i]=0;
    }
    for(int i=0;i<m;i++){
        cin>>a>>b>>w;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
        if(a!=b) {
            dist[a][b] = w;
            dist[b][a] = w;
        }
    }
    for(int mid=1;mid<=n;mid++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][mid]+dist[mid][j]);
            }
        }
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b>>w;
        queries[a].push_back({b,w});
        queries[b].push_back({a,w});
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)tocheck[j]=-1;
        for(int j=1;j<=n;j++){
            for(auto x:queries[j]){
                tocheck[x.first]=max(tocheck[x.first],x.second-dist[j][i]);
            }
        }
        for(auto x:adj[i]){
            for(int j=1;j<=n;j++){
                if(tocheck[j]>=x.second+dist[x.first][j]){
                    cnt++;
                    break;
                }
            }
        }
    }
    printf("%d\n",cnt/2);
    return 0;
}