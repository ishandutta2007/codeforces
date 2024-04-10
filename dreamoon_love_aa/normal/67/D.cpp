#include<stdio.h>
#define SIZE 1000010
int a[SIZE],d[SIZE],dp[SIZE];
main(){
    int x,i,j,now,left,right,mid,n;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        a[x]=i;
    }
    for(i=0;i<n;i++){
        scanf("%d",&x);
        d[a[x]]=i;
    }
    for(i=now=0;i<n;i++){
        left=0,right=now;
        while(left<right){
            mid=(left+right)/2;
            if(dp[mid]>d[i])left=mid+1;
            else right=mid;
        }
        dp[left]=d[i];
        if(left==now)now++;
    }
    printf("%d\n",now);
}