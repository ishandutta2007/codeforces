#include <bits/stdc++.h>

#define Mod 1000000007

using namespace std;

long long Facto[200007], inv[200007], Finv[200007];
int X[2007], Y[2007];
long long D[2007];

int H,W,N;

int Pre()
{
	int i;
	Facto[0] = Finv[0] = 1;
	for(i=1; i<=max(H,W)*2; i++) Facto[i] = (Facto[i-1] * i) % Mod;
	inv[1] = 1;
	for(i=2; i<=max(H,W)*2; i++) inv[i] = (Mod-Mod/i) * inv[Mod%i] % Mod;
	for(i=1; i<=max(H,W)*2; i++) Finv[i] = (Finv[i-1] * inv[i]) % Mod;
	
	return 0;
}

long long Comb(int n,int k)
{
	return (Facto[n] * ((Finv[n-k]*Finv[k])%Mod)) % Mod;
}

int calc(int a,int b)
{
	int h,w;
	h = X[b] - X[a] + 1;
	w = Y[b] - Y[a] + 1;
	
	return Comb((h+w-2), h-1);
}

long long d(int k)
{
	if(D[k] == -1){
		int i;
		long long black = 0;
		for(i=0; i<N; i++){
			if(i != k){
				if(X[k] <= X[i] && Y[k] <= Y[i]){
					black = black + (calc(k,i) * d(i)) % Mod;
				}
			}
		}
		D[k] = (calc(k,N) + Mod - black) % Mod;
	}
	return D[k];
}

int main()
{
	scanf("%d %d %d",&H,&W,&N);
	
	Pre();
	
	int i;
	for(i=0; i<N; i++) scanf("%d %d",X+i,Y+i), D[i] = -1;
	X[N] = H, Y[N] = W;
	X[N+1] = 1, Y[N+1] = 1;
	
	long long ans=0;
	for(i=0; i<N; i++) ans = (ans + (calc(N+1,i) * d(i)) % Mod) % Mod;
	
	ans = (calc(N+1, N) + Mod - ans) % Mod;
	
	printf("%I64d\n",ans);
	
	return 0;
}