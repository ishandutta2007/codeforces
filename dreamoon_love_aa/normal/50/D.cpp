#include<stdio.h>
#include<algorithm>
#include<math.h>
#define Err 1e-7
double sqr(double x){return x*x;}
double dp[101];
double Pro(double x,double r){
    if(x<=r)return 1;
    return exp(1-sqr(x/r));
}
main(){
    int n,K,M,X0,Y0,x,y,i,j;
    double a[101],left=0,right=0,mid;
    scanf("%d",&n);
    scanf("%d%d",&K,&M);
    scanf("%d%d",&X0,&Y0);
    for(i=0;i<n;i++){
        scanf("%d%d",&x,&y);
        a[i]=sqrt(sqr(x-X0)+sqr(y-Y0));
        right=std::max(right,a[i]);
    }
    while(left+Err<right){
        double now=0,p;
        mid=(left+right)/2;
        for(i=0;i<=n;i++)dp[i]=0;
        dp[0]=1000;
        for(i=0;i<n;i++){
            p=Pro(a[i],mid);
            for(j=i+1;j>0;j--)dp[j]=dp[j]*(1-p)+dp[j-1]*p;
            dp[0]*=1-p;
        }
        for(i=0;i<K;i++)now+=dp[i];
        if(now<=M)right=mid;
        else left=mid;
    }
    printf("%.8lf\n",mid);
}