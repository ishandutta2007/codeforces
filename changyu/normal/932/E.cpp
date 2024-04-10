#include<cstdio>
typedef long long ll;
const int N=5003,M=1000000007;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int s[N][N],c[N][N],n,k,t,ans;
signed main(){
	s[0][0]=1,c[0][0]=1;
	for(int i=1;i<N;i++){
	  c[i][0]=1;
	  for(int j=1;j<N;j++){
		s[i][j]=(s[i-1][j-1]+(ll)s[i-1][j]*j)%M;
		c[i][j]=(c[i-1][j]+c[i-1][j-1])%M;
	  }
	}
	scanf("%d%d",&n,&k);
	if(n<=k){
	  for(int i=1;i<=n;i++)
		ans=(ans+(ll)Pow(i,k)*c[n][i])%M;
	  return 0*printf("%d",ans);
	}
	t=1;
	for(int j=1;j<=k;j++){
	  t=(ll)t*(n-j+1)%M;
	  ans=(ans+(ll)t*Pow(2,n-j)%M*s[k][j])%M;
	}printf("%d",ans);
	return 0;
}