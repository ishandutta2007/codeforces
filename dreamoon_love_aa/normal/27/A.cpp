#include<stdio.h>
bool used[1010];
main(){
    int n,i;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&i);
        used[i]=1;
    }
    for(i=1;used[i];i++);
    printf("%d\n",i);
}