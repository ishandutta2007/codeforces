#include<stdio.h>
main(){
int x1,y1,z1,x2,y2,z2;
scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
if(x1==x2||y1==y2||z1==z2)puts("YES");
else puts("NO");
}