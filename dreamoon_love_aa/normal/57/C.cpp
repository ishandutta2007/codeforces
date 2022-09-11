#include<stdio.h>
const long long MOD=1000000007;
int inverse[200001];
struct gcd_t{long long x,y,z;};
gcd_t gcd(long long a,long long b){
    if(!b)return (gcd_t){1,0,a};
    gcd_t t=gcd(b,a%b);
    return (gcd_t){t.y,t.x-t.y*(a/b),t.z};
}
main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<n+n;i++){
        gcd_t tmp=gcd(i,MOD);
        inverse[i]=(tmp.x+MOD)%MOD;
    }
    long long an=1;
    for(i=1;i<n;i++){
        an*=inverse[i];
        an%=MOD;
        an*=n+n-i;
        an%=MOD;
    }
    an*=2;
    an-=n;
    an%=MOD;
    if(an<0)an+=MOD;
    printf("%d\n",(int)an);
}