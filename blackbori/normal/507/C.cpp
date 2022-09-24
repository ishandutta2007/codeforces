#include <cstdio>
#include <cmath>

long long N, K, H;

int main()
{
    scanf("%lld %lld",&N,&K);

    H = pow(2,N);

    long long i,k,ans1,ans2;
    bool f1,f2;
    f1 = true;
    for(i=H/2,k=K-1,ans1=1; i>=1; i/=2){
        if(k>=i) f2 = true;
        else f2 = false;
        if(f1==f2) ans1+=i;
        k %= i;
        f1 = f2;
    }

    for(i=H/2,k=ans1-1,ans2=1; i>=1; i/=2){
        if(k>=i) ans2+=(i*2);
        else ans2++;
        k %= i;
    }

    printf("%lld\n",ans2-1);

    return 0;
}