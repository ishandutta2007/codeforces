#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
	char ch=getchar(); int x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}
const int N=55;
const int M=1505;

int n,mod,mx[N],f[N][N][M],fact[N],c[N][N],p[M],ans;
void upd(int &x,int y){x=(x+y)%mod;}
int c2(int x){return 1LL*x*(x-1LL)/2LL%mod;}

int main(){
	n=read(); mod=read();
	for(int i=1;i<=n;i++) mx[i]=i*(i-1)/2;
	f[1][1][0]=1;
	for(int i=1;i<n;i++)
		for(int st=1;st<=i;st++)
			for(int j=0;j<=mx[i];j++){
				for(int k=1;k<=i;k++) upd(f[i+1][st][j+i-k],f[i][st][j]);
				upd(f[i+1][i+1][j+i],f[i][st][j]);
			}
	fact[0]=c[0][0]=1;
	for(int i=1;i<=n;i++) c[i][0]=1,fact[i]=1LL*fact[i-1]*i%mod;
	for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	for(int l=1;l<=n;l++){
		int tt=n-l+1,coef=1LL*c[n][l-1]*fact[l-1]%mod;
		memset(p,0,sizeof(p));
		for(int i=tt;i;i--){
			for(int ii=1;ii<=mx[tt];ii++) upd(ans,1LL*coef*f[tt][i][ii]%mod*p[ii-1]%mod);
			int sp=0;
			for(int ii=0;ii<=mx[tt];ii++) upd(sp,f[tt][i][ii]),upd(p[ii],sp);
		}
	}
	cout<<ans<<'\n';
	return 0;
}