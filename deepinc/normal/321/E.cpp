#include<bits/stdc++.h>
using namespace std;
char I[30000000],*P=I,*E=I+30000000;
#define S 4004
int A[S][S],n,k,dp[S],use[S],cl[S],cr[S],p[S],c,ans=2e9;
int tr(int l,int r){return A[r][r]+A[l][l]-A[l][r]-A[r][l]+dp[l]+c;}
char gc(){if(P==E)fread(I,1,30000000,stdin),P=I;return *P++;}
void In(int&p){p=0;
	register char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))p=p*10+ch-48,ch=gc();
}
int main(){
	In(n);In(k);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)In(A[i][j]),A[i][j]=(i>j?A[i][j]:0)-A[i-1][j-1]+A[i][j-1]+A[i-1][j];
	cl[1]=1; cr[1]=n;
	int L=0,R=A[n][n]+5,F;
	while(c=L+R>>1,L<=R){
		for(int i=1,h=1,t=1;i<=n;++i){
			while(h<t&&cr[h]<i)h++;
			dp[i]=tr(p[h],i); use[i]=use[p[h]]+1;
			if(tr(i,n)>=tr(p[t],n))continue;
			while(h<t&&tr(p[t],cl[t])>tr(i,cl[t]))t--;
			int l=cl[t],r=cr[t]+1,a,md;
			while(md=l+r>>1,l<=r)if(tr(p[t],md)>tr(i,md))a=md,r=md-1;else l=md+1;
			cr[t]=a-1; p[++t]=i; cl[t]=a; cr[t]=n;
		}
		if(use[n]<=k)R=c-1,ans=dp[n]-k*c;
		else L=c+1;
	}printf("%d",ans);
}