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
long long n,m,i,j,pw[1000005],sum[1000005],e=10,mod=1e9+9;
string st;
long long gts(long long l,long long r)
{
	return ((sum[r]-sum[l-1]*pw[r-l+1])%mod+mod)%mod;
}
void check(long long x,long long y,long long z)
{
	if (x>z||y>z) return;
	if (x<1||y<1||z<1) return;
	if (x>1&&st[1]=='0') return;
	if (y>1&&st[1+x]=='0') return;
	if (z>1&&st[1+x+y]=='0') return;
	if ((gts(1,x)+gts(x+1,x+y))%mod==gts(x+y+1,x+y+z))
	{
		printf("%s+%s=%s\n",st.substr(1,x).c_str(),st.substr(1+x,y).c_str(),st.substr(1+x+y,z).c_str());
		exit(0);
	}
}
int main()
{
	rdst(st,1000005);n=st.length();st=" "+st;
	pw[0]=1;
	fz1(i,n)
	{
		pw[i]=pw[i-1]*e%mod;
		sum[i]=(sum[i-1]*e+st[i]-'0')%mod;
	}
	fz1(i,n)
	{
		check(n-i-i,i,i);
		check(n-i-(i-1),i-1,i);
		check(i,n-i-i,i);
		check(i-1,n-(i-1)-i,i);
	}
	return -1;
}