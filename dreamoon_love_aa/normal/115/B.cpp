#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 168
#define MAX 168000000
char a[SIZE][SIZE];
int left[SIZE],right[SIZE],dp[SIZE][SIZE][2];
int main(){
    int n,m,i,j,k,an=MAX;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%s",a[i]);
    for(i=0;i<n;i++){
        left[i]=MAX;
        right[i]=-1;
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(a[i][j]=='W'){
                left[i]=min(left[i],j);
                right[i]=max(right[i],j);
            }
        }
    for(n--;n>=0&&left[n]==MAX;n--);
    if(n<0){
        puts("0");
        return 0;
    }
    for(i=0;i<=n;i++)
        for(j=0;j<m;j++)dp[i][j][0]=dp[i][j][1]=MAX;
    for(i=max(0,right[0]);i<m;i++)dp[0][i][0]=min(dp[0][i][0],i);
    for(i=1;i<=n;i++){
        if(right[i]==-1){
            for(j=0;j<m;j++)
                for(k=0;k<=j;k++)
                    dp[i][j][0]=min(dp[i][j][0],dp[i-1][k][1]+1+(j-k));
        }
        else{
            for(j=right[i];j<m;j++)
                for(k=0;k<=left[i];k++)
                    dp[i][j][0]=min(dp[i][j][0],dp[i-1][k][1]+1+(j-k));
        }
        if(left[i]==MAX){
            for(j=m-1;j>=0;j--)
                for(k=m-1;k>=j;k--)
                    dp[i][j][1]=min(dp[i][j][1],dp[i-1][k][0]+1+(k-j));
        }
        else{
            for(j=left[i];j>=0;j--)
                for(k=m-1;k>=right[i];k--)
                    dp[i][j][1]=min(dp[i][j][1],dp[i-1][k][0]+1+(k-j));
        }
    }
    for(i=0;i<m;i++){
        an=min(an,dp[n][i][0]);
        an=min(an,dp[n][i][1]);
    }
    printf("%d\n",an);
    return 0;
}