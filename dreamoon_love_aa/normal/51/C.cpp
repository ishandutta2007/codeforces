#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 200000
int a[SIZE];
main(){
    int n,i,j,k,left,right,mid;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    left=0,right=a[n-1]-a[0];
    while(left<right){
        mid=(left+right)>>1;
        for(k=i=0;k<3;k++){
            for(j=i+1;j<n&&a[j]-a[i]<=mid;j++);
            i=j;
        }
        if(i>=n)right=mid;
        else left=mid+1;
    }
    printf("%.6lf\n",left*0.5);
    for(k=i=0;k<3;k++){
        for(j=i+1;j<n&&a[j]-a[i]<=left;j++);
        if(k)putchar(' ');
        if(i==n)printf("%.6lf",1000000000.);
        else printf("%.6lf",0.5*(a[j-1]-a[i])+a[i]);
        i=j;
    }
    puts("");
}