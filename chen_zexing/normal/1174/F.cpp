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
#define li __int128_t
using namespace std;
vector <int> v[200005],c[200005];
int fa[200005][20],dep[200005],sz[200005],son[200005],top[200005];
void dfs1(int x,int from){
    fa[x][0]=from,dep[x]=dep[from]+1,sz[x]=1;
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=from) {
            dfs1(v[x][i], x);
            sz[x]+=sz[v[x][i]];
            if(sz[v[x][i]]>sz[son[x]]) son[x]=v[x][i];
        }
}
void dfs2(int x,int ttop){
    top[x]=ttop,c[ttop].push_back(x);
    if(son[x]) dfs2(son[x],ttop);
    for(int i=0;i<v[x].size();i++)
        if(v[x][i]!=son[x]&&v[x][i]!=fa[x][0])
            dfs2(v[x][i],v[x][i]);
}
int query(int x,int type){
    printf("%c %d\n",type==1?'d':'s',x);
    fflush(stdout);
    int t;
    cin>>t;
    if(t==0&&type==1){
        printf("! %d\n",x);
        exit(0);
    }
    return t;
}
int an(int x,int k){
    int now=x;
    for(int i=19;i>=0;i--) if(dep[x]-dep[fa[now][i]]<=k) now=fa[now][i];
    return now;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
        dfs1(1,0);
        dfs2(1,1);
        for(int i=1;i<20;i++)
            for(int j=1;j<=n;j++)
                fa[j][i]=fa[fa[j][i-1]][i-1];
        int now=1;
        int d=query(now,1)+1;
        while(1){
            if(dep[now]==d){
                printf("! %d\n",now);
                return 0;
            }
            int pos=c[now][min(d-dep[now],int(c[now].size()-1))];
            int temp=query(pos,1);
            now=an(pos,(dep[pos]+temp-d)/2);
            now=query(now,2);
        }
    }
    return 0;
}
//
/// 
//01
//
//!