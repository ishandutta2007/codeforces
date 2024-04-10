#include<bits/stdc++.h>
#define int long long
const int N=805;
using namespace std;

int n,p,f[2][N][N],ans,g[N][N],s[N],C[N][N];

void add(int&a,int b){
	if(b>p)b%=p;a+=b;if(a>p)a-=p;
}

main(){
	scanf("%lld%lld",&n,&p);
	if(n==1)printf("%lld",1%p);
	if(n==2)printf("%lld",2%p);
	f[0][2][1]=1,f[1][2][2]=1,C[0][0]=1;
	for(int i=1;i<=n*2;i++)
		for(int j=0;j<=i;j++){
			C[i][j]=C[i-1][j];
			if(j)add(C[i][j],C[i-1][j-1]);
		}
	for(int i=2;i<n;i++)
		for(int j=1;j<=i;j++)
			for(int k=1;k<=i+1;k++){
				if(k>j)
					add(f[1][i+1][k],f[1][i][j]+f[0][i][j]);
				else 
					add(f[0][i+1][k],f[0][i][j]);
			}
	s[1]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			add(s[k],f[0][k][i]+f[1][k][i]);
	g[0][0]=1,ans=s[n];
	for(int i=2;i<n;i++){
		for(int j=0;j<i-1;j++)
			for(int k=0;k<=j;k++)
				add(g[i][k+1],g[j][k]*C[i-k-1][i-j-1]%p*s[i-j-1]);
		for(int j=0;j<=i;j++)
			add(ans,g[i][j]*C[n-j][i-j]%p*s[n-i]);
	}
	printf("%lld",ans);
}