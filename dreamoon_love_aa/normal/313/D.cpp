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
#define SIZE 100000
#define MAX 1000000000000000000ll
long long dp[301][301],d[301][301];
bool fresh(long long &x,long long v){if(x>v)x=v;}
int main(){
    int i,j,k,n,m,K;
    cin>>n>>m>>K;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)dp[i][j]=d[i][j]=MAX;
    for(i=0;i<m;i++){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        fresh(dp[x][y],v);
    }
    for(i=n-2;i>=0;i--){
        for(int L=1;L+i<=n;L++){
            int R=L+i;
            fresh(dp[L][R],dp[L-1][R]);
            if(R<n)fresh(dp[L][R],dp[L][R+1]);
        }
    }
    d[0][0]=0;
    for(i=1;i<=n;i++){
        d[i][0]=0;
        for(j=1;j<=i;j++){
            fresh(d[i][j],d[i-1][j]);
            for(k=1;k<=j;k++){
                if(dp[i-k+1][i]!=MAX&&d[i-k][j-k]!=MAX)fresh(d[i][j],d[i-k][j-k]+dp[i-k+1][i]);
            }
        }
    }
    if(d[n][K]==MAX)d[n][K]=-1;
    cout<<d[n][K];
    return 0;

}