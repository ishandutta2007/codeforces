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
vector <int> v[200005];
int f[200005],a,b;
void dfs1(int x,int from){
    if(x==b||f[x]) return;
    f[x]=1;
    for(int i=0;i<v[x].size();i++) dfs1(v[x][i],from);
}
void dfs2(int x,int from){
    if(x==a||f[x]) return;
    f[x]=1;
    for(int i=0;i<v[x].size();i++) dfs2(v[x][i],from);
}
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m>>a>>b;
        for(int i=1;i<=n;i++) v[i].clear(),f[i]=0;
        for(int i=1;i<=m;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs1(a,0);
        int cnt1=-1;
        for(int i=1;i<=n;i++)
            if(f[i])
                cnt1++,f[i]=0;
        dfs2(b,0);
        int cnt2=-1;
        for(int i=1;i<=n;i++)
            if(f[i])
                cnt2++,f[i]=0;
        int tt=cnt1+cnt2-n+2;
        int ta=cnt1-tt,tb=cnt2-tt;
        printf("%lld\n",1LL*ta*tb);
    }
    return 0;
}