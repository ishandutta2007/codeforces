#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define maxn 50
#define ll long long 
#define p(n,i) ((n>>i-1)&1)
using namespace std;

int T,l,r;
ll f[maxn][2][2];

ll get(int n,int m){
	if (n<0||m<0) return 0;
	memset(f,0,sizeof(f));
	int cnt=0,lim=0;
	for(int x=n;x;x>>=1) cnt++; lim=max(lim,cnt);
	cnt=0;
	for(int x=m;x;x>>=1) cnt++; lim=max(lim,cnt);
	f[lim][1][1]=1;
	for(int i=lim;i;i--) for(int k1=0;k1<2;k1++) for(int k2=0;k2<2;k2++) if (f[i][k1][k2])
		for(int k3=0;k3<=1;k3++) for(int k4=0;k4<=1;k4++)
			if ((k3&k4)==0&&
				!( (k3>p(n,i)&&k1) || (k4>p(m,i)&&k2)) )
				f[i-1][k1&(k3==p(n,i))][k2&(k4==p(m,i))]+=f[i][k1][k2];
	return f[0][0][0]+f[0][0][1]+f[0][1][0]+f[0][1][1];
}

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&l,&r);
		printf("%lld\n",get(r,r)-get(l-1,r)*2+get(l-1,l-1));
	}
}