#include<stdio.h>
int main(){
    int n,S,ans=0;
    scanf("%d%d",&n,&S);
    for(register int i=n;i!=0;i--){
        ans+=S/i;
        S%=i;
    }
    printf("%d",ans);
    return 0;
}