#include<stdio.h>
bool tr[511];
main(){
    int i,j=1;
    for(i=2;j<=500;i++){
        tr[j]=1;
        j+=i;
    }
    scanf("%d",&i);
    if(tr[i])puts("YES");
    else puts("NO");
}