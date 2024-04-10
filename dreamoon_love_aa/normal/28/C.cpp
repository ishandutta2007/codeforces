#include<stdio.h>
#include<algorithm>
using namespace std;
long long C[51][51],two[51];
double dp[51][51][51];
double pow(double x,int y){
    double an=1;
    while(y){
        if(y&1){
            an*=x;
        }
        x*=x;
        y>>=1;
    }
    return an;
}
main(){
    int n,m,i,j,k,l,x;
    C[0][0]=1;
    for(i=0;i<51;i++)
        for(j=0;j<51;j++)
            for(k=0;k<51;k++)dp[i][j][k]=0;
    for(i=1;i<51;i++){
        C[i][0]=1;
        for(j=1;j<=i;j++)C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
    two[0]=1;
    for(i=1;i<51;i++)two[i]=two[i-1]<<1;
    scanf("%d%d",&n,&m);
    scanf("%d",&x);
    for(i=0;i<=n;i++){
        dp[0][i][(i+x-1)/x]=1;
    }
    for(i=1;i<m;i++){
        scanf("%d",&x);
        for(j=0;j<=n;j++){
            for(k=0;k<=j;k++)
                for(l=0;l<=j-k;l++)
                    dp[i][j][max((k+x-1)/x,l)]+=dp[i-1][j-k][l]*C[j][k]*pow(1./(i+1),k)*pow(1.*i/(i+1),j-k);
        }
    }
    double an=0;
    for(i=0;i<=n;i++)
        an+=dp[m-1][n][i]*i;
    printf("%.12lf\n",an);
}