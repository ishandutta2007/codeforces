#include<stdio.h>
#include<math.h>
main(){
    int x,y,z;
    scanf("%d%d",&x,&y);
    z=(int)(sqrt(x*x+y*y)+1e-9);
    if(x*x+y*y==z*z)puts("black");
    else{
        if(z&1)z=1;
        else z=-1;
        if(x*y*z<0)puts("black");
        else puts("white");
    }
}