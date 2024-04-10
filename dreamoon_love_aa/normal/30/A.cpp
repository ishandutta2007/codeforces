#include<stdio.h>
int pow(int x,int y){
    int an=1;
    while(y){
        if(y&1)
            an*=x;
        x*=x;
        y>>=1;
    }
    return an;
}
int main(){
    int A,B,n,neg=0,answer,i=0;
    scanf("%d%d%d",&A,&B,&n);
    if(B==0){
        if(A==0)
            puts("1");
        else 
            puts("0");
        return 0;
    }
    if(A==0){
        puts("No solution");
        return 0;
    }
    if(A<0){
        A=-A;
        B=-B;
    }
    if(B%A)puts("No solution");
    else{
        B/=A;
        if(B<0){
            if(n&1){
                neg=1;
                B=-B;
            }
            else{
                puts("No solution");
                return 0;
            }
        }
        for(i=1;i<=B;i++){
            answer=pow(i,n);
            if(answer==B)break;
        }
        if(answer==B){
            if(neg==1)putchar('-'); 
            printf("%d\n",i);
        }
        else puts("No solution");
    }
    return 0;
}