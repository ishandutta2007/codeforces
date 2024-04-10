#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int Mod=998244353;
int qpow(int x,int y=Mod-2){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%Mod)
		if (y&1) res=1LL*res*x%Mod;
	return res;
}
int upd(int x){return x+(x>>31&Mod);}

int n,m,w[100010];
int _a[300010][4],b[300010];  //a'[i][j]->a[i][i+j-1];
int& a(int x,int y){
	assert(0<=x&&x<=m&&0<=y&&y<=m);
	assert(x-1<=y<=x+2);
	return _a[x][y-x+1];
}
void gauss(int n,int k){
	for (int i=0;i<=n;i++){
		int p=-1;
		for (int j=i;j<=n&&j<=i+k;j++) if (a(j,i)){p=j;break;}
		assert(~p);
		if (i^p){
			for (int j=i;j<=n&&j<=i+k+k;j++) swap(a(i,j),a(p,j));
			swap(b[i],b[p]);
		}
		int t=qpow(a(i,i));
		for (int j=i;j<=n&&j<=i+k+k;j++) a(i,j)=1LL*a(i,j)*t%Mod; b[i]=1LL*b[i]*t%Mod;
		for (int j=i+1;j<=n&&j<=i+k;j++){
			if (!a(j,i)) continue;
			t=a(j,i);
			for (int u=i;u<=n&&u<=i+k+k;u++)
				a(j,u)=(a(j,u)-1LL*a(i,u)*t)%Mod;
			b[j]=(b[j]-1LL*b[i]*t)%Mod;
		}
	}
	for (int i=n;i>=0;i--){
		for (int j=i+1;j<=n&&j<=i+k+k;j++) b[i]=(b[i]-1LL*b[j]*a(i,j))%Mod;
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",w+i),m+=w[i];
	a(0,0)=(1LL*(n-2)*qpow(n-1)-1)%Mod; a(0,1)=qpow(n-1); b[0]=-1;
	for (int i=1;i<m;i++){
		a(i,i-1)=1LL*i*qpow(m)%Mod;
		a(i,i)=(1LL*(m-i)*(n-2)%Mod*qpow(1LL*m*(n-1)%Mod)-1)%Mod;
		a(i,i+1)=1LL*(m-i)*qpow(1LL*m*(n-1)%Mod)%Mod;
		b[i]=-1;
	}
	a(m,m)=1; b[m]=0;
	gauss(m,1);
	int ans=0;
	for (int i=1;i<=n;i++) ans=(ans+b[w[i]])%Mod;
	ans=(ans-1LL*b[0]*(n-1))%Mod;
	ans=1LL*ans*qpow(n)%Mod;
	printf("%d\n",upd(ans));
	return 0;
}