#include<stdio.h>
main(){
    int n,a,b,c,an=0,i,j;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    a>>=1;
    for(i=0;i<=c&&i*2<=n;i++){
        if(a+b<n-i*2)continue;
        for(j=0;j<=b;j++){
            if(n-i*2-j>=0&&n-i*2-j<=a)an++;
        }
    }
    printf("%d\n",an);
}