#include<stdio.h>
#include<algorithm>
using namespace std;
struct data{
    int x,y,t;
    double p;
    bool operator<(data b)const{return t<b.t;}
}a[1001];
double dp[1001];
long long sqr(long long x){return x*x;}
main(){
    int n,i,j;
    double an=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d%d%lf",&a[i].x,&a[i].y,&a[i].t,&a[i].p);
    sort(a,a+n);
    for(i=0;i<n;i++){
        dp[i]=a[i].p;
        for(j=0;j<i;j++){
            if(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y)<=sqr(a[i].t-a[j].t))
                if(dp[i]<a[i].p+dp[j])dp[i]=a[i].p+dp[j];
        }
        if(an<dp[i])an=dp[i];
    }
    printf("%.8lf\n",an);
}