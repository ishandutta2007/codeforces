#include <cstdio>

typedef long long LL;

LL Mod = 1e9+7;
LL a,b,h,i,p,q;
LL F[202020],I[202020];

LL Comb(LL n,LL r)
{
	n--; r--;
	if(n<0 || r<0 || n<r) return 0;

	return F[n]*I[r]%Mod*I[n-r]%Mod;
}

LL Pow(LL a,LL b)
{
	if(b == 1) return a;

	LL ret = Pow(a,b/2);
	return ret*ret%Mod*(b%2?a:1)%Mod;
}

int main()
{
	scanf("%lld%lld%lld",&a,&b,&h);

	if(a==0){
		printf("%d\n",b>h?1:0);
		return 0;
	}
	if(b==0){
		printf("1\n");
		return 0;
	}

	F[0] = I[0] = 1;
	for(i=1;i<=a+b;i++){
		F[i] = F[i-1]*i%Mod;
		I[i] = i==1?1:(Mod-Mod/i*I[Mod%i]%Mod)%Mod;
	}

    for(i=1;i<=a+b;i++) I[i] = I[i]*I[i-1]%Mod;

	for(i=1;i<=a+b;i++){
		//food first
		//printf("%lld %lld %lld\n",i,Comb(a,(i+1)/2),Comb(b-i/2*h,i/2));
		p += Comb(a,(i+1)/2) * Comb(b,i/2);
		p %= Mod;
		q += Comb(a,(i+1)/2) * Comb(b-i/2*h,i/2);
		q %= Mod;
		//wine first
		//printf("%lld %lld\n",Comb(b-(i+1)/2*h,(i+1)/2),Comb(a,i/2));
		p += Comb(b,(i+1)/2) * Comb(a,i/2);
		p %= Mod;
		q += Comb(b-(i+1)/2*h,(i+1)/2) * Comb(a,i/2);
		q %= Mod;
	}

	p = Pow(p,Mod-2);

	//printf("%lld %lld\n",q,p*q%Mod);
	printf("%lld\n",p*q%Mod);

	return 0;
}