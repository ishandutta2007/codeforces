#include<stdio.h>
#include<algorithm>
using namespace std;
#define Err 1e-9
int a[100010];
main(){
    double left,right,mid,x,y;
    int i,sum=0,now=0,n,k;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    left=a[0];
    right=a[n-1];
    while(left+Err<right){
        x=y=0;
        mid=(left+right)/2;
        for(i=0;i<n;i++){
            if(a[i]<mid)x+=mid-a[i];
            else y+=a[i]-mid;
        }
        if(x*(100)<y*(100-k))left=mid;
        else right=mid;
    }
    printf("%.8lf\n",left);
}