#include<cstdio>
main(){
    int n,h,k;
    long long an=0,v=0;
    scanf("%d%d%d",&n,&h,&k);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        an+=v/k;
        v%=k;
        if(v+x<=h)v+=x;
        else{
          an++;
          v=x;
        }
    }
    an+=(v+k-1)/k;
    printf("%I64d",an);
}