#include<stdio.h>
int a[3];
main(){
    int n,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        a[x%3]++;
    }
    printf("%d\n",a[0]/2+((a[1]>a[2])?a[2]:a[1]));
}