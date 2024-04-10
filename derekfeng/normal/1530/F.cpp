#include<bits/stdc++.h>
using namespace std;
const int M=31607;
int mypow(int x,int t){int ans=1,res=x;while(t){if(t&1)ans=ans*res%M;res=res*res%M,t>>=1;}return ans;}
int inv[10003];
int n,a[22][22],b[22][22];
int f[2097252][22],ps[2097252],ans;
void trans(int msk){
	int lowbit=msk&-msk,LG=__lg(lowbit),fr=msk^lowbit;
	ps[msk]=ps[fr];
	for(int j=0;j<n;j++)ps[msk]=ps[msk]*b[LG][j]%M;
}
int main(){
	int INV=mypow(10000,M-2);
	scanf("%d",&n);
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&a[i][j]),a[i][j]=a[i][j]*INV%M;
	for(int t1=0;t1<2;t1++)for(int t2=0;t2<2;t2++){
		memcpy(b,a,sizeof(a));
		int s=1;
		if(t1)for(int k=0;k<n;k++)s=s*b[k][k]%M,b[k][k]=1;
		if(t2)for(int k=0;k<n;k++)s=s*b[k][n-k-1]%M,b[k][n-k-1]=1;
		ps[0]=1;
		for(int i=1;i<(1<<n);i++)trans(i);
		for(int i=(1<<n)-1;~i;i--){
			int msk=i^((1<<n)-1);
			if(msk==0)for(int j=0;j<n;j++)f[msk][j]=1;
			else{
				int lowbit=msk&-msk,LG=__lg(lowbit),fr=msk^lowbit;
				for(int j=0;j<n;j++)f[msk][j]=f[fr][j]*b[LG][j]%M;
			}
			int s0=s*ps[i]%M,s1=0;
			for(int j=0;j<n;j++){
				int p1=f[msk][j];
				int f0=0,f1=0;
				f0=(s0+s1*p1)%M;
				f1=(s0*p1+s1)%M;
				s0=f0,s1=f1;
			}
			int coef=(__builtin_popcount(i)&1)^t1^t2;
			if(coef&1)ans=(ans-s0+M)%M,ans=(ans+s1)%M;
			else ans=(ans+s0)%M,ans=(ans-s1+M)%M;
		}
	}
	printf("%d",(M+1-ans)%M);
}