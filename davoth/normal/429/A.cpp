#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX_N=1e5+10;
bool m1[MAX_N];
int in[MAX_N],goal[MAX_N];
int n;
vector<int> adj[MAX_N],moves;
void dfs(int v, int lvl, int odd, int even){
    m1[v]=true;
    int k=even;
    if(lvl%2==1) k=odd;
    if((in[v]+k)%2!=goal[v] && lvl%2==1) odd++,in[v]=1-in[v],moves.push_back(v);
    if((in[v]+k)%2!=goal[v] && lvl%2==0) even++,in[v]=1-in[v],moves.push_back(v);
    for(int i : adj[v]){
        if(!m1[i]) dfs(i,lvl+1,odd,even);
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n-1; i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<n; i++) cin >> in[i];
    for(int i=0; i<n; i++) cin >> goal[i];
    dfs(0,0,0,0);
    cout << moves.size() << '\n';
    for(int i=0; i<moves.size(); i++){
        cout << moves[i]+1 << '\n';
    }
    return 0;
}