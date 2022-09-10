#include<cstdio>
const int MOD = 1e9+7;
typedef long long LL;
int main(){
    int K,N;
    scanf("%d%d",&K,&N);
    LL an=0;
    for(int k=1;k<=K;k++){
        an+=(LL)(N-1)*N/2%MOD*((LL)k%MOD*N%MOD+1)%MOD;
    }
    printf("%d\n",(int)(an%MOD));
    return 0;
}