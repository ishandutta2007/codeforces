#include<bits/stdc++.h>
using namespace std;
const int M=998244353,B=16;
int n,m,a[5],b[5];
int f[32][33][33][16][16][2][2];
int nx[32],ny[32],dx[32],dy[32];
void add(int &A,int B){
	A+=B;
	if(A>=M)A-=M;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)if((1<<j)&i){
			nx[i]+=a[j],ny[i]+=b[j];
			dx[i]+=a[j]>0?a[j]:0,dy[i]+=b[j]>0?b[j]:0;
		}
	f[0][B][B][0][0][0][0]=1;
	for(int i=0;i<31;++i)for(int j=0;j<33;++j)for(int k=0;k<33;++k)for(int p=0;p<16;++p)for(int q=0;q<16;++q)for(int s=0;s<2;++s)for(int t=0;t<2;++t)if(f[i][j][k][p][q][s][t])
		for(int msk=0;msk<(1<<n);++msk){
			int nj=j-B+nx[msk],nk=k-B+ny[msk];
			if(nj%2!=0||nk%2!=0)continue;
			nj=nj/2+B,nk=nk/2+B;
			int np=p+dx[msk],nq=q+dy[msk];
			int pp=np&1,qq=nq&1,mm=(m>>i)&1;
			int ns=0,nt=0;
			if(pp==mm)ns=s;
			if(pp>mm)ns=1;
			if(qq==mm)nt=t;
			if(qq>mm)nt=1;
			np/=2,nq/=2;
			add(f[i+1][nj][nk][np][nq][ns][nt],f[i][j][k][p][q][s][t]);
		}
	printf("%d",(f[31][B][B][0][0][0][0]+M-1)%M);
}