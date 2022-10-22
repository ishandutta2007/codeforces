#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX_N=50;
bool m1[MAX_N];
int n,m;
vector<int> adj[MAX_N],ts[MAX_N];
int dfs(int v, int tm){
    int cnt=1;
    m1[v]=true;
    ts[tm].push_back(v);

    for(int i : adj[v]){
        if(!m1[i]){
            cnt+=dfs(i,tm);
        }
    }
    return cnt;
}
int main(){
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        if(!m1[i]){
            if(dfs(i,cnt++)>3){
                cout << -1;
                return 0;
            }
        }
    }
    vector< vector<int> > teams[2];
    for(int i=0; i<cnt; i++){
        if(ts[i].size()==1) teams[0].push_back(ts[i]);
        else if(ts[i].size()==2) teams[1].push_back(ts[i]);
    }
    if(teams[1].size() > teams[0].size()){
        cout << -1;
        return 0;
    }
    for(int i=0; i<cnt; i++){
        if(ts[i].size()==3){
            cout << ts[i][0]+1 << ' ' << ts[i][1]+1 << ' ' << ts[i][2]+1 << '\n';
        }
    }
    for(int i=0; i<teams[1].size(); i++){
        cout << teams[0][i][0]+1 << ' ' << teams[1][i][0]+1 << ' ' << teams[1][i][1]+1 << '\n';
    }
    for(int i=teams[1].size(); i<teams[0].size(); i+=3){
        cout << teams[0][i][0]+1 << ' ' << teams[0][i+1][0]+1 << ' ' << teams[0][i+2][0]+1 << '\n';
    }
    return 0;
}