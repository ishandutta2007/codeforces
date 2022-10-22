#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,M=1e9+7,i2=(M+1)/2;
int fc[1000005],iv[1000005],p2[1000005];
int myp(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
void init(){
	fc[0]=1;
	for(int i=1;i<N;i++)fc[i]=(ll)fc[i-1]*i%M;
	iv[N-1]=myp(fc[N-1],M-2);
	for(int i=N-1;i;i--)iv[i-1]=(ll)iv[i]*i%M;
	p2[0]=1;
	for(int i=1;i<N;i++)p2[i]=(ll)p2[i-1]*i2%M;
}
int C(int a,int b){
	return a<b?0:(ll)fc[a]*iv[b]%M*iv[a-b]%M;
}
int n,m,k;
void sol(){
	scanf("%d%d%d",&n,&m,&k);
	int ans=0;
	if(n==m)ans=(ll)n*k%M;
	else{
		for(int i=1,j=n-1;i<=m;i++,j--)
			(ans+=(ll)p2[j]*C(j-1,m-i)%M*i%M*k%M)%=M;
	}
	printf("%d\n",ans);
}
int main(){
	init();
	int T;scanf("%d",&T);
	while(T--)sol();
}