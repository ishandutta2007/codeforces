#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;
long long cost[200001];
bool from[200001], to[200001], visited[200001] = {0};
long change[200001][2]={0};
vector<long> edges[200001];
long long ans = 0;

void dfs(long node, long long minCost){
    visited[node] = true;
    long c;
    cost[node] = min(minCost,cost[node]);
    for(long n : edges[node]){
        if(!visited[n]){
            dfs(n,cost[node]);
            change[node][0]+=change[n][0];
            change[node][1]+=change[n][1];
        }
    }
    if(from[node] && !to[node]){
        change[node][0]++;
    }else if(!from[node] && to[node]){
        change[node][1]++;
    }
    c = min(change[node][0],change[node][1]);
    ans+=c*cost[node]*2;
    change[node][0]-=c;
    change[node][1]-=c;

}

int main(){
    ios_base::sync_with_stdio(0);
    long n, u, v, toOne = 0,toZero = 0 ;
    cin>>n;
    for(long i = 1; i <= n; i++){
        cin>>cost[i];
        cin>>from[i];
        cin>>to[i];
        if(from[i] && !to[i])
            toZero++;
        if(!from[i] && to[i])
            toOne++;
    }
    if(toZero != toOne)//no need to continue
    {
        cout<<-1;
        return 0;
    }
    for(long i = 1; i < n; i++){
        cin>>u>>v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1,1000000001);
    cout<<ans;
    return 0;
}