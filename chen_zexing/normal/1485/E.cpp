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
long long ans[200005];
int w[200005],dep[200005],fa[200005];
vector <int> v[200005];
vector <int> bl[200005];
int mxdep;
void dfs(int x,int from){
    dep[x]=dep[from]+1;
    fa[x]=from;
    mxdep=max(mxdep,dep[x]);
    bl[dep[x]].push_back(x);
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from)
            dfs(v[x][i],x);
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        mxdep=0;
        cin>>n;
        for(int i=1;i<=n;i++) v[i].clear(),bl[i].clear(),ans[i]=0;
        for(int i=2;i<=n;i++){
            int t;
            scanf("%d",&t);
            v[t].push_back(i);
            v[i].push_back(t);
        }
        for(int i=2;i<=n;i++) scanf("%d",&w[i]);
        dfs(1,0);
        long long aans=0;
        for(int i=2;i<=mxdep;i++){
            long long mx1=INT_MIN,mx2=INT_MIN;
            int mx=0,mn=INT_MAX;
            //cout<<bl[i].size();
            for(int j=0;j<bl[i].size();j++) mx1=max(mx1,ans[fa[bl[i][j]]]+w[bl[i][j]]),mx2=max(mx2,ans[fa[bl[i][j]]]-w[bl[i][j]]),mx=max(mx,w[bl[i][j]]),mn=min(mn,w[bl[i][j]]);
            //cout<<mn<<" "<<mx<<endl;
            for(int j=0;j<bl[i].size();j++){
                int t=bl[i][j];
                ans[t]=ans[fa[t]]+max(w[t]-mn,mx-w[t]);
                //cout<<ans[t]<<" "<<t<<endl;
                ans[t]=max(ans[t],mx1-w[t]);
                ans[t]=max(ans[t],mx2+w[t]);
                aans=max(aans,ans[t]);
                //cout<<ans[t]<<" "<<t<<endl;
            }
        }
        printf("%lld\n",aans);
    }
    return 0;
}