#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define psi pair<string,int>
int a[100005],vis[100005];
int c=0,m;
vc<int> v[100005];
void dfs(int z,int r){
    vis[z]=1;
    int t=(a[z]==0)?0:(r+1),k=0;
    if(t>m)return;
    for(int i=0;i<v[z].size();i++){
        if(vis[v[z][i]])continue;
        k++;
        dfs(v[z][i],t);
    }
    if(k==0)c++;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    cout<<c;
}