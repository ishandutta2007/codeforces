#include<bits/stdc++.h>
#define ll long long
using namespace std;

void FWT_or(ll d[],int n0,int flg){
	for(int i=1;i<(1<<n0);i<<=1)
	for(int j=0;j<(1<<n0);j+=(i<<1))
	for(int k=0;k<i;k++)
		d[i|j|k]+=flg*d[j|k];
}

int N;
int siz[1<<21];
ll a[1<<21],b[1<<21],c[1<<21];

int main(){
	scanf("%d",&N);
	for(int i=1;i<(1<<N);i++) siz[i]=siz[i>>1]+(i&1);
	for(int i=0;i<(1<<N);i++) scanf("%1lld",&a[i]),a[i]<<=(siz[i]<<1);
	for(int i=0;i<(1<<N);i++) scanf("%1lld",&b[i]),b[i]<<=(siz[i]<<1);
	FWT_or(a,N,1);FWT_or(b,N,1);
	for(int i=0;i<(1<<N);i++) c[i]=a[i]*b[i];
	FWT_or(c,N,-1);
	for(int i=0;i<(1<<N);i++) printf("%lld",(c[i]>>(siz[i]<<1))&3);
}