#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int mypow(int x,int t){
	int ans=1,res=x;
	for(;t;t>>=1,res=(ll)res*res%M)if(t&1)ans=(ll)ans*res%M;
	return ans;
}
int fc[3000006],inv[3000006];
int n,q,f[4],g[3000006],h[3000006];
void init(){
	fc[0]=1;
	for(int i=1;i<=3*n+3;i++)fc[i]=(ll)fc[i-1]*i%M;
	inv[3*n+3]=mypow(fc[3*n+3],M-2);
	for(int i=3*n+3;i;i--)inv[i-1]=(ll)inv[i]*i%M;
}
int C(int a,int b){
	return a<b?0:(ll)fc[a]*inv[b]%M*inv[a-b]%M;
}
int main(){
	f[0]=1,f[1]=3,f[2]=3,f[3]=1;
	scanf("%d%d",&n,&q);
	init();
	for(int i=0;i<=3*n+3;i++)g[i]=C(3*n+3,i);
	for(int i=0;i<=3;i++)g[i]=(g[i]+M-f[i])%M;
	f[0]=0;
	for(int i=3*n+3;i;i--)if(g[i]){
		int tmp=g[i];
		h[i-3]=tmp;
		for(int j=2;j;j--)(g[i-j]+=M-3ll*tmp%M)%=M;
	}
	while(q--){
		int x;scanf("%d",&x);
		printf("%d\n",h[x]);
	}
}