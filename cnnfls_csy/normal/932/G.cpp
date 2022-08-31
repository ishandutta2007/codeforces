#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
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
int n,m,i,j,ch[1000005][27],fa[1000005],tp[1000005],sum[1000005],dp[1000005],df[1000005],len[1000005],lst,cnt,mod=1e9+7;
string s,t;
int gtpre(int x,int i)
{
	while (t[i-len[x]-1]!=t[i])
	{
		x=fa[x];
	}
	return x;
}
void ins(int i)
{
	lst=gtpre(lst,i);
	if (!ch[lst][t[i]-'a'])
	{
		fa[++cnt]=ch[gtpre(fa[lst],i)][t[i]-'a'];
		ch[lst][t[i]-'a']=cnt;
		len[cnt]=len[lst]+2;
		df[cnt]=len[cnt]-len[fa[cnt]];
		if (df[cnt]==df[fa[cnt]]) tp[cnt]=tp[fa[cnt]]; else tp[cnt]=cnt; 
	}
	lst=ch[lst][t[i]-'a'];
	int x=lst;
	while (x)
	{
		sum[x]=dp[i-len[tp[x]]]; 
		if (tp[x]!=x) (sum[x]+=sum[fa[x]])%=mod;
		if (!(i&1)) (dp[i]+=sum[x])%=mod;
		x=fa[tp[x]];
	}
}
int main()
{
	cnt=1;fa[0]=1;len[1]=-1;lst=0;
	rdst(s,1000005);t=s;
	fz0k(i,s.length()) if (!(i&1)) t[i]=s[i/2]; else t[i]=s[s.length()-i/2-1];
	t=" "+t;s=t;dp[0]=1;
//	cerr<<t<<endl;
	fz1(i,s.length()-1) ins(i);
	cout<<dp[s.length()-1]<<endl;
	return 0;
}