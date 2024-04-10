#include<stdio.h>
#include<math.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t-->0){
        long long int x,s,k;
        scanf("%I64d",&x);
        s=(long long int)sqrt(x);
        if(x==1||x!=s*s){no: printf("NO\n");continue;}
        k=(long long int)sqrt(s);
        for(int i=2;i<=k;i++)if(s%i==0)goto no;
        printf("YES\n");
    }
}