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
vector <int> bl[300005];
long long fa[600005],sz[600005][2],d[300005],lim[300005];
char s[300005];
int find(int x){
    if(fa[x]==x) return x;
    int ff=find(fa[x]);
    d[x]+=d[fa[x]];
    fa[x]=ff;
    return ff;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,k;
        scanf("%d%d\n",&n,&k);
        scanf("%s",s+1);
        //cout<<strlen(s+1)<<endl;
        for(int i=1;i<=k;i++) fa[i]=i,sz[i][0]=0,sz[i][1]=1,lim[i]=0;
        //cout<<k<<endl;
        for(int i=1,t;i<=k;i++){
            scanf("%d",&t);
            for(int j=1,x;j<=t;j++){
                scanf("%d",&x);
                bl[x].push_back(i);
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(bl[i].size()==0){
                printf("%d\n",ans);
                continue;
            }
            if(bl[i].size()==1){
                int x=find(bl[i][0]);
                //cout<<"#"<<x<<" "<<bl[i][0]<<endl;
                if(lim[x]==0) {
                    ans-=min(sz[x][0],sz[x][1]);
                    if (d[bl[i][0]] % 2) sz[x]['1'-s[i]] = INT_MAX / 10;
                    else sz[x][s[i]-'0'] = INT_MAX / 10;
                    lim[x]=1;
                    ans+=min(sz[x][0],sz[x][1]);
                    //cout<<sz[x][0]<<" "<<sz[x][1]<<endl;
                }
            }
            else{
                int x=find(bl[i][0]),y=find(bl[i][1]);
                int dx=d[bl[i][0]],dy=d[bl[i][1]];
                if(x!=y) {
                    ans-=min(sz[x][0],sz[x][1]);
                    ans-=min(sz[y][0],sz[y][1]);
                    fa[y] = x;
                    //cout<<'#'<<ans<<endl;
                    //cout<<'#'<<sz[x][0]<<" "<<sz[x][1]<<endl;
                    //cout<<'#'<<sz[y][0]<<" "<<sz[y][1]<<endl;
                    if (((dx - dy - s[i] - '0')%2+2)%2==0) d[y]++, sz[x][0] += sz[y][1], sz[x][1] += sz[y][0];
                    else sz[x][0] += sz[y][0], sz[x][1] += sz[y][1];
                    ans+=min(sz[x][0],sz[x][1]);
                    if(lim[x]||lim[y]) lim[x]=1;
                }
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp