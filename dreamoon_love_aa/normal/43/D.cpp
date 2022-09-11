#include<stdio.h>
main(){
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    if((n%2==1&&m%2==1)||(n==1&&m>2)||(m==1&&n>2)){
        printf("1\n%d %d 1 1\n",n,m);
        for(i=1;i<=n;i++){
            if(i%2==1)
                for(j=1;j<=m;j++)printf("%d %d\n",i,j);
            else
                for(j=m;j>0;j--)printf("%d %d\n",i,j);
        }
        printf("1 1\n");
    }
    else if(n%2==0){
        printf("0\n1 1\n");
        for(i=1;i<=n;i++){
            if(i%2==1)
                for(j=2;j<=m;j++)printf("%d %d\n",i,j);
            else
                for(j=m;j>1;j--)printf("%d %d\n",i,j);
        }
        for(i=n;i>0;i--)printf("%d 1\n",i);
    }
    else{
        printf("0\n1 1\n");
        for(i=1;i<=m;i++){
            if(i%2==1)
                for(j=2;j<=n;j++)printf("%d %d\n",j,i);
            else
                for(j=n;j>1;j--)printf("%d %d\n",j,i);
        }
        for(i=m;i>0;i--)printf("1 %d\n",i);
    }
}