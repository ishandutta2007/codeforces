#include<stdio.h>
bool used[500];
main(){
    int N,K,C,i,an=0,x;
    scanf("%d%d%d",&N,&K,&C);
    for(i=0;i<C;i++){
        scanf("%d",&x);
        used[x]=1;
    }
    for(i=1,x=1;i<=N;i++){
        if(!used[i]){
            if(x==K){
                an++;
                x=1;
            }
            else x++;
        }
        else{
            x=1;
            an++;
        }
    }
    printf("%d\n",an);
}