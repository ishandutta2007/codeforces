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
#define SIZE 80001
long long dp[SIZE][3][3];
int used[SIZE];
vector<int>e[SIZE];
void dfs(int x){
    used[x]=1;
    int i,j,k;
    long long tmp[3][3]={},ha=0,ha2=0;
    for(i=0;i<e[x].size();i++){
        if(used[e[x][i]])continue;
        int y=e[x][i];
        dfs(y);
        dp[x][1][2]+=dp[y][1][2]+dp[y][1][1];
        dp[x][1][0]+=dp[y][1][2]+dp[y][1][0]+(dp[y][1][2]+dp[y][1][1])*(tmp[1][2]+tmp[1][1]);
        dp[x][2][0]+=dp[y][2][2]+dp[y][2][0]+(dp[y][1][0]+dp[y][1][2])*(tmp[1][2]+tmp[1][0]);
        dp[x][2][0]+=(dp[y][1][2]+dp[y][1][1])*(tmp[2][1]+tmp[2][2])+(dp[y][2][1]+dp[y][2][2])*(tmp[1][1]+tmp[1][2]);
        dp[x][2][0]+=(dp[y][1][1]+dp[y][1][2])*((tmp[1][1]+tmp[1][2])*(tmp[1][2]+tmp[1][0])-ha);
        dp[x][2][0]+=(dp[y][1][0]+dp[y][1][2])*(((tmp[1][1]+tmp[1][2])*(tmp[1][1]+tmp[1][2])-ha2)/2);
        dp[x][2][2]+=dp[y][2][2]+dp[y][2][1]+(tmp[1][2]+tmp[1][0])*(dp[y][1][2]+dp[y][1][1])+(tmp[1][1]+tmp[1][2])*(dp[y][1][2]+dp[y][1][0]);
        for(j=1;j<=2;j++)
            for(k=0;k<3;k++)tmp[j][k]+=dp[y][j][k];
        ha+=(dp[y][1][1]+dp[y][1][2])*(dp[y][1][2]+dp[y][1][0]);
        ha2+=(dp[y][1][1]+dp[y][1][2])*(dp[y][1][1]+dp[y][1][2]);
    }
    dp[x][2][1]=tmp[1][0]+tmp[1][2];
    dp[x][1][1]=1;
}
int main(){
    int i,j,k,n;
    cin>>n;
    for(i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(1);
    printf("%I64d\n",(dp[1][2][0]+dp[1][2][2])*2);
    /*
    for(k=1;k<=n;k++){
        printf("%d:",k);
        for(i=1;i<=2;i++)
            for(j=0;j<3;j++)printf("%I64d,",dp[k][i][j]);
        puts("");
    }
    */
    return 0;
}