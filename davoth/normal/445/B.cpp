#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX_N=1e5;
bool m1[52];
int cnt=0;
vector<int> adj[52];
void dfs(int v){
    m1[v]=1;
    for(int i=0; i<adj[v].size(); i++){
        if(!m1[adj[v][i]]){
            dfs(adj[v][i]);
        }
    }
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);
    }
    for(int i=0; i<n; i++){
        if(!m1[i]){
            cnt--;
            dfs(i);
        }
    }
    cout << (ll)pow(2,n+cnt);
    return 0;
}