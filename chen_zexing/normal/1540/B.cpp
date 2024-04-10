#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
long long p[205][205],mod=1000000007,inv2;
int dep[205],fa[205][10];
vector <int> v[205];
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
long long solve(int x,int y){
    if(p[x][y]!=-1) return p[x][y];
    if(x==0) return p[x][y]=1;
    if(y==0) return p[x][y]=0;
    return p[x][y]=(solve(x,y-1)*inv2%mod+solve(x-1,y)*inv2%mod)%mod;
}
void dfs(int x,int from){
    dep[x]=dep[from]+1;
    fa[x][0]=from;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=from) dfs(v[x][i],x);
}
int lca(int x,int y){
    //cout<<x<<" "<<y<<" ";
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=9;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    //cout<<x<<" "<<y<<endl;
    if(x==y){
        return x;
    }
    for(int i=9;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        memset(p,-1,sizeof(p));
        long long ans=0;
        cin>>n;
        dep[0]=-1;
        inv2=qpow(2,mod-2);
        for(int i=1,x,y;i<n;i++) cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
        for(int i=1;i<=n;i++){
            long long temp=0;
            dfs(i,0);
            //cout<<"#"<<" "<<i<<endl;
            for(int k=1;k<10;k++) for(int j=1;j<=n;j++) fa[j][k]=fa[fa[j][k-1]][k-1];
            //if(i==3) for(int j=1;j<=n;j++,puts("")) for(int k=0;k<10;k++) cout<<j<<" "<<k<<" "<<fa[j][k]<<endl;
            for(int j=1;j<=n;j++)
                for(int k=j+1;k<=n;k++){
                    int l=lca(j,k);
                    //if(i==3) cout<<j<<" "<<k<<" "<<l<<endl;
                    if(l==k) temp++;
                    else if(l==j) continue;
                    else temp+=solve(dep[k]-dep[l],dep[j]-dep[l]);
                    //if(i==3) cout<<temp*4%mod<<endl;
                    temp%=mod;
                }
            //cout<<temp*4%mod<<" "<<temp<<endl;
            ans+=temp*qpow(n,mod-2)%mod,ans%=mod;
            //cout<<temp<<" "<<ans<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp