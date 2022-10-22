#include<cstdio>
typedef long long ll;
const int N=103,M=1e9+7,MM=1e9+6;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int len,n,ans[N],f0[N],f1[N],g[N][N][N],h0[N][N][N],h1[N][N][N];char s[N];
int main(){
	scanf("%d%d%s",&len,&n,s+1),++n;
	f0[1]=0,f0[2]=1;
	for(int i=3;i<=n;i++)f0[i]=(f0[i-1]+f0[i-2])%M;
	f1[1]=0,f1[2]=1;
	for(int i=3;i<=n;i++)f1[i]=(f1[i-1]+f1[i-2])%MM;
	for(int j=1;j<=len;j++)
	  g[1][j][j]=s[j]=='0';
	for(int i=2;i<=n;i++){
	  for(int j=1;j<=len;j++)
		g[i][j][j]=s[j]=='1'?f0[i]:f0[i-1];
	  for(int l=1;l<=len;l++)
		for(int r=l+1;r<=len;r++){
		  g[i][l][r]=(g[i-2][l][r]+g[i-1][l][r])%M;
		  for(int k=l;k<r;k++)
			g[i][l][r]=(g[i][l][r]+(ll)g[i-1][l][k]*g[i-2][k+1][r])%M;
		}
	}
	for(int j=1;j<=len;j++){
	  h0[1][j][j]=s[j]=='0';
	  h1[1][j][j]=s[j]=='0';
	}
	for(int i=2;i<=n;i++){
	  for(int j=1;j<=len;j++){
		if(i==2){
		  h0[i][j][j]=s[j]=='1';
		  h1[i][j][j]=s[j]=='1';
		}
		else{
		  h0[i][j][j]=((ll)h0[i-2][j][j]*Pow(2,f1[i])+h0[i-1][j][j])%M;
		  h1[i][j][j]=(h1[i-2][j][j]+(ll)h1[i-1][j][j]*Pow(2,f1[i-1]))%M;
		}
	  }
	  for(int l=1;l<=len;l++)
		for(int r=l+1;r<=len;r++){
		  h0[i][l][r]=((ll)h0[i-2][l][r]*Pow(2,f1[i])+h0[i-1][l][r])%M;
		  h1[i][l][r]=(h1[i-2][l][r]+(ll)h1[i-1][l][r]*Pow(2,f1[i-1]))%M;
		  for(int k=l;k<r;k++){
			h0[i][l][r]=(h0[i][l][r]+(ll)h0[i-1][l][k]*g[i-2][k+1][r])%M;
			h1[i][l][r]=(h1[i][l][r]+(ll)g[i-1][l][k]*h1[i-2][k+1][r])%M;
		  }
		}
	}
	ans[1]=len==1&&s[1]=='0';
	ans[2]=len==1&&s[1]=='1';
	for(int i=3;i<=n;i++){
	  ans[i]=((ll)ans[i-2]*Pow(2,f1[i])+(ll)ans[i-1]*Pow(2,f1[i-1]))%M;
	  for(int j=1;j<len;j++)
		ans[i]=(ans[i]+(ll)h0[i-1][1][j]*h1[i-2][j+1][len])%M;
	}printf("%d\n",ans[n]);
	return 0;
}