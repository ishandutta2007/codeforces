#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,dl,dr,i,j,k,a[6005],cnt;
double px[12005],py[12005];
double ans[6005],t,res;
int main()
{
	read(n);read(m);read(dl);read(dr);
	fz1(i,n) read(a[i]);
	cnt=2;
	px[1]=1;py[1]=2.0*(1-a[1]);
	px[2]=m;py[2]=2.0*(m-a[1]);
	t=px[1]-py[1]/(py[2]-py[1])*(px[2]-px[1]);
	ans[1]=t;k=1;
	fz(i,2,n){
		for(j=cnt;j>k;j--){
			px[j+2]=px[j];
			py[j+2]=py[j];
		}
		k++;
		px[k]=px[k+1]=t;
		py[k]=py[k+1]=0;
		cnt+=2;
		fz1(j,cnt) if(j<=k) px[j]+=dl; else px[j]+=dr;
		fz1(j,cnt) py[j]+=2.0*(px[j]-a[i]);
		if(py[1]>=0){
			k=0;t=px[1];
		}
		else{
			k=0;while(py[k+1]<0) k++;
			t=px[k]-py[k]/(py[k+1]-py[k])*(px[k+1]-px[k]);
		}
		ans[i]=t;
	}
	ans[n]=min(ans[n],1.0*m);
	fd1(i,n-1){
		ans[i]=min(ans[i+1]-dl,max(ans[i+1]-dr,ans[i]));
	}
	fz1(i,n) res+=sqr(ans[i]-a[i]);
	fz1(i,n)printf("%.10f%c",ans[i],spln(i,n));
	printf("%.10f\n",res);
	return 0;
}