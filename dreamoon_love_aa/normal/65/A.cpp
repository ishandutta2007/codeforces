#include<stdio.h>
void AC(){puts("Ron");}
void WA(){puts("Hermione");}
main(){
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(!c){
        if(d)AC();
        else WA();
    }
    else if(!d)WA();
    else if(!a){
        if(b)AC();
        else WA();
    }
    else if(!b)WA();
    else if(!e){
        if(f)AC();
        else WA();
    }
    else{
        a*=c*e;
        b*=d*f;
        if(a<b)AC();
        else WA();
    }
}