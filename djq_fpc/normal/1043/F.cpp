#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<iomanip>
#define sqr(x) (x)*(x)
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ int
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
//struct bit_2d{T_ a[2005][2005];int lowbit(int x){return x&(-x);}void add(int x,int y,T_ z){int i,j;for (i=x;i<=2000;i+=lowbit(i)){for (j=y;j<=2000;j+=lowbit(j)){a[i][j]+=z;}}}T_ query(int x,int y){int i,j;T_ s=0;for (i=x;i;i-=lowbit(i)){for (j=y;j;j-=lowbit(j)){s+=a[i][j];}}return s;}T_ query(int x,int y,int xx,int yy){return query(xx,yy)-query(x-1,yy)-query(xx,y-1)+query(x-1,y-1);}};
long long n,m,i,j,x,np[300005],mu[300005],cnt[300005],f[300005],fac[300005],inv[300005],fi[300005],mod=998244353;
vector<long long> p;
void fake(long long x)
{
	int i;
	long long s=0;
	fz1(i,300000)
	{
		if (mu[i]&&cnt[i]>=x)
		{
			(s+=mu[i]*fac[cnt[i]]%mod*fi[x]%mod*fi[cnt[i]-x])%=mod;
		}
	}
	if (s)
	{
		cout<<x;
		exit(0);
	}
}
int main()
{
	scanf("%I64d",&n);
	fac[0]=fac[1]=inv[0]=inv[1]=fi[0]=fi[1]=1;
	fz(i,2,300000)
	{
		fac[i]=fac[i-1]*i%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		fi[i]=fi[i-1]*inv[i]%mod;
	}
	fz1(i,n)
	{
		scanf("%d",&x);
		cnt[x]++;
	}
	fz1(i,300000)
	{
		for (j=2;i*j<=300000;j++)
		{
			cnt[i]+=cnt[i*j];
		}
	}
	mu[1]=1;
	for (i=2;i<=300000;i++)
	{
		if (!np[i])
		{
			p.push_back(i);
			mu[i]=-1;
		}
		for (j=0;j<p.size()&&i*p[j]<=300000;j++)
		{
			np[i*p[j]]=1;
			if (i%p[j]==0)
			{
				mu[i*p[j]]=0;
				break;
			}
			else
			{
				mu[i*p[j]]=-mu[i];
			}
		}
	}
	fz1(i,15) fake(i);
	puts("-1");
	return 0;
}