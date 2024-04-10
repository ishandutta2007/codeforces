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
#define rdst(st,len){char ss[len];scanf(" %s",ss);(st)=ss;}
//#define T_ long long
using namespace std;
//struct bit{T_ arr[1000005];int lowbit(int x){return x&(-x);}void add(int x,T_ y){for (int i=x;i<=n;i+=lowbit(i)) arr[i]+=y;}T_ query(int x){T_ s=0;for (int i=x;i>0;i-=lowbit(i)) s+=arr[i];return s;}};
//struct seg{struct treedot{int l,r;T_ sum,add;void update(T_ x){sum+=(r-l+1)*x; add+=x;}}c[800005];void pushdown(int id){if (c[id].add){c[id*2].update(c[id].add);c[id*2+1].update(c[id].add);c[id].add=0;}}void pushup(int id){c[id].sum=c[id*2].sum+c[id*2+1].sum;}void build(int id,int l,int r){if (l>r) return;c[id].l=l;c[id].r=r;c[id].sum=0;c[id].add=0;if (l==r) c[id].sum=0;else{int mid=l+(r-l)/2;build(id*2,l,mid);build(id*2+1,mid+1,r);pushup(id);}}void update(int id,int le,int ri,T_ x){if (le>c[id].r||ri<c[id].l) return;if (le<=c[id].l&&c[id].r<=ri) c[id].update(x);else{pushdown(id);update(id*2,le,ri,x);update(id*2+1,le,ri,x);pushup(id);}}T_ query(int id,int le,int ri){if (ri<c[id].l||c[id].r<le) return 0;if (le<=c[id].l&&c[id].r<=ri) return c[id].sum;T_ ans=0;pushdown(id);ans+=query(id*2,le,ri);ans+=query(id*2+1,le,ri);pushup(id);return ans;}};
long long hsh[200005][26],e=1e6+33,mod=1e9+9,fe,pw[200005],fpw[200005];
string st;
int n,m,i,j,x,y,len;
vector<int> h1,h2;
long long qp(long long x,long long y)
{
	if (y==0) return 1;
	long long z=qp(x,y/2);
	z=z*z%mod;
	if (y&1) z=z*x%mod;
	return z;
}
long long calc(int x,int len,int y)
{
	return (hsh[x+len-1][y]-hsh[x-1][y]*pw[len]%mod+mod)%mod;
}
int main()
{
	scanf("%d%d",&n,&m);
	rdst(st,n+5);
	st=" "+st;
	pw[0]=fpw[0]=1;
	fe=qp(e,mod-2);
	fz1(i,n)
	{
		pw[i]=pw[i-1]*e%mod;
		fpw[i]=fpw[i-1]*fe%mod;
		fz0k(j,26)
		{
			hsh[i][j]=hsh[i-1][j]*e%mod;
		}
		hsh[i][st[i]-'a']++;
		hsh[i][st[i]-'a']%=mod;
	}
	fz1(i,m)
	{
		scanf("%d%d%d",&x,&y,&len);
		h1.clear();h2.clear();
		fz0k(j,26)
		{
		//	cerr<<calc(x,len,j)<<' '<<calc(y,len,j)<<endl;
			h1.push_back(calc(x,len,j));
			h2.push_back(calc(y,len,j));
		}
		sort(h1.begin(),h1.end());
		sort(h2.begin(),h2.end());
		fz0k(j,26)
		{
			if (h1[j]!=h2[j]) break;
		}
		if (j==26) puts("YES"); else puts("NO");
	}
	return 0;
}