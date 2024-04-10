#include<stdio.h>
int used[2010],a[1010],i,j,n;
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),used[a[i]]=i;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
            if(used[a[i]+a[j]]){
                printf("%d %d %d\n",used[a[i]+a[j]],i,j);
                return 0;
            }
    puts("-1");
    return 0;
}