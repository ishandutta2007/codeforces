#include<stdio.h>
int a[3];
main(){
int n,x,y,z;
scanf("%d",&n);
while(n--){
scanf("%d%d%d",&x,&y,&z);
a[0]+=x;
a[1]+=y;
a[2]+=z;
}
if(a[0]==0&&a[1]==0&&a[2]==0)puts("YES");
else puts("NO");
}