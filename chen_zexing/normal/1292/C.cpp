#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int n,p1,p2;
vector <int> v[3005],s[3005];
int sz[3005],f[3005],dep[3005],fa[3005],son[3005],top[3005],to[3005][3005],ssz[3005][3005];
long long dp[3005][3005];
long long ans;
void dfs1(int x,int from){
    sz[x]=1;
    dep[x]=dep[from]+1;
    fa[x]=from;
    s[x].push_back(x);
    int mx=0;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from) {
            dfs1(v[x][i], x), sz[x] += sz[v[x][i]];
            for(int j=0;j<s[v[x][i]].size();j++){
                s[x].push_back(s[v[x][i]][j]),to[x][s[v[x][i]][j]]=v[x][i],to[s[v[x][i]][j]][x]=fa[s[v[x][i]][j]];
                ssz[x][s[v[x][i]][j]]=sz[s[v[x][i]][j]],ssz[s[v[x][i]][j]][x]=n-sz[v[x][i]];
            }
            dp[x][v[x][i]]=dp[v[x][i]][x]=1LL*sz[v[x][i]]*(n-sz[v[x][i]]);
            if(sz[v[x][i]]>mx){
                mx=sz[v[x][i]],son[x]=v[x][i];
            }
        }
}
void dfs2(int x,int ttop){
    top[x]=ttop;
    if(son[x]) dfs2(son[x],ttop);
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=fa[x]&&v[x][i]!=son[x])
            dfs2(v[x][i],v[x][i]);
}
int lca(int x,int y){
    while(top[x]!=top[y]){
        if(dep[fa[top[x]]]>dep[fa[top[y]]]) x=fa[top[x]];
        else y=fa[top[y]];
    }
    return dep[x]<dep[y]?x:y;
}
long long cal(int x,int y){
    if(x>y) swap(x,y);
    if(dp[x][y]!=-1) return dp[x][y];
    int l=lca(x,y);
    if(l==x||l==y) return dp[x][y]=dp[y][x]=max(cal(to[x][y],y),cal(to[y][x],x))+1LL*ssz[y][x]*ssz[x][y];
    else return dp[x][y]=dp[y][x]=max(cal(fa[x],y),cal(fa[y],x))+1LL*sz[x]*sz[y];
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        cin>>n;
        for(int i=1,x,y;i<n;i++){
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        memset(dp,-1,sizeof(dp));
        dfs1(1,0);
        dfs2(1,1);
        /*
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cout<<i<<" "<<j<<" "<<to[i][j]<<" "<<to[j][i]<<" "<<ssz[i][j]<<" "<<ssz[j][i]<<endl;
        for(int i=1;i<=n;i++) cout<<i<<" "<<sz[i]<<" "<<fa[i]<<endl;
         */
        long long ans=0;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++) {
                ans = max(ans, cal(i, j));
                //cout << i << " " << j << " " << dp[i][j] << endl;
            }
        cout<<ans<<endl;
    }
    return 0;
}