#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,N,cnt[3][20];
ll X,Y,a[200005],pri[20];
void getfac(){
	ll x=Y;
	for(int i=2;i<=1e6;i++)if(x%i==0){
		pri[N++]=i;
		while(x%i==0)x/=i;
	}
	if(x>1){
		for(int i=0;i<=n;i++){
			ll G=__gcd(x,a[i]);
			if(1<G&&G<x){
				pri[N++]=G;
				if(x/G!=G)pri[N++]=x/G;
				return;
			}
		}
	}
	if(x>1)pri[N++]=x;
}
ll A[1100000],B[1100000];
void AND(ll *f,int x){
	for(int b=2,i=1;b<=(1<<N);b<<=1,i<<=1)
		for(int j=0;j<(1<<N);j+=b)
			for(int k=0;k<i;k++)
				f[j+k]+=f[i+j+k]*x;
}
int main(){
	scanf("%d%lld%lld",&n,&X,&Y);
	if(Y%X!=0)return puts("0"),0;
	a[0]=X;for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	getfac();
	for(int i=0;i<N;i++){
		while(X%pri[i]==0)cnt[0][i]++,X/=pri[i];
		while(Y%pri[i]==0)cnt[1][i]++,Y/=pri[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<N;j++){
			cnt[2][j]=0;
			while(a[i]%pri[j]==0)cnt[2][j]++,a[i]/=pri[j];
		}
		bool ok0=1,ok1=(a[i]==1);
		for(int j=0;j<N;j++){
			ok0&=(cnt[0][j]<=cnt[2][j]);
			ok1&=(cnt[2][j]<=cnt[1][j]);
		}
		if(ok0){
			int msk=0;
			for(int j=0;j<N;j++)if(cnt[0][j]!=cnt[1][j])
				if(cnt[0][j]<cnt[2][j])msk|=(1<<j);
			A[msk]++;
		}
		if(ok1){
			int msk=0;
			for(int j=0;j<N;j++)if(cnt[0][j]!=cnt[1][j])
				if(cnt[2][j]<cnt[1][j])msk|=(1<<j);
			B[msk]++;
		}
	}
	AND(A,1),AND(B,1);
	for(int i=0;i<(1<<N);i++)A[i]=A[i]*B[i];
	AND(A,-1);
	printf("%lld",A[0]);
}