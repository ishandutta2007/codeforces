#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
vector<int> matrix[MAXN];
int dist[MAXN];
void dfs(int loc, int parent){
    dist[loc]=dist[parent]+1;
    for(auto x:matrix[loc])if(x!=parent)dfs(x,loc);
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,a,b,da,db;
        cin>>n>>a>>b>>da>>db;
        for(int i=1;i<=n;i++)matrix[i]=vector<int>();
        int x,y;
        for(int i=0;i<n-1;i++){
            cin>>x>>y;
            matrix[x].push_back(y);
            matrix[y].push_back(x);
        }
        if(2*da>=db){
            printf("Alice\n");
            continue;
        }
        dist[0]=-1;
        dfs(a,0);
        if(dist[b]<=da){
            printf("Alice\n");
            continue;
        }
        pii ma={0,-1};
        for(int i=1;i<=n;i++){
            if(dist[i]>ma.second){
                ma={i,dist[i]};
            }
        }
        dfs(ma.first,0);
        ma={0,-1};
        for(int i=1;i<=n;i++){
            if(dist[i]>ma.second){
                ma={i,dist[i]};
            }
        }
        if(2*da<ma.second){
            printf("Bob\n");
        }
        else printf("Alice\n");
    }
    return 0;
}