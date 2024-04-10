#include<cstdio>
#include<algorithm>
using namespace std;
#define ll long long
const int MOD=1e9+7;
struct mint{int x;mint(int x=0):x(x){}};
inline mint operator+  (mint a,mint b){return a.x+b.x<MOD?a.x+b.x:a.x+b.x-MOD;}
inline mint operator-  (mint a){return MOD-a.x;}
inline mint operator-  (mint a,mint b){return a+-b;}
inline mint operator*  (mint a,mint b){return 1LL*a.x*b.x%MOD;}
inline mint operator<< (mint x,ll y){mint r=1;for(;y;y>>=1,x=x*x)if(y&1)r=r*x;return r;}
inline mint operator~  (mint x){return x<<MOD-2;}
inline mint operator/  (mint a,mint b){return a*~b;}
inline mint&operator+= (mint&a,mint b){return a=a+b;}
inline mint&operator-= (mint&a,mint b){return a=a-b;}
inline mint&operator*= (mint&a,mint b){return a=a*b;}
inline mint&operator<<=(mint&x,int y){return x=x<<y;}
inline mint&operator/= (mint&a,mint b){return a=a/b;}
#define MN 600000
char a[MN+5],b[MN+5];
int u[MN+5],p[MN+5],pn;
ll n;mint ans,S,s,F[MN+5],R[MN+5],mu[MN+5];
inline mint C(int n,int m){return F[n]*R[m]*R[n-m];}
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
	int i,j,sa=0,sb=0,ac=0,bc=0,x,y;
	scanf("%s%s%lld",a,b,&n);
	for(F[0]=i=1;i<=MN;++i)F[i]=F[i-1]*i;
	for(R[i=MN]=~F[MN];i--;)R[i]=R[i+1]*(i+1);
	for(mu[1]=1,i=2;i<=n;++i)
	{
		if(!u[i])mu[p[++pn]=i]=MOD-1;
		for(j=1;i*p[j]<=n;++j)if(u[i*p[j]]=1,i%p[j])mu[i*p[j]]=-mu[i];else break;
	}
	for(i=0;a[i];++i)a[i]=='A'?++sa:(--sb,a[i]=='?'?++ac:0);
	for(i=0;b[i];++i)b[i]=='A'?--sa:(++sb,b[i]=='?'?++bc:0);
	if(sa==sb)
	{
		for(i=1;i<=n;S+=s*(mint(2)<<i++))for(s=0,j=1;j<=n/i;++j)s+=mu[j]*(n/i/j)*(n/i/j);
		ans=((mint(2)<<n+1)-2)*((mint(2)<<n+1)-2)-S;
		for(i=0;a[i];++i)
		{
			if(a[i]=='?'&&b[i]=='?')ans*=2;
			if(a[i]!='?'&&b[i]!='?'&&a[i]!=b[i])ans=0;
		}
	}
	for(i=-bc;i<=ac;++i)
	{
		x=sa+i;y=sb+i;
		if(!x&&!y)ans+=S*C(ac+bc,ac-i);
		if(1LL*x*y<=0)continue;
		if(x<0)x=-x,y=-y;
		ans+=((mint(2)<<n/(max(x,y)/gcd(x,y))+1)-2)*C(ac+bc,ac-i);
	}
	printf("%d",ans);
}