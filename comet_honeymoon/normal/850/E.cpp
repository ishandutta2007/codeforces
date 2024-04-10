#include<bits/stdc++.h>
using namespace std;

const int p=1000000007,inv2=500000004;

int N;
int F[1<<20],siz[1<<20];

int FWT_xor(int d[],int n0,int flg){
	for(int i=1;i<(1<<n0);i<<=1)
	for(int j=0;j<(1<<n0);j+=(i<<1))
	for(int k=0;k<i;k++){
		int a0=d[j|k],a1=d[i|j|k];
		d[j|k]=(a0+a1)%p,d[i|j|k]=(a0-a1+p)%p;
		if(flg==-1) d[j|k]=1LL*d[j|k]*inv2%p,d[i|j|k]=1LL*d[i|j|k]*inv2%p;
	}
}

int ans;

int main(){
	scanf("%d",&N);
	for(int i=0;i<(1<<N);i++){scanf("%1d",&F[i]);if(i) siz[i]=siz[i>>1]+(i&1);}
	FWT_xor(F,N,1);
	for(int i=0;i<(1<<N);i++) F[i]=1LL*F[i]*F[i]%p;
	FWT_xor(F,N,-1);
	for(int i=0;i<(1<<N);i++) ans=(ans+1LL*F[i]*(1<<(N-siz[i]))%p)%p;
	printf("%d\n",3LL*ans%p);
}