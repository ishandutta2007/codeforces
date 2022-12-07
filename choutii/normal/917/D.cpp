#include<bits/stdc++.h>
#define N 123
#define p 1000000007
#define ll long long
using namespace std;
int n,k,g[N][N],f[N],a[N],b[N],u[N],v[N];
int fpow(int a,int n){
	int res=1;
	for(;n;n>>=1,a=(ll)a*a%p)
		if(n&1)res=(ll)res*a%p;
	return res;
}
int main(){
	int i=1,j,k,l,o; 
	for(scanf("%d",&n),i=2;i<=n;i++){
		scanf("%d%d",u+i,v+i);
	}
	for(i=0;i<n;i++){
		for(j=1;j<n;j++)
			for(k=1;k<=n;k++)g[j][k]=-i;
		for(j=2;j<=n;j++)g[u[j]][v[j]]=g[v[j]][u[j]]=-1;
		for(j=1;j<n;j++){
			g[j][j]=0;
			for(k=1;k<=n;k++)g[j][j]-=(k!=j)*g[j][k];
		}
		for(l=j=1;j<n;j++){
			for(k=j;k<n;k++)if(g[j][k])break;
			if(k==n){l=0;break;}
			if(k>j)for(l*=-1,o=j;o<n;o++)swap(g[j][o],g[k][o]);
			l=(ll)l*g[j][j]%p;o=fpow(g[j][j],p-2);
			for(k=j;k<n;k++)g[j][k]=(ll)g[j][k]*o%p;	
			for(k=j+1;k<n;k++)if(g[k][j])
				for(o=n-1;o>=j;o--)g[k][o]=(g[k][o]-(ll)g[k][j]*g[j][o])%p;
		}
		f[i]=(l+p)%p;
	}
	for(i=1;i<n;i++)for(j=n-1;j>=i;j--)f[j]=(f[j]-f[j-1]+p)%p;
	for(b[0]=f[0],i=k=a[0]=1;i<n;k=(ll)k*++i%p){
		for(j=i;j;j--)a[j]=(a[j-1]-(ll)a[j]*(i-1)%p+p)%p;
		for(f[i]=(ll)f[i]*fpow(k,p-2)%p,a[0]=j++;j<=i;j++){
			b[j]=(b[j]+(ll)a[j]*f[i]%p)%p;
		} 
	}
	for(i=n-1;~i;i--)printf("%d ",b[i]);return 0;
}