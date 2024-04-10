#include<cstdio>
#include<algorithm>
typedef long long ll;
const int N=2003,A=200003,M=1e9+7;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
struct point{int x,y;}a[N];
bool Cmp(const point&a,const point&b){return a.x==b.x?a.y<b.y:a.x<b.x;}
int h,w,n,g[N],f[A],invf[A],ans;
inline int C(int n,int m){return(ll)f[n]*invf[m]%M*invf[n-m]%M;}
signed main(){
	scanf("%d%d%d",&h,&w,&n);
	f[0]=1;
	for(int i=1;i<=h+w;i++)f[i]=(ll)f[i-1]*i%M;
	invf[h+w]=Pow(f[h+w],M-2);
	for(int i=h+w;i>=1;i--)invf[i-1]=(ll)invf[i]*i%M;
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a+1,a+1+n,Cmp);
	for(int i=1;i<=n;i++){
	  g[i]=C(a[i].x+a[i].y-2,a[i].x-1);
	  for(int j=1;j<i;j++)if(a[j].x<=a[i].x&&a[j].y<=a[i].y)
		g[i]=(g[i]-(ll)g[j]*C(a[i].x+a[i].y-a[j].x-a[j].y,a[i].x-a[j].x)%M+M)%M;
	  ans=(ans+(ll)g[i]*C(h+w-a[i].x-a[i].y,h-a[i].x))%M;
	}
	printf("%d",(C(h+w-2,h-1)-ans+M)%M);
	return 0;
}