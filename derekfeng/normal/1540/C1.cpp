#include<bits/stdc++.h>
using namespace std;
const int M=1e9+7;
void add(int &A,int B){
	A+=B;
	if(A>=M)A-=M;
}
int f[10004],g[10004],sum,sb;
int n,q,x,c[103],b[103];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	for(int i=1;i<n;i++)scanf("%d",&b[i]);
	scanf("%d%d",&q,&x);
	f[0]=1;
	for(int i=1;i<=n;i++){
		sum+=b[i-1],sb+=sum;
		memset(g,0,sizeof(g));
		for(int j=0;j<=1e4;j++)g[j]=g[j-1],add(g[j],f[j]);
		for(int j=0;j<=1e4;j++){
			f[j]=g[j];
			if(j>c[i])add(f[j],M-g[j-c[i]-1]);
		}
		for(int j=0;j<min(sb+i*x,(int)10001);j++)f[j]=0;
	}
	int ans=0;
	for(int i=0;i<=1e4;i++)add(ans,f[i]);
	printf("%d",ans);
}