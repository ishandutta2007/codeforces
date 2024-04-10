#include<stdio.h>
int a[999],b[999];
main(){
    int n,m,l,r,x,y,i,an=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)a[i]=10000;
    while(m--){
        scanf("%d%d%d%d",&l,&r,&x,&y);
        for(i=l;i<=r;i++){
            if(x<a[i]){
                a[i]=x;
                b[i]=y;
            }
        }
    }
    for(i=1;i<=n;i++)an+=b[i];
    printf("%d\n",an);
}