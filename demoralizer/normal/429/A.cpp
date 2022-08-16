#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)                   (x).begin(),(x).end()
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
    if(b%2)return (((a*t)%p)*t)%p;
    else return ((t*t)%p);
}

vc<int> v[100005],ans;int vis[100005],init[100005],goal[100005];
void dfs(int z,int a,int b,int l){
    vis[z]=1;
    if((l==0&&a==1)||(l==1&&b==1))init[z]^=1;
    if(init[z]!=goal[z]){
        if(l==0)a^=1;
        else b^=1;
        ans.pb(z);
    }
    for(int i:v[z]){
        if(vis[i])continue;
        dfs(i,a,b,1-l);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        cin>>init[i];
    }
    for(int i=1;i<=n;i++){
        cin>>goal[i];
    }
    dfs(1,0,0,0);
    cout<<ans.size();
    for(int i:ans)cout<<"\n"<<i;
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