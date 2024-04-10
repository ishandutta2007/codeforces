#include<bits/stdc++.h>
using namespace std;

const int p=1000000007;
int qpow(int a,int k){
	int ans=1;
	while(k){
		if(k&1) ans=1LL*ans*a%p;
		a=1LL*a*a%p;
		k>>=1; 
	}
	return ans;
}
int N,S,invS;
int A[100005];
int F[100005];

int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",&A[i]),S+=A[i];
	invS=qpow(S,p-2);
	F[1]=1LL*(S-1)*(S-1)%p*invS%p;
	F[2]=(2LL*F[1]%p-1+p)%p; 
	for(int i=2;i<=99999;i++){
		F[i+1]=(2LL*F[i]%p-F[i-1]+p)%p;
		F[i+1]=(F[i+1]-1LL*(S-1)*qpow(S-i,p-2)%p+p)%p;
	}
	int ans=0;
	for(int i=1;i<=N;i++) ans=(ans+F[A[i]])%p;
	printf("%d\n",ans);
}