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
bool p[100000];
int pn,pp[100000];
vector<int>a[6][5][10000];
void pre(int x){
    //printf("[%d]",x);
    int y=x;
    char s[8];
    sprintf(s,"%d",x);
    int i,j,len=strlen(s);
    for(i=len;i<=5;i++){
        y=x;
        for(j=i-1;j>0;j--){
            y/=10;
            a[i][j][y].pb(x);
        }
    }
}
int d[6][6],cnt,dp[5][10000];
int dfs(int x,int len){
    int i,j,tmp=0,tmp2=0;
    for(i=1;i<x;i++){
        tmp*=10;
        tmp+=d[x][i];
    }
    //printf("[%d,%d,%d]",x,tmp,a[len][x-1][tmp].size());
    if(x==len){
        return (int)a[len][x-1][tmp].size();
    }
    if(x>2){
        for(j=x;j<=len;j++)
            for(int k=2;k<x;k++){
                tmp2*=10;
                tmp2+=d[j][k];
            }
        if(dp[x][tmp2]!=-1)return dp[x][tmp2];
    }
    int now=0;
    for(i=0;i<a[len][x-1][tmp].size();i++){
        int y=a[len][x-1][tmp][i];
        for(j=0;j<=len-x;j++){
            d[x][len-j]=d[len-j][x]=y%10;
            y/=10;
        }
        now+=dfs(x+1,len);
    }
    return dp[x][tmp2]=now;
}
void go(int x){
    int i,y=x;
    char s[8];
    sprintf(s,"%d",x);
    int len=strlen(s);
    cnt=0;
    for(i=0;i<len;i++){
        d[1][len-i]=d[len-i][1]=y%10;
        y/=10;
    }
    printf("%d\n",dfs(2,len));
}
int main(){
    int i,j,k,n,t;
    for (i=2;i<100000;i++){
        if (p[i]==0){
            pn++;
            pp[pn]=i;
            pre(i);
        }
        for (j=1;j<=pn&&i*pp[j]<100000;j++){
            p[i*pp[j]]=1;
            if (i%pp[j]==0) break;
        }
    }
    cin>>t;
    while(t--){
        int x;
        scanf("%d",&x);
        memset(dp,-1,sizeof(dp));
        go(x);
    }
    return 0;
}