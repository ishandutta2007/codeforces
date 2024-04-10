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
ll p[300005];
vc<int> v[300005];
int vis[300005];
pii dfs(int z,int f){
    vis[z]=f;
    int a=0,b=0;
    for(int i=0;i<v[z].size();i++){
        if(vis[v[z][i]]){
            if(vis[v[z][i]]==f)return {-1,-1};
            else continue;
        }
        pii u=dfs(v[z][i],-f);
        if(u.fr==-1)return {-1,-1};
        a+=u.sc;b+=u.fr;
    }
    return {a+1,b};
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ll abc=1;
    for(int i=0;i<300005;i++){
        p[i]=abc;
        abc*=2;
        abc%=MM;
    }
    int t;
    cin>>t;
    while(t--){
        int n,m;
        ll z=0,y=1;
        cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        for(int i=1;i<=n;i++){
            if(vis[i])continue;
            z=0;
            pii a=dfs(i,1);
            if(a.fr==-1){y=0;break;}
            z+=p[a.fr];z%=MM;
            z+=p[a.sc];z%=MM;
            y*=z;y%=MM;
        }
        cout<<y<<"\n";
        for(int i=1;i<=n;i++){
            v[i].clear();
            vis[i]=0;
        }
    }
}