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
int n,m,i,j,mod=1e9+7,dp[1000005],sum[1000005];
vector<int> bi[1000005];
struct ii
{
	int l,r;
}a[1000005];
vector<int> all;
bool cmp(ii x,ii y)
{
	return x.r<y.r;
}
int main()
{
	scanf("%d%d",&n,&m);
	all.push_back(0);all.push_back(n);
	fz1(i,m)
	{
		scanf("%d%d",&a[i].l,&a[i].r);
		all.push_back(a[i].l);
		all.push_back(a[i].r);
	}
	sort(all.begin(),all.end());
	all.resize(unique(all.begin(),all.end())-all.begin());
	sort(a+1,a+m+1,cmp);
	dp[1]=sum[1]=1;
	int t=1;
	fz1(i,m)
	{
		a[i].l=upper_bound(all.begin(),all.end(),a[i].l)-all.begin();
		a[i].r=upper_bound(all.begin(),all.end(),a[i].r)-all.begin();
		while (t<a[i].r)
		{
			t++;
			sum[t]=(sum[t-1]+dp[t])%mod;
		}
		(dp[a[i].r]+=(sum[a[i].r-1]-sum[a[i].l-1])%mod)%=mod;
		sum[a[i].r]=(sum[a[i].r-1]+dp[a[i].r])%mod;
	}
	cout<<(dp[all.size()]%mod+mod)%mod<<endl;
	return 0;
}