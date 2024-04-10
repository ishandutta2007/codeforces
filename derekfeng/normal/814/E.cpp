#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
void add(int &a,int b){
	a+=b;
	if(a>=M)a-=M;
}
int mypow(int x,int t){
	int ans=1,res=x;
	while(t){
		if(t&1)ans=(ll)ans*res%M;
		res=(ll)res*res%M,t>>=1;
	}
	return ans;
}
int n;
int fac[103],inv[103],p2[53],d[53],s1[53],s2[53],coef[53];
int f[53][53],g[53][103];
void init(){
	fac[0]=1;
	for(int i=1;i<=100;i++)fac[i]=(ll)fac[i-1]*i%M;
	inv[100]=mypow(fac[100],M-2);
	for(int i=99;~i;i--)inv[i]=(ll)inv[i+1]*(i+1)%M;
	p2[0]=1;
	for(int i=1;i<=n;i++)p2[i]=(ll)p2[i-1]*inv[2]%M;
}
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		if(i>1){
			d[i]--;
			s1[i]=s1[i-1],s2[i]=s2[i-1];
			if(d[i]==1)s1[i]++;
			else s2[i]++;
		}
	}
	for(int s=0;s<=n;s++)for(int p=0;p*2<=s;p++){
		int q=s-2*p,t=(ll)inv[p]*inv[q]%M;
		if((p+q)&1)add(coef[s],M-t);
		else add(coef[s],t);
	}
	f[1][d[1]]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=2*n;j++)if(g[i][j])
			for(int d=0;d*2<=j;d++)
				add(f[i][j-d*2],(ll)g[i][j]*inv[d]%M*p2[d]%M);
		for(int j=1;i+j<=n;j++)if(f[i][j]){
			int x=s1[i+j]-s1[i],y=s2[i+j]-s2[i];
			int res=(ll)f[i][j]*fac[y]%M;
			for(int s=0;s<=y;s++)
				add(g[i+j][x+2*y-2*s],(ll)res*coef[s]%M*fac[x+2*y-2*s]%M*inv[y-s]%M);
		}
	}
	int ans=f[n][0];
	for(int i=2;i<=n;i++)ans=(ll)ans*inv[d[i]]%M;
	printf("%d",ans);
}