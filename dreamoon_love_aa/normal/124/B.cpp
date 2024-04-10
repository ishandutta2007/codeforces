#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
char s[16][16];
int ten[8]={1,10,100,1000,10000,100000,1000000,10000000},used[8],d[8],an,k,n;
void dfs(int x){
    if(x==k){
        int mi=1000000000,ma=0;
        for(int i=0;i<n;i++){
            int now=0;
            for(int j=0;j<k;j++)
                now+=d[j]*s[i][j];
            mi=min(now,mi);
            ma=max(now,ma);
        }
        an=min(an,ma-mi);
        return;
    }
    for(int i=0;i<k;i++){
        if(used[i]==0){
            used[i]=1;
            d[x]=ten[i];
            dfs(x+1);
            used[i]=0;
        }
    }
}
int main(){
    int i,j;
    an=1000000000;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%s",s[i]);
        for(j=0;j<k;j++)s[i][j]-='0';
    }
    dfs(0);
    printf("%d\n",an);
    return 0;
}