#include<stdio.h>
int main(){
    int t,n;
    scanf("%d",&t);
    for(register int i=0;i!=t;i++){
        scanf("%d",&n);
        int ans=0;
        while(n%6==0){
            n/=6;
            ans++;
        }
        while(n%3==0){
            n/=3;
            ans+=2;
        }
        if(n!=1){
            puts("-1");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}