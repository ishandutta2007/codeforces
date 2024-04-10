#include<bits/stdc++.h>
using namespace std;
const int N=2001;
int n,m,a[N],S=0;
//#define double long double
double dp[2][1200001];

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),S+=a[i];
    if(n==1){
        printf("%d\n",a[1]);
        return 0;
    }
    if(m==1){
        puts("1");
        return 0;
    }
    dp[0][0]=1; int cur=0;
    for(int i=1;i<=n;i++){
        cur^=1; memset(dp[cur],0,sizeof(dp[cur]));
        double sum=0;
        for(int j=1;j<=m;j++){
            sum+=dp[cur^1][j-1];
            double tmp=0; if(j>=a[i]) tmp=dp[cur^1][j-a[i]];
            dp[cur][j]=(sum-tmp)/(m-1);
        }
        for(int j=m+1;j<=i*m;j++){
            sum-=dp[cur^1][j-m-1];
            sum+=dp[cur^1][j-1];
            double tmp=dp[cur^1][j-a[i]];
            dp[cur][j]=(sum-tmp)/(m-1);
        }
    }
    double sum=0;
    for(int i=0;i<S;i++) sum+=dp[cur][i];
    printf("%.12lf\n",1.0*(1.0*m-1)*sum+1.0);
    return 0;
}