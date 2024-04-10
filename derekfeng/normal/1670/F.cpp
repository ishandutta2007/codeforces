#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
ll l,r,z;
int n,C[1006][1006];
int f[1006][2][2];
int g[1006][2][2];
int main(){
	scanf("%d%lld%lld%lld",&n,&l,&r,&z);
	for(int i=0;i<=n;C[i][0]=1,i++)
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
	f[0][1][0]=1;
	for(int i=0;i<61;i++){
		memset(g,0,sizeof(g));
		int L=(l>>i)&1,R=(r>>i)&1;
		for(int j=0;j<=n;j++){
			for(int k=(z>>i)&1;k<=n;k+=2){
				int h=(j+k)%2,w=(j+k)/2,z=C[n][k];
				for(int s=0;s<2;s++)for(int t=0;t<2;t++){
					int ns,nt;
					if(h<L)ns=0;
					if(h==L)ns=s;
					if(h>L)ns=1;
					if(h<R)nt=0;
					if(h==R)nt=t;
					if(h>R)nt=1;
					(g[w][ns][nt]+=(ll)f[j][s][t]*z%M)%=M;
				}
			}
		}
		memcpy(f,g,sizeof(g));
	}
	printf("%d",f[0][1][0]);
}