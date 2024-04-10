#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool a[60][60];
vector<int> adj[3000];
vector<int> vis(2600,0);
void dfs(int pos){
    if(vis[pos])return;
    vis[pos]=1;
    for(int x:adj[pos])dfs(x);
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string x;
        cin>>x;
        for(int j=0;j<M;j++)a[i][j]=(x[j]=='#');
    }
    vector<int> nodi;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(a[i][j])nodi.pb(i*M+j);
            if(i+1<N && a[i][j] && a[i+1][j]){
                adj[i*M+j].pb((i+1)*M+j);
                adj[(i+1)*M+j].pb(i*M+j);
            }
            if(j+1<M && a[i][j] && a[i][j+1]){
                adj[i*M+j].pb(i*M+j+1);
                adj[i*M+j+1].pb(i*M+j);
            }
        }
    }
    int mi=1e8;
    if(nodi.size()<3){
        cout<<-1;
        return 0;
    }
    if(nodi.size()>10)mi=2;
    for(int i=0;i<nodi.size();i++){
        fill(vis.begin(),vis.end(),0);
        vis[nodi[i]]=1;
        dfs(i==0?nodi[1]:nodi[0]);
        if(accumulate(vis.begin(),vis.end(),(int)0)!=nodi.size()){
            mi=1;
            break;
        }
    }
    if(mi>1e7 && nodi.size()>2){
        for(int i=0;i<nodi.size();i++){
            for(int j=i+1;j<nodi.size();j++){
                if(count(adj[nodi[i]].begin(),adj[nodi[i]].end(),nodi[j]))continue;
                fill(vis.begin(),vis.end(),0);
                vis[nodi[i]]=1;
                vis[nodi[j]]=1;
                dfs(i==0?(j==1?nodi[2]:nodi[1]):nodi[0]);
                if(accumulate(vis.begin(),vis.end(),(int)0)!=nodi.size()){
                    mi=2;
                    break;
                }
            }   
        }
    }
    if(mi>1e7)cout<<-1;
    else cout<<mi;
}