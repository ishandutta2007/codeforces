#include<stdio.h>
int a[100010],use[100010];
main(){
    int n,i,an=10000000;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        if(i<=(n+1)/2){
            if(a[i]>=i)use[a[i]-i]++;
        }
        else{
            if(a[i]>=n+1-i)use[a[i]-(n+1-i)]++;
        }
    }
    for(i=0;i<100000;i++)
        if(an>n-use[i])an=n-use[i];
    printf("%d\n",an);
}