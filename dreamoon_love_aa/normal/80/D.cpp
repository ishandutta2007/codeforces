#include<stdio.h>
main(){
    int T,a,b,aa;
    double an;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        if(b==0){
            an=1;
        }
        else if(a==0){
            an=0.5;
        }
        else{
            if(4*b>=a)
                an=((double)a*a/8+(double)a*b)/(2.*a*b);
            else{
                aa=4*b;
                an=(a-aa)*1./a+((double)aa*aa/8+(double)aa*b)/(2.*aa*b)*aa/a;
            }
        }
        printf("%.9lf\n",an);
    }
}