#include<stdio.h>
#define SIZE 100001
int an[SIZE],dp[SIZE],used[SIZE];
int q(int n){
    int i,an=-1;
    for(i=2;(1+i)*i/2<=n;i++){
        if((2*n)%i==0){
            int tmp=(2*n)/i-(i-1);
            if((tmp&1)||tmp<=0)continue;
            tmp/=2;
            used[dp[tmp+i-1]^dp[tmp-1]]=n;
            if((dp[tmp+i-1]^dp[tmp-1])==0){
                if(an==-1)an=i;
            }
        }
    }
    for(i=0;used[i]==n;i++);
    dp[n]=i;
    dp[n]^=dp[n-1];
    return an;
}
main(){
    int n,i;
    an[1]=an[2]=-1;
    for(i=3;i<SIZE;i++){
        an[i]=q(i);
    }
    scanf("%d",&n);
    printf("%d\n",an[n]);
}