#include <bits/stdc++.h>
#define Mod 1000000007

typedef long long LL;

using namespace std;

LL Facto[3030303],inv[3030303],Finv[3030303];

LL Pre(LL N)
{
	LL i;
	Facto[0] = Finv[0] = 1;
	for(i=1; i<=N; i++) Facto[i] = (Facto[i-1] * i) % Mod;
	inv[1] = 1;
	for(i=2; i<=N; i++) inv[i] = (Mod-Mod/i) * inv[Mod%i] % Mod;
	for(i=1; i<=N; i++) Finv[i] = (Finv[i-1] * inv[i]) % Mod;
	
	return 0;
}

LL Comb(LL n,LL k)
{
	return ((Facto[n]*Finv[n-k])%Mod*Finv[k])%Mod;
}

int main()
{
	LL n;
	
	scanf("%I64d",&n);
	
	Pre(n*3+6);
	
	printf("%I64d\n",(Comb(n*2+2,n+1)-1+Mod)%Mod);
	
	return 0;
}