#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 100001
int a[SIZE],d[SIZE],an[SIZE],ann;
main(){
    int i,j,n,x,left=0,right=0,mid;
    long long k,now; 
    scanf("%d%I64d",&n,&k);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        right=max(a[i],right);
    }
    while(left<right){
        mid=(left+right)/2;
        now=0;
        for(i=0;i<n;i++){
            if(a[i]<mid)now+=a[i];
            else now+=mid;
        }
        if(now<k)left=mid+1;
        else right=mid;
    }
    mid=left;
    for(i=0;i<n;i++){
        if(a[i]<mid)k-=a[i];
        else k-=mid-1;
    }
    for(i=0;i<n;i++){
        if(a[i]>=mid){
            k--;
            if(k==0)break;
        }
    }
    if(k>0){
        puts("-1");
    }
    else{
        for(j=i+1;j<n;j++)
            if(a[j]>=mid)an[ann++]=j+1;
        for(j=0;j<=i;j++)
            if(a[j]>mid)an[ann++]=j+1;
        for(i=0;i<ann;i++){
            if(i)putchar(' ');
            printf("%d",an[i]);
        }
        puts("");
    }
}