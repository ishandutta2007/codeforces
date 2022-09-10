#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int SIZE = 2010;
int far[SIZE],dp[SIZE][SIZE],mi[SIZE],an[SIZE];
char str[SIZE],p[SIZE];
int main(){
    scanf("%s%s",str,p);
    int n=strlen(str);
    int m=strlen(p);
    memset(far,-1,sizeof(far));
    for(int i=0;i<n;i++){
        int idx=0;
        for(int j=i;str[j];j++){
            if(str[j]==p[idx])idx++;
            if(!p[idx]){
                far[i]=j+1;
                break;
            }
        }
    }
    memset(dp,0x77,sizeof(dp));
    dp[0][0]=0;
    for(int i=0;far[i]!=-1;i++){
        if(i)for(int j=0;j<=i;j++)dp[i][j]=min(dp[i][j],dp[i-1][j]);
        for(int j=i;j>=0;j--){
            dp[far[i]][j+1]=min(dp[far[i]][j+1],dp[i][j]+far[i]-i-m);
        }
    }
    memset(mi,0x77,sizeof(mi));
    for(int i=0;i<=n;i++){
        for(int j=0;j<=i;j++)
            mi[j]=min(mi[j],dp[i][j]);
    }
    for(int i=0;i<=n;i++)an[i]=(n-i)/m;
    int ma=0;
    for(int i=1;i<=n&&mi[i]<=n;i++){
        for(int j=0;j<mi[i];j++)an[j]=min(an[j],i-1);
        ma=i;
    }
    for(int i=0;i<=n;i++)an[i]=min(an[i],ma);
    for(int i=0;i<=n;i++){
        if(i)printf(" ");
        printf("%d",an[i]);
    }
    puts("");
    return 0;
}