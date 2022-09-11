#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
int two[20],s[524288];
long long len[20],dp[19][524288],an;
int edge[20][20];
void Go(int start){
    int i,j,k,n=start+1;
    for(i=0;i<n;i++)
        for(j=two[start];j<two[n];j++)dp[i][j]=0;
    dp[start][two[start]]=1;
    for(i=two[start]+1;i<two[n];i++){
        for(j=0;two[j]<=i;j++){
            if(j==start||!(two[j]&i))continue;
            for(k=0;two[k]<=i;k++){
                if(!edge[j][k])continue;
                if(!(two[k]&i))continue;
                dp[j][i]+=dp[k][i-two[j]];
                if(s[i]>2&&edge[start][j])an+=dp[k][i-two[j]];
            }
        }
    }
}
main(){
    int n,m,x,y,i;
    two[0]=1;
    for(i=1;i<20;i++)two[i]=two[i-1]*2;
    for(i=1;i<524288;i++)
        s[i]=s[i-(i&-i)]+1;
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&x,&y);
        edge[x-1][y-1]=edge[y-1][x-1]=1;
    }
    for(i=n-1;i>1;i--)
        Go(i);
    cout<<an/2<<endl;
}