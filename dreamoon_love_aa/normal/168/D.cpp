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
#define SIZE 210
double dp[SIZE][SIZE][SIZE*2];
int p[SIZE],a[SIZE];
inline int fix(int x,int bb){
    if(x<0)return x;
    if(x>=bb)return bb-1;
    return x;
}
int main(){
    int i,j,k,l,n,r;
    cin>>n>>l>>k;
    for(i=1;i<=n;i++)cin>>p[i];
    for(i=1;i<=n;i++)cin>>a[i];
    for(r=0;r<SIZE;r++)
        for(i=0;i<=n;i++)
            for(j=0;j<SIZE*2;j++)dp[r][i][j]=0;
    dp[0][0][SIZE+k]=1;
    for(i=1;i<=n;i++){
        if(a[i]==-1){
            for(j=0;j<SIZE;j++)
                for(r=0;r<SIZE*2;r++){
                    dp[i][fix(j+1,SIZE)][fix(r-1,SIZE*2)]+=dp[i-1][j][r]*p[i]*0.01;
                    dp[i][j][r]+=dp[i-1][j][r]*(100-p[i])*0.01;
                }
        }
        else{
            for(j=0;j<SIZE;j++)
                for(r=0;r<SIZE*2;r++){
                    dp[i][j+1][fix(r+a[i],SIZE*2)]+=dp[i-1][j][r]*p[i]*0.01;
                    dp[i][j][r]+=dp[i-1][j][r]*(100-p[i])*0.01;
                }
        }
    }
    double an=0;
    for(i=l;i<SIZE;i++)
        for(j=SIZE;j<SIZE*2;j++)an+=dp[n][i][j];
    printf("%.9lf\n",an);
    return 0;
}