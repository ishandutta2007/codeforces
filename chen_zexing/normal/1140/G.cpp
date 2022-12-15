#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
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
#define li __int128_t
#define ull unsigned long long
using namespace std;
int fa[300005][20],dep[300005];
long long oth[300005];
long long cost[300005][20][2][2];
struct edge{
    long long ed,w0,w1;
};
vector <edge> v[300005];
void dfs1(int x,int from){
    fa[x][0]=from,dep[x]=dep[from]+1;
    for(auto t:v[x])
        if(t.ed!=from)
            dfs1(t.ed,x),oth[x]=min(oth[x],oth[t.ed]+t.w0+t.w1);
}
void dfs2(int x,int from){
    for(auto t:v[x])
        if(t.ed!=from)
            oth[t.ed]=min(oth[t.ed],oth[x]+t.w0+t.w1),dfs2(t.ed,x);
}
void dfs3(int x,int from){
    for(auto t:v[x])
        if(t.ed!=from){
            cost[t.ed][0][0][0]=min(t.w0,t.w1+oth[t.ed]+oth[x]);
            cost[t.ed][0][1][1]=min(t.w1,t.w0+oth[t.ed]+oth[x]);
            cost[t.ed][0][1][0]=min(t.w0+oth[t.ed],oth[x]+t.w1);
            cost[t.ed][0][0][1]=min(t.w1+oth[t.ed],oth[x]+t.w0);
            dfs3(t.ed,x);
        }
}
int lca(int x,int y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i=19;i>=0;i--) if(dep[fa[x][i]]>=dep[y]) x=fa[x][i];
    if(x==y) return x;
    for(int i=19;i>=0;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
    return fa[x][0];
}
long long tempans[300005][2][2];
void solve(int x,int tar,int st,int ttar){
    if(dep[x]==dep[tar]){
        tempans[x][ttar][ttar]=0,tempans[x][ttar^1][ttar]=oth[x];
        return;
    }
    for(int i=st;i>=0;i--) if(dep[fa[x][i]]>=dep[tar]){
            solve(fa[x][i],tar,i-1,ttar);
            for(int j=0;j<2;j++) tempans[x][j][ttar]=min(cost[x][i][j][0]+tempans[fa[x][i]][0][ttar],cost[x][i][j][1]+tempans[fa[x][i]][1][ttar]);
            return;
        }
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        long long x,y,w1,w2;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&oth[i]);
        for(int i=1;i<n;i++){
            scanf("%lld%lld%lld%lld",&x,&y,&w1,&w2);
            v[x].push_back(edge{y,w1,w2});
            v[y].push_back(edge{x,w1,w2});
        }
        dfs1(1,0),dfs2(1,0),dfs3(1,0);
        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++)
                fa[j][i]=fa[fa[j][i-1]][i-1];
        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++)
                for(int k=0;k<2;k++)
                    for(int l=0;l<2;l++)
                        cost[j][i][k][l]=min(cost[j][i-1][k][0]+cost[fa[j][i-1]][i-1][0][l],cost[j][i-1][k][1]+cost[fa[j][i-1]][i-1][1][l]);
        int q;
        cin>>q;
        for(int i=1,p1,p2,t1,t2;i<=q;i++){
            scanf("%lld%lld",&x,&y);
            p1=(x+1)/2,t1=(x+1)%2,p2=(y+1)/2,t2=(y+1)%2;
            //cout<<p1<<" "<<t1<<" "<<p2<<" "<<t2<<endl;
            int l=lca(p1,p2);
            solve(p1,l,19,0),solve(p2,l,19,0),solve(p1,l,19,1),solve(p2,l,19,1);
            printf("%lld\n",min(tempans[p1][t1][0]+tempans[p2][t2][0],tempans[p1][t1][1]+tempans[p2][t2][1]));
            //cout<<solve(p1,l,19,t1,0)+solve(p2,l,19,t2,0)<<" "<<solve(p1,l,19,t1,1)+solve(p2,l,19,t2,1)<<endl;
        }
    }
    return 0;
}
//
/// 
//01
//