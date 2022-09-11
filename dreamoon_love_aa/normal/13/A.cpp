#include<stdio.h>
int an;
int Gcd(int x,int y){
    while((x%=y)&&(y%=x));
    return x+y;
}
void Go(int x,int y){
    while(y){
        an+=y%x;
        y/=x;
    }
}
main(){
    int N,i;
    scanf("%d",&N);
    for(i=2;i<N;i++)
        Go(i,N);
    N-=2;
    int g=Gcd(an,N);
    printf("%d/%d\n",an/g,N/g);
}