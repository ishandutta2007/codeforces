#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int mo=1e9+7,N=300000;
int I[310000],nI[310000],n,m,h;
int quick(int k1,int k2){
	int k3=1;
	while (k2){
		if (k2&1) k3=1ll*k3*k1%mo;
		k2>>=1; k1=1ll*k1*k1%mo;
	}
	return k3;
}
int C(int k1,int k2){
	if (k1<k2) return 0;
	if (k2==0) return 1;
	return 1ll*I[k1]*nI[k2]%mo*nI[k1-k2]%mo;
}
int put(int k1,int k2){
	if (k1<k2) return 0;
	if (k1==0&&k2==0) return 1;
	if (k2==0) return 0;
	return C(k1-1,k2-1);
}
int main(){
	I[0]=1; for (int i=1;i<=N;i++) I[i]=1ll*I[i-1]*i%mo;
	for (int i=0;i<=N;i++) nI[i]=quick(I[i],mo-2);
	scanf("%d%d%d",&n,&m,&h);
	if (m==0){
		printf("1\n");
		return 0;
	}
	int tot=0,ans=0;
	for (int i=1;i<=m;i++){
		int k1=(2ll*put(n,i)+put(n,i-1)+put(n,i+1))%mo;
		tot=(tot+1ll*put(m,i)*k1)%mo;
		if (1ll*i*h<=m) ans=(ans+1ll*k1*put(m-i*h,i))%mo;
	}
	printf("%d\n",1ll*ans*quick(tot,mo-2)%mo);
	return 0;
}