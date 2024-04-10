#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=130000;
int n,M,ans;
int f[260000],g[260000];
int s1[260000],s2[260000];
void add(int &A,int B){A+=B;if(A>=M)A-=M;}
int main(){
	scanf("%d%d",&n,&M);
	f[N]=1;
	for(int i=2;i<=n;i++){
		ans=(ll)ans*i%M;
		memset(g,0,sizeof(g));
		int lim=i*(i-1)/2;
		for(int j=N-lim-i-1;j<=N+lim+i+1;j++){
			s1[j]=f[j],s2[j]=(ll)f[j]*j%M;
			add(s1[j],s1[j-1]),add(s2[j],s2[j-1]);
		}
		for(int j=N-lim;j<=N+lim;j++){
			int tmp1=(s1[j+i-1]-s1[j]+M)%M,tmp2=(s2[j+i-1]-s2[j]+M)%M;
			add(g[j],((ll)(i+j)*tmp1%M-tmp2+M)%M);
			if(j>N)add(ans,g[j]);
		}
		for(int j=N-lim;j<=N+lim;j++){
			int tmp1=(s1[j]-s1[j-i]+M)%M,tmp2=(s2[j]-s2[j-i]+M)%M;
			add(g[j],((ll)(i%M-j%M+M)%M*tmp1%M+tmp2)%M);
		}
		memcpy(f,g,sizeof(f));
	}
	printf("%d",ans);
}