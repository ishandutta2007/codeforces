#include<bits/stdc++.h>
#define LL long long
const int MOD=1e9+7;
LL an=1,pp=1,res,cc[5001];
LL mypow(LL x,LL y){
    LL r=1;
    while(y){
        if(y&1)r=r*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return r;
}
int main(){
    int n,k,a;
    scanf("%d%d",&n,&k);
    cc[0]=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        for(int j=i;j>0;j--){
            cc[j]=(cc[j]*a-cc[j-1])%MOD;
            if(cc[j]<0)cc[j]+=MOD;
        }
        cc[0]=cc[0]*a%MOD;
        an=an*a%MOD;
    }
    LL tmp=mypow(n,k),inv=mypow(n,MOD-2);
    for(int i=0;i<=n&&i<=k;i++){
        res=(res+tmp*pp%MOD*cc[i])%MOD;
        pp=pp*(k-i)%MOD;
        tmp=tmp*inv%MOD;
    }
    an=((an-res*mypow(mypow(n,k),MOD-2)%MOD)%MOD+MOD)%MOD;
    printf("%lld\n",an);
    return 0;
}