#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

vc<int> v[2005];
int vis[2005];
int dfs(int a){
    int z=0;
    vis[a]=1;
    for(int x:v[a]){
        if(!vis[x])z=max(z,dfs(x));
    }
    return (z+1);
}
void solve(){
    set<int> boss;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        if(t==-1)boss.insert(i);
        else v[t].pb(i);
    }
    int z=0;
    for(int a:boss){
        z=max(z,dfs(a));
    }
    cout<<z;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}