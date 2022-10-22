#include<bits/stdc++.h>
typedef long long ll;
const int K=5003,M=998244353;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
int s[K][K],n,m,invm,k,ans,s1,s2;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(m==1)return 0*printf("%d\n",Pow(n,k));
	s[0][0]=1;
	for(int i=1;i<=k;i++)
	  for(int j=1;j<=i;j++)
		s[i][j]=(s[i-1][j-1]+(ll)s[i-1][j]*j)%M;
	invm=Pow(m,M-2);
	s1=1,s2=1;
	for(int j=1;j<=k;j++){
	  s1=(ll)s1*(n-j+1)%M;
	  s2=(ll)s2*invm%M;
	  ans=(ans+(ll)s[k][j]*s1%M*s2)%M;
	}printf("%d\n",ans);
	return 0;
}