#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAX_N=2e3+10;
bool m1[MAX_N];
int n,m,cnt;
vector<int> adj[MAX_N],ts[MAX_N];
void dfs(int v, int cn){
    m1[v]=true;
    if(cnt<cn) cnt=cn;
    for(int i : adj[v]){
        if(!m1[i]) dfs(i,cn+1);
    }
}
int main(){
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        int p;
        cin >> p;
        a[i]=p;
        if(p==-1) continue;
        adj[i].push_back(p-1);
        adj[p-1].push_back(i);
    }
    for(int i=0; i<n; i++){
        if(!m1[i] && a[i]==-1) dfs(i,1);
    }
    cout << cnt;
    return 0;
}