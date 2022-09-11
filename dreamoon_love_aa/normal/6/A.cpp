#include<stdio.h>
#include<algorithm>
main(){
    int i,a[4];
    for(i=0;i<4;i++)scanf("%d",&a[i]);
    std::sort(a,a+4);
    if(a[0]+a[1]>a[2]||a[1]+a[2]>a[3])
        puts("TRIANGLE");
    else if(a[0]+a[1]==a[2]||a[1]+a[2]==a[3])
        puts("SEGMENT");
    else puts("IMPOSSIBLE");
}