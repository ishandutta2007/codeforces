#include<stdio.h>
#define SIZE 1010
int Out(int x){return x<1000||x>2011;}
int an[SIZE],a[SIZE];
int Find(int x,int y){
    int ten=1,i,j,o=y,mi=9999;
    for(i=0;i<4;i++,ten*=10){
        for(j=0;j<10;j++){
            int tmp=o-((o/ten)%10*ten)+j*ten;
            if(tmp>=x&&tmp<mi)mi=tmp;
        }
    }
    return mi;
}
main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    an[0]=Find(1000,a[0]);
    for(i=1;i<n;i++){
        an[i]=Find(an[i-1],a[i]);
        if(Out(an[i]))break;
    }
    if(i<n)puts("No solution");
    else{
        for(i=0;i<n;i++)printf("%d\n",an[i]);
    }
}