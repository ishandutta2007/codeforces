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
void win(){puts("BitLGM");}
void lose(){puts("BitAryo");}
int dp[301][301][301],d[301][301],e[301][301];
int dp2[301][301],d2[301],e2[301];
void cal(int x,int y,int z){
    if(dp[x][y][z])return;
    if(e[x][y]||e[x][z]||e[y][z]){
        dp[x][y][z]=1;
        return;
    }
    if(d[y-x][z-x]){
        dp[x][y][z]=1;
        return;
    }
    e[x][y]=e[y][z]=e[x][z]=1;
    d[y-x][z-x]=1;
    dp[x][y][z]=-1;
}
void cal2(int x,int y){
    if(dp2[x][y])return;
    if(e2[x]||e2[y]){
        dp2[x][y]=1;
        return;
    }
    if(d2[y-x]){
        dp2[x][y]=1;
        return;
    }
    e2[x]=e2[y]=1;
    d2[y-x]=1;
    dp2[x][y]=-1;
}
int main(){
    int i,j,k,n,a[3]={};
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    if(n==1){
        if(a[0])win();
        else lose();
    }
    else if(n==2){
        sort(a,a+2);
        dp2[0][0]=-1;
        e2[0]=1;
        d2[0]=1;
        for(int r=1;r<=300;r++){
            for(i=0;i<=r;i++)
                cal2(i,r);
        }
        if(dp2[a[0]][a[1]]==1)win();
        else lose();
    }
    else{
        sort(a,a+3);
        dp[0][0][0]=-1;
        e[0][0]=1;
        d[0][0]=1;
        for(int r=1;r<=300;r++){
            for(i=0;i<=r;i++)
                for(j=i;j<=r;j++){
                    cal(i,j,r);
                }
        }
        if(dp[a[0]][a[1]][a[2]]==1)win();
        else lose();
    }
    return 0;
}