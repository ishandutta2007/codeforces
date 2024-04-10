#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 111
vector<int>e[SIZE];
long long dp1[SIZE],dp2[SIZE];
int bfs[SIZE],tt,used[SIZE],v1[SIZE],v2[SIZE];
int main(){
    int i,j,k,n,m;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        e[x].pb(y);
        e[y].pb(x);
    }
    bfs[0]=1;
    dp1[1]=1;
    tt++;
    used[1]=tt;
    v1[1]=0;
    for(i=0,j=1;i<j;i++){
        int x=bfs[i];
        for(k=0;k<e[x].size();k++){
            int y=e[x][k];
            if(used[y]!=tt){
                bfs[j++]=y;
                v1[y]=v1[x]+1;
                used[y]=tt;
            }
            if(v1[y]==v1[x]+1)dp1[y]+=dp1[x];
        }
    }
    bfs[0]=n;
    dp2[n]=1;
    tt++;
    used[n]=tt;
    v2[n]=0;
    for(i=0,j=1;i<j;i++){
        int x=bfs[i];
        for(k=0;k<e[x].size();k++){
            int y=e[x][k];
            if(used[y]!=tt){
                bfs[j++]=y;
                v2[y]=v2[x]+1;
                used[y]=tt;
            }
            if(v2[y]==v2[x]+1)dp2[y]+=dp2[x];
        }
    }
    double ma=0;
    for(i=1;i<=n;i++){
        if(v1[i]+v2[i]==v1[n]){
            if(i!=1&&i!=n)ma=max(ma,2.*dp1[i]*dp2[i]/dp1[n]);
            else ma=max(ma,1.*dp1[i]*dp2[i]/dp1[n]);
        }
    }
    printf("%.12lf\n",ma);
    return 0;
}