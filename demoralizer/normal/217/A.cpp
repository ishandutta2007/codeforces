#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}

int vis[1004][2];
map<int,vc<int> > vx,vy;
void dfs(int z,int r){
    vis[z][r]=1;
    if(r==1)
    for(int i:vx[z]){
        if(vis[i][1-r])continue;
        dfs(i,1-r);
    }
    else
    for(int i:vy[z]){
        if(vis[i][1-r])continue;
        dfs(i,1-r);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        vx[x].pb(y);
        vy[y].pb(x);
    }
    int c=0;
    for(auto uuu:vx){
        if(vis[uuu.fr][1])continue;
        c++;
        dfs(uuu.fr,1);
    }
    cout<<(c-1);
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