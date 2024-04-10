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
int c[4][100005];
vector <int> v[100005];
long long ans=LLONG_MAX,op,stt;
void dfs(int st, int x,int from,int t,long long now){
    now+=c[t][x];
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=from) dfs(st,v[x][i],x,t%3+1,now);
    if(v[x].size()==1&&x!=st){
        ans=min(now,ans);
        if(ans==now) op=t,stt=st;
    }
}
int pp[100005];
void dfs2(int x,int from,int t){
    pp[x]=t;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=from) dfs2(v[x][i],x,t+2-3*(t>1));
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&c[1][i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[2][i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[3][i]);
        int f=1,p=-1;
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
            if(v[x].size()>2||v[y].size()>2) f=0;
        }
        if(!f){
            puts("-1");
            continue;
        }
        for(int i=1;i<=n;i++)
            if(v[i].size()==1)
                p=i;
        for(int i=1;i<=3;i++) dfs(p,p,0,i,0);
        int p2=-1;
        for(int i=1;i<=n;i++)
            if(v[i].size()==1&&i!=p)
                p2=i;
        for(int i=1;i<=3;i++) dfs(p2,p2,0,i,0);
        printf("%lld\n",ans);
        if(stt==p) dfs2(p2,0,op);
        else dfs2(p,0,op);
        for(int i=1;i<=n;i++) printf("%d ",pp[i]);
    }
    return 0;
}