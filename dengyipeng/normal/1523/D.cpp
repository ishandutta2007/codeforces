#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<ctime>
#define maxn 200005
#define maxm 61
#define maxp 16
#define ll long long 
using namespace std;
 
int n,m,p,i,j,k,d[maxm],P[maxm],a[maxn];
ll bz[maxn];
int f[1<<maxp],C[1<<maxp],ansp[maxm];
 
mt19937 ran;
void getr(){
	int K=13,M=1045141;
	ll s=/*time(0)*/1919810;
	double sum=0;
	ran.seed(s);
	while (K--){
		for (int i=ran()%M;i>=0;--i){
			sum+=(ll)floor(log(asin(sqrt(ran()^i)+exp(sin(ran()+i)))));
			s^=(ran()+i)*(ran()^i);
		}
//		printf("%lld\n",s);
			//s=(s+ran())^i;
		ran.seed(clock()^s);
	}
//	printf("%d\n",ran());
} 
 
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(i=1;i<=n;i++){
		char ch=getchar();
		while (ch!='0'&&ch!='1') ch=getchar();
		for(j=0;j<m;j++) {
			if (ch-'0') bz[i]|=1ll<<j;
			ch=getchar();
		}
	}
	getr();
	for(i=2,a[1]=1;i<=n;i++) 
		a[i]=i,swap(a[i],a[(ran()>>1)%(i-1)+1]);
	int ans=0;
	for(int now=1;now<=min(15,n);now++){
		int c=0;
		for(i=1;i<=m;i++) if (bz[a[now]]>>i-1&1)
			d[++c]=i,P[i]=c; else P[i]=0;
		memset(f,0,sizeof(f));
		for(i=1;i<=n;i++){
			ll S=0;
			for(j=1;j<=c;j++) if (bz[i]>>d[j]-1&1)
				S|=1<<j-1;
			f[S]++;
		}
		for(i=0;i<c;i++) for(int S=0;S<1<<c;S++) if (S>>i&1) f[S^(1<<i)]+=f[S];
		for(int S=1;S<1<<c;S++) C[S]=C[S>>1]+(S&1);
		for(int S=0;S<1<<c;S++) if (f[S]>=(n+1)/2&&C[S]>ans){
			ans=C[S];
			for(i=1;i<=m;i++) ansp[i]=(P[i]>0&&(S>>P[i]-1&1));
		}
	}
	for(i=1;i<=m;i++) printf("%d",ansp[i]);
}