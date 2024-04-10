#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
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
#define rdst(st,len){char ss[len];scanf("%s",ss);(st)=ss;}
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long n,m,i,j,dp[2][55],mod=1e9+7,inv[40005],ans=1,cnt;
long long solve(long long x,long long y)
{
	memset(dp[0],0,sizeof(dp[0]));
	dp[0][x]=1;
	long long i,j,k;
	fz1(i,m)
	{
		memset(dp[i&1],0,sizeof(dp[0]));
		fd0g(j,x)
		{
			fz(k,j,x)
			{
				(dp[i&1][j]+=dp[(i-1)&1][k]*inv[k+1])%=mod;
			}
			dp[i&1][j]%=mod;
		}
	}
	long long s=1,ans=0;
	fz0g(j,x)
	{
		ans+=dp[m&1][j]*s%mod;
		ans%=mod;
		s*=y;
		s%=mod;
	}
	return ans;
}
int main()
{
	inv[0]=inv[1]=1;
	fz(i,2,40000)
	{
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	}
	cin>>n>>m;
	for (i=2;i*i<=n;i++)
	{
		if (n%i==0)
		{
			cnt=0;
			while (n%i==0)
			{
				cnt++;
				n/=i;
			}
			ans*=solve(cnt,i%mod);
			ans%=mod;
		}
	}
	if (n>1)
	{
		ans*=solve(1,n%mod);
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}