#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1005
#define ll long long 
using namespace std;

int n,m,i,j,k,a[maxn][maxn],p,v;
ll s1[maxn],s2[maxn];

int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++) {
			scanf("%d",&a[i][j]);
			s1[i]+=a[i][j],s2[i]+=1ll*a[i][j]*a[i][j];
		}
	}
	ll g;
	for(i=2;i<=m;i++){
		g=s1[i]-s1[i-1]; int cnt=0;
		for(j=2;j<=m;j++) if (s1[j]-s1[j-1]==g) cnt++;
		if (cnt>=m-3){
			for(j=2;j<=m;j++) if (s1[j]-s1[j-1]!=g){p=j;break;}
			break;
		}
	}
	int L; if (p<=3) L=4; else L=1;
	
	ll v1=s2[L+1]-s2[L],v2=s2[L+2]-s2[L+1];
	ll v0=(v2-v1)/2;
	ll d=(s1[p]-s1[p-1])-g;
	ll s0; if (p>=3) s0=s2[p-1]*2-s2[p-2]+v0*2; else s0=s2[p+1]*2-s2[p+2]+v0*2;
	ll d0=s2[p]-s0;
	v=(d0-d*d)/2/d;
	printf("%d %d\n",p-1,v);
}