#include<stdio.h>
#include<algorithm>
#include<math.h>
#define Err 1e-9
using namespace std;
main(){
    int n,i,l,r;
    double x,mi=0,ma=1e12;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf",&x);
        mi=max(mi,x/i);
        ma=min(ma,(x+1)/i);
    }
    l=(int)floor(mi*(n+1)+Err);
    r=(int)floor(ma*(n+1)-Err);
    if(l==r)printf("unique\n%d\n",l);
    else puts("not unique");
}