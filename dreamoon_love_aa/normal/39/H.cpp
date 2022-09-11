#include<stdio.h>
int v(int x,int y){
    int an=0,p=1;
    while(x){
        an+=(x%y)*p;
        p*=10;
        x/=y;
    }
    return an;
}
main(){
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<n;i++,puts(""))
        for(j=1;j<n;j++){
            if(j!=1)putchar(' ');
            printf("%d",v(i*j,n));
        }
}