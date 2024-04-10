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
#include<queue>
#define pb push_back
using namespace std;
int n,d[500001];
char s0[15][12];
bool fresh(int &x,int v){
    if(x<v){
        x=v;
        return 1;
    }
    return 0;
}
int find(char ss[]){
    for(int i=0;i<n;i++)
        if(strcmp(ss,s0[i])==0)return i;
    return -1;
}
int next[500001][15],tt,mi[1<<15][106];
int go(){
    int dn=0,m,i,j,k,res=-1;
    char ss[12];
    scanf("%d",&m);
    for(i=0;i<m;i++){
        scanf("%s",ss);
        int tmp=find(ss);
        if(tmp>=0)d[dn++]=tmp;
    }
    if(dn<n)return 0;
    memset(mi,-1,sizeof(mi));
    for(i=0;i<n;i++)next[dn][i]=-1;
    for(i=dn-1;i>=0;i--){
        for(j=0;j<n;j++)next[i][j]=next[i+1][j];
        next[i][d[i]]=i;
    }
    mi[0][0]=0;
    for(i=0;i<(1<<n);i++){
        for(j=0;j<=n*(n-1)/2;j++){
            if(mi[i][j]!=-1){
                if(i==(1<<n)-1){
                    res=max(res,j);
                    continue;
                }
                int cnt=0;
                for(k=0;k<n;k++){
                    if((i>>k)&1)cnt++;
                    else{
                        if(next[mi[i][j]][k]!=-1&&(mi[i|(1<<k)][j+cnt]==-1||mi[i|(1<<k)][j+cnt]>next[mi[i][j]][k]+1))
                            mi[i|(1<<k)][j+cnt]=next[mi[i][j]][k]+1;
                    }
                }
            }
        }
    }
    return res+1;
}
int main(){
    int i,j,k,m;
    while(scanf("%d",&n)==1){
        for(i=0;i<n;i++)scanf("%s",s0[i]);
        scanf("%d",&m);
        int ma=0,No;
        for(k=1;k<=m;k++){
            if(fresh(ma,go())){
                No=k;
            }
        }
        if(ma==0)puts("Brand new problem!");
        else{
            printf("%d\n[:",No);
            for(i=0;i<ma;i++)printf("|");
            puts(":]");
        }
    }
    return 0;
}