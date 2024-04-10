#include<stdio.h>
void win(){puts("Timur");}
void lose(){puts("Marsel");}
main(){
    int n,m,k,i;
    scanf("%d%d%d",&n,&m,&k);
    if(n&1){
        if(k==1&&m!=1)win();
        else{
            for(i=2;i*i<=m;i++){
                if(m%i==0){
                    if(m/i>=k)win();
                    else lose();
                    break;
                }
            }
            if(i*i>m)lose();
        }
    }
    else lose();
}