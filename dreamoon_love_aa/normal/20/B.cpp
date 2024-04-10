#include<stdio.h>
#include<math.h>
main(){
    int A,B,C;
    scanf("%d%d%d",&A,&B,&C);
    if(A<0){
        A=-A;
        B=-B;
        C=-C;
    }
    if(A==0&&B==0&&C==0)
        puts("-1");
    else if(A==0&&B==0)
        puts("0");
    else if(A==0)
        printf("1\n%.10lf\n",-1.*C/B);
    else{
        if((long long)B*B==4ll*A*C){
            printf("1\n%.10lf\n",-0.5*B/A);
        }
        else if((long long)B*B<4ll*A*C){
            puts("0");
        }
        else{
            printf("2\n");
            printf("%.10lf\n%.10lf\n",(-B-sqrt((double)B*B-4.*A*C))/(2*A),(-B+sqrt((double)B*B-4.*A*C))/(2*A));
        }
    }
}