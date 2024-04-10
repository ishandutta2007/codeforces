#include<stdio.h>
int mod(int a){
return (a>0)?a:-a;
}
int main(){
    int x,y,z,t1,t2,t3,e,w;
    scanf("%d %d %d %d %d %d",&x,&y,&z,&t1,&t2,&t3);
    w=mod(x-y)*t1;
    e=(mod(x-z)+mod(x-y))*t2+3*t3;
    if(w<e)
    printf("NO");
    else
    printf("YES");
}