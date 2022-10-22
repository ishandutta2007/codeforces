#include<cstdio>
#include<vector>
typedef long long ll;
const int M=1e9+7,N=1e5+3;
int n,f[N],inv[N],g[N];
std::vector<int>d[N];
int main(){
	scanf("%d",&n);
	inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=(ll)inv[M%i]*(M-M/i)%M;
	for(int i=n;i;i--)
	  for(int j=i;j<=n;j+=i)d[j].push_back(i);
	f[1]=0;
	for(int i=2;i<=n;i++){
	  for(int j=0,div;j<d[i].size();j++){
		div=d[i][j];
		g[div]=n/div;
		for(int k=0;k+1<d[i/div].size();k++)g[div]-=g[d[i/div][k]*div];
		f[i]=(f[i]+(ll)f[div]*g[div])%M;
	  }
	  f[i]=((ll)(f[i]+n)*inv[n-n/i])%M;
	  f[0]=(f[0]+f[i])%M;
	}
	f[0]=((ll)(f[0]+n)*inv[n])%M;
	printf("%d\n",f[0]);
	return 0;
}