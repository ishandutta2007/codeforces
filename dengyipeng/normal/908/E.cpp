#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxm 1005
#define mo 1000000007
#define ll long long 
using namespace std;

int n,m,i,j,k,bz[maxm],cnt,f[maxm][maxm];
ll B[maxm],jc[maxm],ny[maxm],ans;
char ch;

ll ksm(ll x,ll y){
	ll s=1;
	for(;y;y/=2,x=x*x%mo) if (y&1)
		s=s*x%mo;
	return s;
}

ll C(int m,int n){return jc[m]*ny[n]%mo*ny[m-n]%mo;}

int main(){
//	freopen("ceshi.in","r",stdin);
	scanf("%d%d",&m,&n);
	jc[0]=ny[0]=1;
	for(i=1;i<=m;i++) jc[i]=jc[i-1]*i%mo,ny[i]=ny[i-1]*ksm(i,mo-2)%mo;
	B[0]=1;
	for(i=1;i<=m;i++) {
		for(j=0;j<=i-1;j++) 
			B[i]=(B[i]+C(i-1,j)*B[j]%mo)%mo;
	}
	for(i=1;i<=m;i++) for(j=1;j<=m;j++) f[i][j]=1;
	while (n--){
		ch=getchar();
		while (ch<'0'||ch>'1') ch=getchar();
		for(i=1;i<=m;i++) bz[i]=ch-'0',ch=getchar();
		for(i=1;i<=m;i++) {
			for(j=1;j<=m;j++) if (bz[j]!=bz[i])
				f[i][j]=0;
		}
	}
	memset(bz,0,sizeof(bz));
	ans=1;
	for(i=1;i<=m;i++) if (!bz[i]){
		cnt=0;
		for(j=1;j<=m;j++) if (f[i][j])
			cnt++,bz[j]=1;
		ans=ans*B[cnt]%mo;
	}
	printf("%I64d",ans);
//	printf("%lld",ans);
}